/*
파일명: ex13-04-gets-puts.c

gets() 
    문자열 입력
puts()
    문자열 출력

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    /*
    char ch[30];
    gets(ch);
    puts(ch);   // 자동 줄바꿈 
    printf("이 문자열은 다음줄에서 출력됩니다.\n");
    */

   char ch[30];
   // 표준 입력에서 문자열 읽기(버퍼, 버퍼 크기, stdin 표준입력 스트림)
   fgets(ch, 30, stdin);

   fputs(ch, stdout);
   printf("이 문자열은 다음줄에서 출력됩니다.\n");



    return 0;
}
