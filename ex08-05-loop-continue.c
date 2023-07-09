/*
파일명: ex08-05-loop-continue.c

continue 문
    반복문에서 해당 반복을 건너뛰고 다음 반복을 실행하도록 
    강제하는 명령어
*/
#include <stdio.h>

int main(void)
{
    int num;
    for (num = 1; num <= 5; num++)
    {
        if (num == 3)
            continue;
        
        printf("%d\n", num);
    }

    return 0;
}