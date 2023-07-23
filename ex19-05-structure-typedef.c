/*
파일명: ex19-05-structure-typedef.c

구조체와 typedef
    구조체 이름도 typedef 선언 대상이 될 수 있다.
*/
#include <stdio.h>

// 구조체 선언과 동시에 typedef 선언
typedef struct 
{
    int x;
    int y;
}POINT;

struct person
{
    char name[30];
    int age;
};

// 정의된 구조체에 대한 typedef선언
typedef struct person PERSON;

int main(void) 
{
    POINT position = {30, 60};
    PERSON saram = {"김사람", 10};

    printf("%d %d\n", position.x, position.y);
    printf("%s %d\n", saram.name, saram.age);

    return 0;
}
