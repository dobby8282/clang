/*
파일명: ex08-99-homework.c

1번 분석하기 
*
**
***
****
*****
******
*******
2번
   *
  **
 ***
****
3번
   *
  ***
 *****
*******

4번
   *
  ***
 *****
*******
 *****
  ***
   *




*/
#include <stdio.h>

int main(void)
{

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}