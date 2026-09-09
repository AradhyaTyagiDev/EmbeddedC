#include <stdio.h>

struct Weather {
    int temp;
    int humi;
};

typedef struct {
    int rollNo;
    char *name;
} user_t;

int main()
{
    struct Weather today = {
        .temp = 47,
        .humi = 86
    };

    printf("today temp: %d, humi: %d\n", today.temp, today.humi);

    user_t user = {
        .name = "Kuldeep",
        .rollNo = 1
    };

    user_t *userPtr = &user;

    printf("user: Name: %s, RollNo: %d\n", user.name, user.rollNo);
    printf("User with Pointer: Name: %s, RollNO. %d\n", userPtr->name, userPtr->rollNo);

    return 0;
}