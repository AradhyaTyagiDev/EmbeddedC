#include <stdio.h>
#include <stdint.h>
#include "05_pointer/pointer.h"

void printBinary(int n) {
    // Assumes a 32-bit integer; skips leading zeros for scannability
    int started = 0;
    
    for (int i = 31; i >= 0; i--) {
        int bit = (n >> i) & 1;
        
        printf("%d", bit);

        // if (started || i == 0) {
        //     printf("%d", bit);
        //     started = 1; // Marks that we started printing digits
        // }
    }
    printf("\n");
}


int main(void) {

    u_int32_t value = 0x00000000ULL;
    u_int32_t bitValue = (1U << 5);

    printf("bitValue: %d\n", bitValue);
    printf("BitValue in HEX: 0x%032X\n", bitValue);
    printf("Binary: ");
    printBinary(bitValue);

    int value = 10;
    int *ptr1 = &value;
    int *ptr2 ;
    ptr2 = ptr1 - 1;
    // *ptr2 = 20;

    printf("ptr1: %p\n", ptr1);
    printf("ptr2: %p\n", ptr2);
    printf("ptr1 points to value: %d\n", *ptr1);
    printf("ptr2 points to value: %d\n", *ptr2);

    pointerWithArray();

    arrayAndPointer();

    getVarAddress();

    return 0;
}