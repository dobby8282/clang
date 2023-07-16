/*
파일명: ex15-07-static.c

static 변수(정적변수)
    함수내부(지역), 함수외부(전역)에서도 사용가능
    프로그램이 시작될 때 할당되고 프로그램이 끝날때 소멸된다.

*/
#include <stdio.h>

int gNumber = 10;

void increaseNumber()
{
    static int number = 0; // static 진역변수 number 선언

    number++;
    printf("number: %d\n", number);

}

int main(void)
{
    increaseNumber();
    increaseNumber();
    increaseNumber();
    increaseNumber();
    increaseNumber();

    return 0;
}