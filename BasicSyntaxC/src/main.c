#include <stdio.h>
#include "05_pointer/null_pointer.h"

int main(void) {

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

    return 0;
}