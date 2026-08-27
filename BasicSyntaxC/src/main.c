#include <stdio.h>

int add(int a, int b)
{
    int result = a + b;

    return result;
}

int main(void)
{
    int x = 10;
    int y = 20;

    int sum = add(x, y);

    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("sum = %d\n", sum);
    printf("Hello, World!\n");

    return 0;

    
}