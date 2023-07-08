/*
파일명: ex03-01-data.c

데이터 표현방식
    정수표현
        컴퓨터는 2진수로 표현(bit)
        부호비트(Most Significant Bit) + 수치비트

    실수표현(부동소수)
        지수부(e)비트 + 가수부(m)비트
    실수표현 수식
        ±(1.m)*2^(e-127)
    부동소수점오차
        정확한 실수표현 불가능 근사치값으로 인해 생긴 오차

    unsigned 자료형
        부호없는 데이터
        0이상 표현
        음수포기 대신 양수 표현 범위 그만큼 커진다.

*/

#include <stdio.h>

int main(void)
{
    // float:  10.00000190734863281250
    // double: 9.99999999999998046007
    double err_num = 0;

    // 반복문
    // Ctrl + / : 주석 단축키
    // for (int i = 0; i < 100; i++) // i++ -> i=i+1
    // {
    //     err_num += 0.1; // err_num = err_num + 0.1;
    //     printf("%d번째: %.20f\n", i, err_num);
    // }

    char cnum = 128; // char 형의 최대값은 127이다.
    unsigned char u_cnum = 255; // 0 ~ 255 
    short snum = 32768; // short 형의 최대 값은 32767이다.
    unsigned short u_snum = 32768;

    printf("%d\n", cnum);
    printf("%d\n", u_cnum);
    printf("%d\n", snum);
    printf("%d\n", u_snum);

    return 0;
}