#ifndef _T6_STATE
#define _T6_STATE
#include <stdint.h>

#define T6_FLAG_C (1<<0)
#define T6_FLAG_Z (1<<1)
#define T6_FLAG_I (1<<2)
#define T6_FLAG_D (1<<3)
//                (1<<4)
#define T6_FLAG_B (1<<5)
#define T6_FLAG_O (1<<6)
#define T6_FLAG_N (1<<7)

typedef struct {
    uint8_t flags;
    uint8_t sp;
    uint8_t a;
    uint8_t x;
    uint8_t y;
    uint16_t pc;
} t6_state_t;

#endif
