/*
파일명: ex10-01-pointer.c

포인터
    메모리의 주소값을 의미하며 주소값을 저장하는 변수를 가리켜
    '포인터 변수' 라고 한다.

    & 주소연산자 : 변수앞에 붙어서 변수의 메모리 시작 주소값을 구한다.
    * 포인터 : 포인터변수를 선언할 때 사용
    * 간접 참조 연산자(dereference operator or indirection operator) 
        : 선언된 포인터 변수가 가리키는 변수
    

*/

#include <stdio.h>

int main(void)
{
    int inum = 999;

    int* iptr = &inum;

    printf("%p\n", iptr);   // 00000000005ffe9c
    printf("%p\n", &iptr);  // 00000000005ffe90

    printf("%d\n", *iptr);  // *iptr == inum



    int num = 10;
    int* pnum;
    pnum = &num; // 포인터 변수 pnum은 num의 주소를 저장

    printf("%d\n", *pnum);

    printf("1) num의 주소값: %p\n", &num);
    printf("2) pnum의 값: %p\n", pnum);

    num = 14;
    printf("3) num의 주소값: %p\n", &num);
    printf("4) pnum의 값: %p\n", pnum);

    printf("5) num: %d\n", num);
    printf("6) *pnum: %d\n", *pnum);

    *pnum = 30;
    printf("7) num: %d\n", num);
    (*pnum)++;
    (*pnum)++;
    printf("8) num: %d\n", num);
    printf("9) *pnum: %d\n", *pnum);

    return 0;
}