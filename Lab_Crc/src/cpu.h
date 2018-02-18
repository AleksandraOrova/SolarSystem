// ****************************************************************************
// CPU features detector
// ****************************************************************************

#ifndef _CPU_H_ 
#define _CPU_H_ 

class CpuDetect
{
public:
  bool      m_mmx;
  bool      m_sse;
  bool      m_sse2;
  bool      m_sse3;
  bool      m_ssse3;
  bool      m_sse41;
  bool      m_sse42;
  bool      m_aes;
  bool      m_avx;
  bool      m_fma3;
  bool      m_rdrand;

  bool      m_avx2;
  bool      m_bmi1;
  bool      m_bmi2;
  bool      m_adx;
  bool      m_sha;
  bool      m_prefetchwt1;
  bool      m_avx512f;
  bool      m_avx512cd;
  bool      m_avx512pf;
  bool      m_avx512er;
  bool      m_avx512vl;
  bool      m_avx512bw;
  bool      m_avx512dq;
  bool      m_avx512ifma;
  bool      m_avx512vbmi;

  bool      m_x64;
  bool      m_abm;
  bool      m_sse4a;
  bool      m_fma4;
  bool      m_hop;

public:
  CpuDetect();
};

#endif
