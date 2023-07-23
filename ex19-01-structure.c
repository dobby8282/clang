/*
파일명: ex19-01-structure.c

구조체(Structure)
    하나 이상의 변수를 한꺼번에 묶어서 만드는 새로운 유형의 자료형
    사용자 정의 자료형이라고 부르기도 한다.
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
    struct person boy, girl;

    // name 멤버 변수에 대한 접근
    strcpy(boy.name, "김소년");
    strcpy(girl.name, "이소녀");

    // age 멤버 변수에 대한 접근
    boy.age = 12;
    girl.age = 9;
    printf("소년의 이름은 %s 나이는 %d세\n", boy.name, boy.age);
    printf("소녀의 이름은 %s 나이는 %d세\n", girl.name, girl.age);

    return 0;
}