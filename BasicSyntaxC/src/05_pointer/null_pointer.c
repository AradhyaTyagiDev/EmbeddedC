#include <stdio.h>

int checkForNullPointer(int *ptr) {
    u_int8_t x = 10;
    u_int8_t *p = &x;
    printf("Checking for null pointer... %p\n", (void*)p);

    u_int8_t y = 20;
    u_int8_t *p2 = &y;
    printf("Checking for null pointer... %p\n", (void*)p2);

    u_int8_t arr[2] = {10, 20};
    printf("Element 0: %p\n", (void*)&arr[0]);
    printf("Element 1: %p\n", (void*)&arr[1]);
    return 0;
}