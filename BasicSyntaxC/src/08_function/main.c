#include <stdio.h>

void func() {
    printf("hello world\n");
}

int funcA(int p1, int p2) {
    printf("My name is kuldeep\n");
    return 30;
}

typedef void (*call_back)(int, int);

int func3(void (*fun1)(void)) {

    funcA(10, 20);

    return 1;
}

int main() {

    void (*funcP)(void);

    funcP = func;

    funcP();

    int (*f2Ptr)(int, int);

    f2Ptr = funcA;

    int returnVal = f2Ptr(10, 20);

    func3(funcP);

    return 0;
}