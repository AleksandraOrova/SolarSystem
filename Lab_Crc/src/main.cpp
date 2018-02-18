// ******************************************************************
// This is CRC32 instruction (SSE4.2 intel instruction set) emulator
// ******************************************************************


// ******************************************************************
// Includes
// ******************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <intrin.h>
#include <assert.h>

#include "cpu.h"
#include "crc32.h"

// ******************************************************************
// Defines
// ******************************************************************

#define USE_PARAM(s)          (s)

#define NUM_TEST_BYTES        (1024 * 32)
#define NUM_ITERATIONS_TEST   (1024 * 2)

// ******************************************************************
// Methods
// ******************************************************************

static float _getStdDev(const int *histogram, const int numValues)
{
  float ave = 0.0f;
  int i;
  for (i = 0 ; i < numValues; i++)
  {
    ave += histogram[i];
  }
  ave /= (float)numValues;

  float dev = 0.0f;
  for (i = 0; i < numValues; i++)
  {
    dev += (histogram[i] - ave) * (histogram[i] - ave);
  }
  dev /= (float)numValues;
  dev = sqrtf(dev);
  return dev;
}

int main(int argc, char *argv[])
{
  // just for compiler happiness in maximum warning level
  USE_PARAM(argc);
  USE_PARAM(argv);

  CpuDetect cpuDetector;
  if (!cpuDetector.m_sse42)
  {
    printf("This application cant be executed on this processor due to SSE4.2 instruction set lack (need to have crc32 instruction support). Try on another, more powerfull PC\n");
    return -1;
  }

  // Create some test string
  unsigned char *strTest = new unsigned char[NUM_TEST_BYTES];
  if (strTest == NULL)
    return -1;

  // Fill test string with some crap
  int i;
  for (i = 0; i < NUM_TEST_BYTES; i++)
  {
    strTest[i] = (unsigned char)(rand() & 0xff);
  }

  int iter;
  static int histogram[16];

  // Check function quality
  Crc32     crc32;
  MInt32    difMin, difMax;
  MUint32   crc32prev;

  memset(histogram, 0, sizeof(histogram) );
  difMin = 1 << 30;
  difMax = 0;
  crc32prev = 0xffffffff;
  for (iter = 0; iter < NUM_ITERATIONS_TEST; iter++)
  {
    strTest[iter] ++;
    MUint32 valCrc32 = crc32.getCrc32(0, strTest, NUM_TEST_BYTES);
    strTest[iter] --;

    histogram[ (valCrc32 >> 28) & 15 ] ++;

    if (crc32prev != 0xffffffff)
    {
      MInt32    dif;
      dif = (MInt32)valCrc32 - (MInt32)crc32prev;
      dif = (dif >= 0)? dif: (-dif);
      difMin = (dif < difMin)? dif: difMin;
      difMax = (dif > difMax)? dif: difMax;

    }
    crc32prev     = valCrc32;
  }
  MInt32 crc32Min = difMin;
  MInt32 crc32Max = difMax;

  printf("Histogram for crc32cpp:\n");
  for (i = 0; i < 16;i++)
    printf("%d ", histogram[i]);
  printf("\n");
  printf("Std.deviation = %f:\n", _getStdDev(histogram, 16) );


  memset(histogram, 0, sizeof(histogram));
  difMin = 1 << 30;
  difMax = 0;
  crc32prev = 0xffffffff;
  for (iter = 0; iter < NUM_ITERATIONS_TEST; iter++)
  {
    strTest[iter] ++;
    MUint32 valCrc32 = crc32.getAdler32(0, strTest, NUM_TEST_BYTES);
    strTest[iter] --;

    histogram[(valCrc32 >> 28) & 15] ++;

    if (crc32prev != 0xffffffff)
    {
      MInt32    dif;
      dif = (MInt32)valCrc32 - (MInt32)crc32prev;
      dif = (dif >= 0) ? dif : (-dif);
      difMin = (dif < difMin) ? dif : difMin;
      difMax = (dif > difMax) ? dif : difMax;

    }
    crc32prev = valCrc32;
  }
  MInt32 adler32Min = difMin;
  MInt32 adler32Max = difMax;

  printf("Histogram for crc32adler:\n");
  for (i = 0; i < 16; i++)
    printf("%d ", histogram[i]);
  printf("\n");
  printf("Std.deviation = %f:\n", _getStdDev(histogram, 16));

  memset(histogram, 0, sizeof(histogram));
  difMin = 1 << 30;
  difMax = 0;
  crc32prev = 0xffffffff;
  for (iter = 0; iter < NUM_ITERATIONS_TEST; iter++)
  {
    strTest[iter] ++;
    MUint32 valCrc32 = crc32.getCrcAsm(0, strTest, NUM_TEST_BYTES);
    strTest[iter] --;

    histogram[(valCrc32 >> 28) & 15] ++;

    if (crc32prev != 0xffffffff)
    {
      MInt32    dif;
      dif = (MInt32)valCrc32 - (MInt32)crc32prev;
      dif = (dif >= 0) ? dif : (-dif);
      difMin = (dif < difMin) ? dif : difMin;
      difMax = (dif > difMax) ? dif : difMax;

    }
    crc32prev = valCrc32;
  }
  MInt32 asm32Min = difMin;
  MInt32 asm32Max = difMax;

  printf("Histogram for crc32asm:\n");
  for (i = 0; i < 16; i++)
    printf("%d ", histogram[i]);
  printf("\n");
  printf("Std.deviation = %f:\n", _getStdDev(histogram, 16));

  printf("CRC Quality checks:\n");
  printf("CRC32cpp:   MinDif = %8d MaxDif = %d\n", crc32Min, crc32Max);
  printf("CRC32adler: MinDif = %8d MaxDif = %d\n", adler32Min, adler32Max);
  printf("CRC32asm:   MinDif = %8d MaxDif = %d\n", asm32Min, asm32Max);

  // Check performance
  MUint64 ticksCrcCpp, ticksCrcAdler, ticksCrcAsm;
  MUint64 ticksS, ticksE;
  MUint32 valCrc, trickForCompiler = 0;

  ticksS = (MUint64)__rdtsc();
  for (iter = 0; iter < NUM_ITERATIONS_TEST; iter++)
  {
    valCrc = crc32.getCrc32(iter, strTest, NUM_TEST_BYTES);
    trickForCompiler ^= valCrc;
  }
  ticksE = (MUint64)__rdtsc();
  ticksCrcCpp = (ticksE - ticksS) / ((MUint64)NUM_ITERATIONS_TEST);


  ticksS = (MUint64)__rdtsc();
  for (iter = 0; iter < NUM_ITERATIONS_TEST; iter++)
  {
    valCrc = crc32.getAdler32(iter, strTest, NUM_TEST_BYTES);
    trickForCompiler ^= valCrc;
  }
  ticksE = (MUint64)__rdtsc();
  ticksCrcAdler = (ticksE - ticksS) / ((MUint64)NUM_ITERATIONS_TEST);

  ticksS = (MUint64)__rdtsc();
  for (iter = 0; iter < NUM_ITERATIONS_TEST; iter++)
  {
    valCrc = crc32.getCrcAsm(iter, strTest, NUM_TEST_BYTES);
    trickForCompiler ^= valCrc;
  }
  ticksE = (MUint64)__rdtsc();
  ticksCrcAsm = (ticksE - ticksS) / ((MUint64)NUM_ITERATIONS_TEST);

  // trick for compiler to force invoke methods
  if (trickForCompiler == 0)
    printf("\n");

  printf("CRC Performance test:\n");
  printf("CRC32cpp:   Ticks = %8d Percent = %f\n", (int)ticksCrcCpp,     (float)(100.0f * ticksCrcCpp   / ticksCrcCpp) );
  printf("CRC32adler: Ticks = %8d Percent = %f\n", (int)ticksCrcAdler,   (float)(100.0f * ticksCrcAdler / ticksCrcCpp) );
  printf("CRC32asm:   Ticks = %8d Percent = %f\n", (int)ticksCrcAsm,     (float)(100.0f * ticksCrcAsm   / ticksCrcCpp) );

  // free test buffer
  delete [] strTest;


  return 1;

}