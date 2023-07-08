/*
파일명: ex04-02-scanf.c
scanf()
    데이터 입력에 사용되는 함수
*/

// Visual Studio 사용시
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char character;
    int inum;
    float fnum;

    scanf("%c", &character);
    scanf("%d", &inum);
    scanf("%f", &fnum);

    printf("%c, %d, %f \n", character, inum, fnum);

    return 0;
}

