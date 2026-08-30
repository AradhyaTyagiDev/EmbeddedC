#include <stdio.h>
#include "var.h"

int main(void) {

    total += 10;

    printf("total: %d\n", total);

    total = add(total, 5);

    total = subtract(total, 3);

    printf("total after addition: %d\n", total);

    counter = 15;
    printf("counter in main: %d\n", counter);

    int16_t result =  subtract(10, 5);
    printf("result: %d\n", result);

    return 0;
}