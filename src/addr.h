#ifndef _T6_ADDR
#define _T6_ADDR

#include <stdint.h>

uint8_t t6_addr_read_byte(uint16_t addr, uint8_t *buffer);
uint16_t t6_addr_read_word(uint16_t addr, uint8_t *buffer);
void t6_addr_write_byte(uint8_t data, uint16_t addr, uint8_t *buffer);
void t6_addr_write_word(uint16_t data, uint16_t addr, uint8_t *buffer);

#endif
