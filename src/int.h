#ifndef _T6_INT
#define _T6_INT

#include "state.h"
#include "stack.h"
#include "addr.h"
#include <stdint.h>

#define T6_VECTOR_NMI 0xFFFA
#define T6_VECTOR_RESET 0xFFFC
#define T6_VECTOR_IRQ 0xFFFE

void t6_int_nmi(t6_state_t *state, uint8_t *memory);
void t6_int_reset(t6_state_t *state, uint8_t *memory);
void t6_int_irq(t6_state_t *state, uint8_t *memory);

#endif
