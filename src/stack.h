#ifndef _T6_STACK
#define _T6_STACK

#include "state.h"
#include "addr.h"
#include <stdint.h>

uint8_t t6_stack_pop(t6_state_t *state, uint8_t *memory);
void t6_stack_push(uint8_t data, t6_state_t *state, uint8_t *memory);

#endif
