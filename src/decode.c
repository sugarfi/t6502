#include "decode.h"

t6_instr_t t6_instr_decode(uint8_t byte) {
    t6_instr_t out = {
        .opcode = T6_NOP,
        .addr_mode = T6_IMPL
    };

    switch (byte) {
    case 0x00: {
                   out.opcode = T6_BRK;
                   return out;
               }
    case 0x20: {
                   out.opcode = T6_JSR;
                   out.addr_mode = T6_AB;
                   return out;
               }
    case 0x40: {
                   out.opcode = T6_RTI;
                   return out;
               }
    case 0x60: {
                   out.opcode = T6_RTS;
                   return out;
               }
    case 0x08:
               {
                   out.opcode = T6_PHP;
                   return out;
               }
    case 0x28: {
                   out.opcode = T6_PLP;
                   return out;
               }
    case 0x48: {
                   out.opcode = T6_PHA;
                   return out;
               }
    case 0x68: {
                   out.opcode = T6_PLA;
                   return out;
               }
    case 0x88: {
                   out.opcode = T6_DEY;
                   return out;
               }
    case 0xA8: {
                   out.opcode = T6_TAY;
                   return out;
               }
    case 0xC8: {
                   out.opcode = T6_INY;
                   return out;
               }
    case 0xE8: {
                   out.opcode = T6_INX;
                   return out;
               }
    case 0x18: {
                   out.opcode = T6_CLC;
                   return out;
               }
    case 0x38: {
                   out.opcode = T6_SEC;
                   return out;
               }
    case 0x58: {
                   out.opcode = T6_CLI;
                   return out;
               }
    case 0x78: {
                   out.opcode = T6_SEI;
                   return out;
               }
    case 0x98: {
                   out.opcode = T6_TYA;
                   return out;
               }
    case 0xB8: {
                   out.opcode = T6_CLV;
                   return out;
               }
    case 0xD8: {
                   out.opcode = T6_CLD;
                   return out;
               }
    case 0xF8: {
                   out.opcode = T6_SED;
                   return out;
               }
    case 0x8A: {
                   out.opcode = T6_TXA;
                   return out;
               }
    case 0x9A: {
                   out.opcode = T6_TXS;
                   return out;
               }
    case 0xAA: {
                   out.opcode = T6_TAX;
                   return out;
               }
    case 0xBA: {
                   out.opcode = T6_TSX;
                   return out;
               }
    case 0xCA: {
                   out.opcode = T6_DEX;
                   return out;
               }
    case 0xEA: {
                   return out;
               }
    default: {
                 break;
             }
    }

    uint8_t aaa = (byte & 0b11100000) >> 5;
    uint8_t bbb = (byte & 0b00011100) >> 2;
    uint8_t cc  = (byte & 0b00000011);

    switch (cc) {
    case 0b01: {
                   out.opcode = (t6_opcode_t[]){
                       T6_ORA,
                       T6_AND,
                       T6_EOR,
                       T6_ADC,
                       T6_STA,
                       T6_LDA,
                       T6_CMP,
                       T6_SBC
                   }[aaa];

                   out.addr_mode = (t6_addr_mode_t[]){
                       T6_IND_X,
                       T6_ZP,
                       T6_IMM,
                       T6_AB,
                       T6_IND_Y,
                       T6_ZP_X,
                       T6_AB_Y,
                       T6_AB_X
                   }[bbb];
                   break;
               }
    case 0b10: {
                   out.opcode = (t6_opcode_t[]){
                       T6_ASL,
                       T6_ROL,
                       T6_LSR,
                       T6_ROR,
                       T6_STX,
                       T6_LDX,
                       T6_DEC,
                       T6_INC
                   }[aaa];

                   out.addr_mode = (t6_addr_mode_t[]){
                       T6_IMM,
                       T6_ZP,
                       T6_A,
                       T6_AB,
                       T6_ZP_X,
                       T6_AB_X
                   }[bbb];
                   break;
               }
    case 0b00: {
                   if (byte & 0b00010000 == 0b00010000) {
                        uint8_t xxy = byte & 0b11100000 >> 5;
                        
                        out.opcode = (t6_opcode_t[]){
                            T6_BPL,
                            T6_BMI,
                            T6_BVC,
                            T6_BVS,
                            T6_BCC,
                            T6_BCS,
                            T6_BNE,
                            T6_BEQ
                        }[xxy];
                   } else {
                        out.opcode = (t6_opcode_t[]){
                            T6_BIT,
                            T6_JMP,
                            T6_JMP,
                            T6_STY,
                            T6_LDY,
                            T6_CPY,
                            T6_CPX
                        }[aaa];

                        out.addr_mode = (t6_addr_mode_t[]){
                            T6_IMM,
                            T6_ZP,
                            T6_AB,
                            T6_ZP_X,
                            T6_AB_X
                        }[bbb];
                   }
                   break;
               }
    default: {
                 break;
             }
    }

    return out;
}
