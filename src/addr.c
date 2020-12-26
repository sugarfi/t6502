#include "addr.h"

uint8_t t6_addr_read_byte(uint16_t addr, uint8_t *buffer) {
    return buffer[addr];
}

uint16_t t6_addr_read_word(uint16_t addr, uint8_t *buffer) {
    return buffer[addr] | (buffer[addr + 1] << 8);
}

void t6_addr_write_byte(uint8_t data, uint16_t addr, uint8_t *buffer) {
    buffer[addr] = data;
}

void t6_addr_write_word(uint16_t data, uint16_t addr, uint8_t *buffer) {
    buffer[addr] = data & 0xff;
    buffer[addr + 1] = data >> 8;
}
