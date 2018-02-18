// ****************************************************************************
// Includes
// ****************************************************************************

#include <nmmintrin.h>

#include "crc32.h"

// ****************************************************************************
// Defines
// ****************************************************************************

#define INITIAL_REMAINDER	      0xFFFFFFFF
#define FINAL_XOR_VALUE		      0xFFFFFFFF
#define CHECK_VALUE			        0xCBF43926
#define WIDTH                   (8 * sizeof(unsigned int))
#define TOPBIT                  (1 << (WIDTH - 1))
#define POLYNOMIAL			        0x04C11DB7

#define REFLECT_DATA(X)			    ((unsigned char)  _reflectBits((X), 8))
#define REFLECT_REMAINDER(X)	  ((unsigned int)   _reflectBits((X), WIDTH))


// ****************************************************************************
// Classes
// ****************************************************************************

Crc32::Crc32()
{
  init();
}

void  Crc32::init()
{
  unsigned int    remainder;
  int			        dividend;
  unsigned char   bit;

  for (dividend = 0; dividend < 256; ++dividend)
  {
    remainder = dividend << (WIDTH - 8);
    for (bit = 8; bit > 0; --bit)
    {
      if (remainder & TOPBIT)
      {
        remainder = (remainder << 1) ^ POLYNOMIAL;
      }
      else
      {
        remainder = (remainder << 1);
      }
    }
    m_crcTable[dividend] = remainder;
  }
}

static unsigned long  _reflectBits(unsigned long data, unsigned char nBits)
{
  unsigned long  reflection = 0x00000000;
  unsigned char  bit;

  for (bit = 0; bit < nBits; ++bit)
  {
    if (data & 0x01)
    {
      reflection |= (1 << ((nBits - 1) - bit));
    }
    data = (data >> 1);
  }
  return (reflection);
}


MUint32 Crc32::getCrc32(
                          MUint32       crcPrev,
                          const MUint8  *message,
                          const int     numBytes
                       )
{
  MUint32 remainder = crcPrev & INITIAL_REMAINDER;
  MUint8  data;
  int     byte;
  for (byte = 0; byte < numBytes; ++byte)
  {
    data = REFLECT_DATA(message[byte]) ^ (remainder >> (WIDTH - 8));
    remainder = m_crcTable[data] ^ (remainder << 8);
  }
  return (REFLECT_REMAINDER(remainder) ^ FINAL_XOR_VALUE);
}


MUint32 Crc32::getAdler32(
                            MUint32         crcPrev,
                            const MUint8    *message,
                            const int       numBytes
                         )
{
  MUint64  sumA, sumB;
  sumA = 1L + (MUint64)crcPrev;
  sumB = 0L;

  for (int i = 0; i < numBytes; i++)
  {
    MUint64 a = (MUint64)message[i];
    sumA += a;
    sumB += sumA;
  }
  sumA = sumA % 65521;
  sumB = sumB % 65521;
  MUint64 result = sumA + sumB * 65536;
  return (MUint32)result;
}

//
// This is WRONG !!! implementation.
// You need to write correct one.
//
MUint32 Crc32::getCrcAsm(
                          MUint32         crcPrev,
                          const MUint8    *message,
                          const int       numBytes
                        )
{
	MUint32 crc = crcPrev;
	for (int i =  0; i<numBytes; i+=4){
		crc = _mm_crc32_u32(crc, *(MUint32*)(message + i));
	}
    return crc;
}





