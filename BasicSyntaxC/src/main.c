#include <stdio.h>
#include "05_pointer/null_pointer.h"

int main(void) {

    int x = 10;
     int *ptr = &x;
     checkForNullPointer(ptr);

    printf("x address %p\n", &x);
    printf("pointer  %p\n", ptr);
    printf("pointer value %p\n", &ptr);

    return 0;
}