#ifndef _T6_DECODE
#define _T6_DECODE

#ifdef DEBUG
#include <stdio.h>
#endif

#include <stdint.h>

typedef enum {
    T6_BRK,
    T6_BPL,
    T6_JSR,
    T6_BMI,
    T6_RTI,
    T6_BVC,
    T6_RTS,
    T6_BVS,
    T6_BCC,
    T6_LDY,
    T6_BCS,
    T6_CPY,
    T6_BNE,
    T6_CPX,
    T6_BEQ,
    T6_ORA,
    T6_AND,
    T6_EOR,
    T6_ADC,
    T6_STA,
    T6_LDA,
    T6_CMP,
    T6_SBC,
    T6_LDX,
    T6_BIT,
    T6_STY,
    T6_ASL,
    T6_ROL,
    T6_LSR,
    T6_ROR,
    T6_STX,
    T6_DEC,
    T6_INC,
    T6_PHP,
    T6_CLC,
    T6_PLP,
    T6_SEC,
    T6_PHA,
    T6_CLI,
    T6_PLA,
    T6_SEI,
    T6_DEY,
    T6_TYA,
    T6_TAY,
    T6_CLV,
    T6_INY,
    T6_CLD,
    T6_INX,
    T6_SED,
    T6_TXA,
    T6_TXS,
    T6_TAX,
    T6_TSX,
    T6_DEX,
    T6_NOP,
    T6_JMP
} t6_opcode_t;

#ifdef DEBUG

static const char *T6_OPCODE_NAMES[] = {
    "BRK",
    "BPL",
    "JSR",
    "BMI",
    "RTI",
    "BVC",
    "RTS",
    "BVS",
    "BCC",
    "LDY",
    "BCS",
    "CPY",
    "BNE",
    "CPX",
    "BEQ",
    "ORA",
    "AND",
    "EOR",
    "ADC",
    "STA",
    "LDA",
    "CMP",
    "SBC",
    "LDX",
    "BIT",
    "STY",
    "ASL",
    "ROL",
    "LSR",
    "ROR",
    "STX",
    "DEC",
    "INC",
    "PHP",
    "CLC",
    "PLP",
    "SEC",
    "PHA",
    "CLI",
    "PLA",
    "SEI",
    "DEY",
    "TYA",
    "TAY",
    "CLV",
    "INY",
    "CLD",
    "INX",
    "SED",
    "TXA",
    "TXS",
    "TAX",
    "TSX",
    "DEX",
    "NOP",
    "JMP"
};

#endif

typedef enum {
    T6_IMPL,
    T6_A,
    T6_IMM,
    T6_ZP,
    T6_AB,
    T6_REL,
    T6_IND,
    T6_ZP_X,
    T6_ZP_Y,
    T6_AB_X,
    T6_AB_Y,
    T6_IND_X,
    T6_IND_Y
} t6_addr_mode_t;

#ifdef DEBUG

static const char *T6_MODE_NAMES[] = {
    "IMPL",
    "A",
    "IMM",
    "ZP",
    "AB",
    "REL",
    "IND",
    "ZP_X",
    "ZP_Y",
    "AB_X",
    "AB_Y",
    "IND_X",
    "INT_Y"
};

#endif

typedef struct {
    t6_opcode_t opcode;
    t6_addr_mode_t addr_mode;
} t6_instr_t;

t6_instr_t t6_instr_decode(uint8_t byte);

#endif
