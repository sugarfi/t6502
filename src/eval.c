#include "eval.h"

void t6_eval_step(t6_state_t *state, uint8_t *memory) {
    uint8_t byte = t6_addr_read_byte(state->pc, memory);
    t6_instr_t inst = t6_instr_decode(byte);

    uint8_t size = 1;

    int16_t op;
    uint8_t res;
    switch (inst.addr_mode) {
    case T6_IMPL: {
                      break;
                  }
    case T6_A: {
                   res = op = state->a;
                   break;
               }
    case T6_IMM: {
                     res = op = t6_addr_read_byte(state->pc + 1, memory);
                     ++size;
                     break;
                 }
    case T6_ZP: {
                    op = t6_addr_read_byte(state->pc + 1, memory);
                    res = t6_addr_read_byte(op);
                    ++size;
                    break;
                }
    case T6_AB: {
                    op = t6_addr_read_word(state->pc + 1, memory);
                    res = t6_addr_read_byte(op);
                    size += 2;
                    break;
                }
    case T6_REL: {
                     uint8_t byte = t6_addr_read_byte(state->pc + 1, memory);
                     ++size;
                     uint8_t sign = byte >> 7;
                     byte <<= 1;
                     byte >>= 1;
                     op = size ? -byte : byte;
                     break;
                 }
    case T6_IND: {
                     uint16_t addr = t6_addr_read_word(state->pc + 1, memory);
                     size += 2;
                     op = t6_addr_read_word(addr, memory);
                     res = t6_addr_read_byte(op);
                     break;
                 }
    case T6_ZP_X: {
                      op = (t6_addr_read_byte(state->pc + 1, memory) + state->x) % 256;
                      res = t6_addr_read_byte(op);
                      ++size;
                      break;
                  }
    case T6_ZP_Y: {
                      op = (t6_addr_read_byte(state->pc + 1, memory) + state->x) % 256;
                      res = t6_addr_read_byte(op);
                      ++size;
                      break;
                  }
    case T6_AB_X: {
                      op = t6_addr_read_word(state->pc + 1, memory) + state->x;
                      res = t6_addr_read_byte(op);
                      size += 2;
                      break;
                  }
    case T6_AB_Y: {
                      op = t6_addr_read_word(state->pc + 1, memory) + state->y;
                      res = t6_addr_read_byte(op);
                      size += 2;
                      break;
                  }
    case T6_IND_X: {
                       uint16_t arg = t6_addr_read_word(state->pc + 1, memory);
                       op = t6_addr_read_word(arg + state->x, memory);
                       res = t6_addr_read_byte(op);
                       size += 2;
                       break;
                   }
    case T6_IND_Y: {
                       uint16_t arg = t6_addr_read_word(state->pc + 1, memory);
                       op = arg + state->y;
                       res = t6_addr_read_byte(op);
                       size += 2;
                       break;
                   }
    }

    #ifdef DEBUG
    printf(" A: %x  X: %x  Y: %x\nPC: %x SP: %x\n", state->a, state->x, state->y, state->pc, state->sp);
    printf("%s %s %x\n", T6_OPCODE_NAMES[inst.opcode], T6_MODE_NAMES[inst.addr_mode], op);
    #endif

    switch (inst.opcode) {
    case T6_ADC: {
                     uint8_t old = state->a;
                     if (state->flags & T6_FLAG_D) {
                         // TODO: figure out what the fuck is up with BCD
                     } else {
                         state-> a += res + ((state->flags & T6_FLAG_C) ?  1 : 0);
                         if ((((uint16_t) state->a) + res) > 255) {
                             state->flags |= T6_FLAG_C;
                         } else {
                             state->flags &= ~T6_FLAG_C;
                         }
                     }
                     if (state->a == 0) {
                         state->flags |= T6_FLAG_Z;
                     } else {
                         state->flags &= ~T6_FLAG_Z;
                     }

                     if ((old & 128) != (state->a & 128)) {
                        state->flags |= T6_FLAG_V;
                     } else {
                         state->flags &= ~T6_FLAG_V;
                     }

                     if (state->a > 127) {
                         state->flags |= T6_FLAG_N;
                     } else {
                         state->flags &= ~T6_FLAG_N;
                     }
                 }
    case T6_AND: {
                     state->a &= res;

                     if (state->a == 0) {
                         state->flags |= T6_FLAG_Z;
                     } else {
                         state->flags &= ~T6_FLAGS_Z;
                     }

                     if (state->a > 127) {
                         state->flags |= T6_FLAG_N;
                     } else {
                         state->flags &= ~T6_FLAG_N;
                     }
                 }
    }

    state->pc += size;
    #ifdef DEBUG
    getchar();
    #endif  
}
