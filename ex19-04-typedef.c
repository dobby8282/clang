/*
파일명: ex19-04-typedef.c

typedef
    자료형 이름을 마음대로 붙일 수 있다.
    자료형 이름이 추가된거지 기존 자료형 이름이 변경된건 안니다.
*/

#include <stdio.h>

// int형 정수, int형 정수포인터, 부호없는 int형 정수에 각각 이름 붙이기
typedef int INT;
typedef int* PINT;
typedef unsigned int UINT;

int main(void)
{
    // 지역 내에서 사용할 자료형 이름에 대한 선언
    typedef char CHAR;
    typedef char* STR;

    // typedef 선언 이후 자료형은 기존 자료형과 동일한 역할 수행
    INT num = 3;
    PINT ptr = &num;
    UINT unum = 5;

    CHAR ch = 'c';
    STR str = "Hello!";

    printf("%d %d %d\n", num, *ptr, unum);
    printf("%c %s\n", ch, str);

    return 0;
}


