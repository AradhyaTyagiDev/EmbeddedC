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

void pointerWithArray() {
    u_int8_t arr[5] = {1, 2, 3};
    u_int8_t arra[2] = {10, 20};
    u_int8_t *p = arr; // Pointer to the first element of the array
    printf("Address of first element: %p\n", (void*)p);
    printf("Address of second element: %p\n", (void *)(p + 1));
    printf("Address of 1 element: %p\n", arr);
    printf("Address of 2 element: %p\n", arr + 1);
    printf("Address of 3 element: %p\n", arr + 2);
     printf("Address of first element: %p\n", arra);
     printf("Address of 2nd element: %p\n", arra + 1);
    printf("Address of arrary: %ld\n", arr - arra);
    printf("Value at 0 %d\n", arr[0]);
    printf("Value at 0 %d\n", *p);
    printf("Value at 1 %d\n", *(p + 1));
}

void arrayAndPointer() {
    long arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    long *p = arr; // Pointer to the first element of the array
    printf("Address of first element: %ld\n", sizeof(arr));
    printf("Address of array: %p\n", &arr);
    printf("Value of p: %p\n", p);
    printf("Add: %p\n", &p);
    printf("Address of second element: %ld\n", sizeof(p));
}
