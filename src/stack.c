#include "stack.h"

uint8_t t6_stack_pop(t6_state_t *state, uint8_t *memory) {
    uint8_t value = t6_addr_read_byte(0x100 + state->sp++, memory);
    return value;
}

void t6_stack_push(uint8_t data, t6_state_t *state, uint8_t *memory) {
    t6_addr_write_byte(0x100 + state->sp--, data, memory);
}
