#include <stdio.h>
#include "var.h"

void processData(const int *p, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("Element %zu: %d\n", i, p[i]);
    }

    int *q = (int *)p; // Casting away constness (not recommended)
    q[0] = 100; // Modifying the first element (undefined behavior)

    printf("after modification, first element: %d\n", p[0]);
    printf("after modification, second element: %d\n", q[0]);
}

int main(void) {

    static uint8_t table[];

    const int count = 5;
    int *ptr = (int *)&count;

    printf("table address: %p\n", table);

    printf("value of count: %d\n", *ptr);
    printf("address of count: %p\n", (void *)ptr);
    printf("address of count: %p\n", (void *)&count);

    *ptr = 10; // Modifying the value of count (undefined behavior)
    printf("After Modification, value of count: %d\n", *ptr);
    printf("After Modification, address of count: %p\n", (void *)ptr);
    printf("After Modification, address of count: %p\n", (void *)&count);

    int p[] = { 1, 2, 3, 4, 5 };

    size_t size = sizeof(p) / sizeof(p[0]);

    processData(p, size);

    return 0;
}

