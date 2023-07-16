/*
파일명: ex13-06-string-function.c

    4. strcat(str1, str2)
        문자열 이어 붙이기
    5. strncat(str1, str2, count)
        원하는 개수만큼 문자열 이어붙이기
    6. strcmp(str1, str2)
        두 문자열 비교 같으면 0, 같지 않으면 0이 아닌 값을 반환
    7. strncmp(str1, str2, count)
        count개 두 문자열 비교 같으면 0, 같지 않으면 0이 아닌 값 반환
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[50] = "Michael ";
    char str2[50] = "Michael ";

    // strcat 문자열 붙이기
    strcat(str1, "Bolton");
    puts(str1);

    // str2 에 7개의 문자 붙이기
    strncat(str2, "Jackson Five", 7);
    puts(str2);


    // str1 과 str2 비교
    printf("비교 결과: %d\n", strcmp(str1, str2));

    // str1 과 str2 비교 앞의 7개 문자만 비교
    printf("비교 결과: %d\n", strncmp(str1, str2, 7));











    return 0;
}