#include <stdio.h>
#include "var.h"

int main(void) {

    total += 10;

    printf("total: %d\n", total);

    total = add(total, 5);

    total = subtract(total, 3);

    printf("total after addition: %d\n", total);
    return 0;
}