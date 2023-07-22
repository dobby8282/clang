/*
파일명: ex18-01-heap.c

힙 영역의 필요성
    예제 처럼 지역변수 사용시 함수를 벗어나면 소멸
    전역변수 사용시 코드가 복잡해지고 관리가 힘들어 질 수 있다.
    
*/
#include <stdio.h>

char* getString(void)
{
    char str[100];
    printf("좋아하는 단어는?");
    gets(str); //문자열 입력함수

    printf("함수 안에서 결과: %s\n", str);

    return str;

}

int main(void)
{
    char* result = getString();

    printf("당신이 좋아하는 단어는: %s\n", result);
    return 0;
}