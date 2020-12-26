#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "addr.h"
#include "state.h"
#include "eval.h"
#include "int.h"

#define T6_CODE_ADDR 0x0000 // Fix this later

int main(int argc, char *argv[]) {
    if (argc < 2) {
        puts("Please provide a file!");
        return -1;
    }

    // Read the file into a buffer
    FILE *file = fopen(argv[1], "r");
    fseek(file, 0, SEEK_END);
    unsigned int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buffer = (char *) malloc(size);
    fread(buffer, size, 1, file);
    fclose(file);

    uint8_t *memory = (uint8_t *) malloc(65536);

    unsigned int i;
    for (i = 0; i < size; i++) {
        t6_addr_write_byte(buffer[i], T6_CODE_ADDR + i, memory);
        #ifdef DEBUG
        printf("Writing %x to %x\n", buffer[i] & 0xff, T6_CODE_ADDR + i);
        #endif
    }
    t6_addr_write_word(T6_CODE_ADDR, T6_VECTOR_RESET, memory);

    t6_state_t state;
    
    t6_int_reset(&state, memory);
    for (;;) {
        t6_eval_step(&state, memory);
    }

    free(memory);
    free(buffer);
    return 0;
}
