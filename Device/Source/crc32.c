/* CRC32 - No lookup table used
   Resource Requirements:
	 RAM:   32 Bytes (Stack)
	 ROM:   42 Bytes
	 Execution Performance Cortex-M3@100Mhz Checksum for 256KByte ROM area:
	 240 ms 
	 
	 Suitable for systems that are restricted in memory (RAM and ROM).
	 Saves code space and RAM resources. Execution is slower than on table based variants.
*/


#include <inttypes.h>
#include "CRC32.h"

uint32_t crc32 (uint32_t crc, const uint8_t *buf, uint32_t len) 
{
  uint8_t* current = (unsigned char*) buf;
	crc = ~crc; 
  while (len--)
  {
		uint32_t j;
    crc ^= *current++;
    for (j = 0; j < 8; j++)
      if (crc & 1)
        crc = (crc >> 1) ^ CRC32_POLYNOMIAL;
      else
        crc =  crc >> 1;
  }
  return ~crc; 
}
