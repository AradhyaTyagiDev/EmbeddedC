#include <stdio.h>
#include <stdint.h>

void printBinary(uint32_t n) {

    for(int i = 31; i >= 0; i--) {
        int bit = (n >> i) & 1;
        printf("%d", bit);
    }
}
    

int main() {

    uint32_t bitValue = 0x00000000ULL;
    bitValue |=  (1U << 5);

    

    printf("bitValue Int: %d\n", bitValue);
    printf("BitValue in HEX: 0x%08X\n", bitValue);
    printf("Binary: ");
    printBinary(bitValue);
    printf("\n");

    bitValue &= ~(1U << 5);

    printf("BitValue in HEX: 0x%08X\n", bitValue);
    printf("Binary: ");
    printBinary(bitValue);
    printf("\n");

    bitValue ^= (1ULL << 5);

    printf("BitValue in HEX: 0x%08X\n", bitValue);
    printf("Binary: ");
    printBinary(bitValue);
    printf("\n");

    if (bitValue & (1U << 5)) {
        printf("Bit 5 is set.\n");
    } else {
        printf("Bit 5 is not set.\n");
    }

    return 0;
}