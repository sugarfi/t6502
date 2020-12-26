#ifndef _T6_EVAL
#define _T6_EVAL

#include <stdint.h>
#include "state.h"
#include "decode.h"
#include "addr.h"
#ifdef DEBUG
#include <stdio.h>
#endif

void t6_eval_step(t6_state_t *state, uint8_t *memory);

#endif
