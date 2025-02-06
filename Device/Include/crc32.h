#include <inttypes.h>

/**
 * @fn          uint32_t crc32 (uint32_t crc, const uint8_t *buf, uint32_t len) 
 * @brief       Bitwise CRC32 calculation (slow, no LUT used).
 * @param       crc      Previous CRC
 * @param       buf      Pointer to buffer for data
 * @param       len      Length of data
 * @return      Calculated CRC
*/
extern uint32_t crc32(uint32_t crc, const uint8_t *buf, uint32_t len);

#define CRC32_POLYNOMIAL 0xedb88320ull
