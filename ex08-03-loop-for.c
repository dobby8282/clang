/*
파일명: ex08-03-loop-for.c

3. for 문

    for(변수 초기화; 조건식; 증감식)
    {
        반복 실행할 코드
    }
*/

#include <stdio.h>

int main(void)
{

    for (int i = 0; i < 3; i++)
    {
        printf("i is %d now\n", i);
    }

    int j = 0;
    while (j < 3)
    {
        printf("j is %d now\n", j);
        j++;
    }


    return 0;
}