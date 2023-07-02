/*
파일명: ex02-01-variable.c

변수란?
    메모리 공간에 붙여진 이름.
    C 프로그램 사용되는 모든 값을 메모리 공간에 저장
    메모리 공간에 이름을 붙여 접근 가능.

변수 선언 및 초기화
    자료형 변수명 = 값

변수명 규칙
    알파벳, 숫자, 언더바(_) 로만 구성.
    숫자로 시작 (X)
    공백 포함 (X)
    키워드 변수명 (X)

주의: C언어는 알파벳 대/소문자 구분한다.

*/

#include <stdio.h>

int main(void) 
{
    int number1, number2; // 두 개의 int형 변수를 한번에 선언

    number1 = 1;    // 초기화
    number2 = 2;
    // 선언과 동시에 초기화(값 대입)
    int number3 = 3, number4 = 4;
    int number5 = 5;

    /*
        Ctrl + c (줄복사) -> Ctrl + v (붙여넣기)
        Ctrl + Shift + k (줄삭제)
    */
    printf("%d\n", number1);
    printf("%d\n", number2);
    printf("%d\n", number3);
    printf("%d\n", number4);
    printf("%d\n", number5);
    
    /* 사용 가능한 변수명들 */
    int num = 3; // int는 '정수'를 의미하는 자료형
    int number6 = 6;
    int num_ber = 10;
    int Number = 15;

    /* 사용 불가한 변수명들 */
    // Ctrl + / 주석 단축키
    // int hello boy = 3; // 공백포함    
    // int hi#$ = 5; // 특수기호 사용
    // int 8number = 8; // 숫자로 시작
    // int short = 3; // 기능이 있는 키워드




    return 0;
}