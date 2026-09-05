#include <stdio.h>

#define GPIO_BASE_ADD (volatile unit32_t *) ox16aeee26U
#define GPIO_VAL (*(volatile uinit32_t *) GPIO_BASE_ADD)

void getVarAddress() {
    int x = 10;
    int *ptr = &x;

    

    printf("Address of x: %p\n", (void*)&x);
    printf("Address stored in ptr: %p\n", (void*)ptr);
}
