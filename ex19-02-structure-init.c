/*
파일명: ex19-02-structure-init.c

구조체 초기화
*/
#include <stdio.h>
#include <string.h>

struct person 
{
    char name[30];
    int age;
};

int main(void)
{
    // 구조체 선언과 동시에 초기화!
    struct person boy = {"김소년", 12};
    struct person girt = {"이소녀", 9};

    printf("소년의 이름은 %s, 나이는 %d세\n", boy.name, boy.age);
    printf("소녀의 이름은 %s, 나이는 %d세\n", girt.name, girt.age);

    return 0;
}