/*
파일명: ex02-03-literal.c

리터럴(Literal)
    값이 그 자체로 고정된 상수를 의미

    예)
    정수형 상수 : 10, -10
    실수형 상수 : 2.2, 3.14, -5.1
    문자형 상수 : 'A', 'B', 'C'

심볼릭 상수 (const)
    상수에 이름을 붙여준 것
    초기 값을 저장하면 변경불가
    프로그램 흐름을 따라 컴파일됨.

매크로 상수
    심볼릭 상수 일종
    컴파일시 가장먼저 매크로 상수 처리

tip : 가독성을 위해 통상적으로 상수명은 대문자로 표시!
*/
#include <stdio.h>
#define LENGTH 10   // 매크로 상수 정의에서는 세미콜론(;)이 필요하지 않다.

int main(void)
{
    int number = 3; // 일반변수
    const int NUMBER = 5; // 심볼릭 상수 선언
    number = 10;    // 변수는 값을 변경할 수 있다.
    // NUMBER = 11;    // 상수는 값을 변경할 수 없다. 변경시 컴파일 에러!

    printf("%d\n", LENGTH);
    printf("%d\n", number);
    printf("%d\n", NUMBER);

    return 0;
}

