// ****************************************************************************
// CPU features detector
// ****************************************************************************

// ****************************************************************************
// Includes
// ****************************************************************************

#include "cpu.h" 

#include <immintrin.h>
#include <stdint.h>
#include <intrin.h>

// ****************************************************************************
// Class implementation
// ****************************************************************************


CpuDetect::CpuDetect()
  : m_mmx(false),
  m_sse(false),
  m_sse2(false),
  m_sse3(false),
  m_ssse3(false),
  m_sse41(false),
  m_sse42(false),
  m_aes(false),
  m_avx(false),
  m_fma3(false),
  m_rdrand(false),
  m_avx2(false),
  m_bmi1(false),
  m_bmi2(false),
  m_adx(false),
  m_sha(false),
  m_prefetchwt1(false),
  m_avx512f(false),
  m_avx512cd(false),
  m_avx512pf(false),
  m_avx512er(false),
  m_avx512vl(false),
  m_avx512bw(false),
  m_avx512dq(false),
  m_avx512ifma(false),
  m_avx512vbmi(false),
  m_x64(false),
  m_abm(false),
  m_sse4a(false),
  m_fma4(false),
  m_hop(false)

{
  int cpuInfo[4];
  __cpuidex(cpuInfo, 0, 0);
  int nIds = cpuInfo[0];

  __cpuidex(cpuInfo, 0x80000000, 0);
  unsigned nExIds = cpuInfo[0];
  if (nIds >= 0x00000001)
  {
    __cpuidex(cpuInfo, 1, 0);

    m_mmx = (cpuInfo[3] & ((int)1 << 23)) != 0;
    m_sse = (cpuInfo[3] & ((int)1 << 25)) != 0;
    m_sse2 = (cpuInfo[3] & ((int)1 << 26)) != 0;
    m_sse3 = (cpuInfo[2] & ((int)1 << 0)) != 0;

    m_ssse3 = (cpuInfo[2] & ((int)1 << 9)) != 0;
    m_sse41 = (cpuInfo[2] & ((int)1 << 19)) != 0;
    m_sse42 = (cpuInfo[2] & ((int)1 << 20)) != 0;
    m_aes = (cpuInfo[2] & ((int)1 << 25)) != 0;

    m_avx = (cpuInfo[2] & ((int)1 << 28)) != 0;
    m_fma3 = (cpuInfo[2] & ((int)1 << 12)) != 0;
    m_rdrand = (cpuInfo[2] & ((int)1 << 30)) != 0;
  }
  if (nIds >= 0x00000007)
  {
    __cpuidex(cpuInfo, 0x00000007, 0);
    m_avx2 = (cpuInfo[1] & ((int)1 << 5)) != 0;

    m_bmi1 = (cpuInfo[1] & ((int)1 << 3)) != 0;
    m_bmi2 = (cpuInfo[1] & ((int)1 << 8)) != 0;
    m_adx = (cpuInfo[1] & ((int)1 << 19)) != 0;
    m_sha = (cpuInfo[1] & ((int)1 << 29)) != 0;
    m_prefetchwt1 = (cpuInfo[2] & ((int)1 << 0)) != 0;

    m_avx512f = (cpuInfo[1] & ((int)1 << 16)) != 0;
    m_avx512cd = (cpuInfo[1] & ((int)1 << 28)) != 0;
    m_avx512pf = (cpuInfo[1] & ((int)1 << 26)) != 0;
    m_avx512er = (cpuInfo[1] & ((int)1 << 27)) != 0;
    m_avx512vl = (cpuInfo[1] & ((int)1 << 31)) != 0;
    m_avx512bw = (cpuInfo[1] & ((int)1 << 30)) != 0;
    m_avx512dq = (cpuInfo[1] & ((int)1 << 17)) != 0;
    m_avx512ifma = (cpuInfo[1] & ((int)1 << 21)) != 0;
    m_avx512vbmi = (cpuInfo[2] & ((int)1 << 1)) != 0;
  }
  if (nExIds >= 0x80000001)
  {
    __cpuidex(cpuInfo, 0x80000001, 0);
    m_x64 = (cpuInfo[3] & ((int)1 << 29)) != 0;
    m_abm = (cpuInfo[2] & ((int)1 << 5)) != 0;
    m_sse4a = (cpuInfo[2] & ((int)1 << 6)) != 0;
    m_fma4 = (cpuInfo[2] & ((int)1 << 16)) != 0;
    m_hop = (cpuInfo[2] & ((int)1 << 11)) != 0;
  }


}
