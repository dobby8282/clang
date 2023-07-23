/*
파일명: ex20-01-structure-pointer.c

구조체 포인터변수
    구조체를 포인터변수로 선언

화살표연산자 (->)
    포인터 사용하여 구조체 멤버에 접근
*/
#include <stdio.h>

typedef struct
{
    char name[30];
    int age;
}Person;

int main(void)
{
    Person boy = {"손흥민", 32};
    Person* ptr = &boy;

    printf("%s (%d)\n", (*ptr).name, (*ptr).age);
    printf("%s (%d)\n", ptr->name, ptr->age);

    return 0;
}