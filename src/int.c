#include "int.h"

void t6_int_nmi(t6_state_t *state, uint8_t *memory) {
    t6_stack_push(state->pc & 0xFF, state, memory);
    t6_stack_push(state->pc >> 8, state, memory);
    t6_stack_push(state->flags | (1<<4), state, memory);
    state->pc = t6_addr_read_word(T6_VECTOR_NMI, memory);
}

void t6_int_reset(t6_state_t *state, uint8_t *memory) {
    state->pc = t6_addr_read_word(T6_VECTOR_RESET, memory);
}

void t6_int_irq(t6_state_t *state, uint8_t *memory) {
    if (state->flags & T6_FLAG_I) return;
    state->flags |= T6_FLAG_I;
    t6_stack_push(state->pc & 0xFF, state, memory);
    t6_stack_push(state->pc >> 8, state, memory);
    t6_stack_push(state->flags | (1<<4), state, memory);
    state->pc = t6_addr_read_word(T6_VECTOR_IRQ, memory);
    state->flags &= ~T6_FLAG_I;
}
