#include <stdio.h>

/*
1. Creates a uint32_t variable initialized to 0.
2. Creates a volatile uint32_t * pointing to it.
3. Sets bits 0, 3, and 7.
4. Clears bit 3.
5. Toggles bit 5.
6. Reads bit 7.
7. Prints the final register value in hexadecimal.
*/
void MemoryMappedRegisters() {
    uint32_t value = 0;
    volatile uint32_t *baseReg = (volatile uint32_t *)&value;

    *baseReg |= (1U << 0);
    *baseReg |= (1U << 3);
    *baseReg |= (1U << 7);

    *baseReg &= ~(1U << 3);

    *baseReg ^= (1U << 5);

    if(*baseReg & (1U << 7)) {
        printf("7th bit is 1");
    }
    else {
         printf("7th bit is 0");
    }

    printf("Final Value: 0x%08lX", *baseReg);
}