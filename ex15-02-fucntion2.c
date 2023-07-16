/*
파일명: ex15-02-fucntion2.c
*/

#include <stdio.h>

// add 함수의 원형(선언부)
int add(int a, int b);

int main(void)
{
    int result;

    result = add(3, 9);
    printf("함수가 반환한 값: %d\n", result);

    return 0;
}

// add 함수의 기능(정의부)
int add(int a, int b)
{
    return a + b;
}


