// ****************************************************************************
// CRC32 calculation
// ****************************************************************************

#ifndef _CRC32_H_ 
#define _CRC32_H_ 

typedef unsigned char       MUint8;
typedef unsigned int        MUint32;
typedef int                 MInt32;
typedef unsigned long long  MUint64;
typedef          long long  MInt64;


class Crc32
{
public:
  Crc32();

  MUint32 getCrc32(
                      MUint32               crcPrev,
                      const MUint8          *message,
                      const int             numBytes
                  );

  MUint32 getAdler32(
                      MUint32               crcPrev,
                      const MUint8          *message,
                      const int             numBytes
                    );

  MUint32 getCrcAsm(
                      MUint32               crcPrev,
                      const MUint8          *message,
                      const int             numBytes
                   );

  

private:
  void          init();
private:
  unsigned int m_crcTable[256];
};

#endif

