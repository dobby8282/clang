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


          i     j
   *      0   j > 3  -> j > 3+i
  ***     1   j > 4  -> j > 3+i
 *****    2   j > 5  -> j > 3+i
*******   3   
 ******   4   j > 5  -> i+j > 9
  *****   5   j > 4  -> i+j > 9
   ****   6   j > 3  -> i+j > 9

*/
#include <stdio.h>

int main(void)
{
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(i < 7/2+1) {
                if(j < 3-i) {
                    printf(" ");
                } else if(j > 3+i) {
                    printf(" ");
                } else {
                    printf("*");
                }
            } else {
                if(j < i-3) {
                    printf(" ");
                } else if(i+j > 9) {
                    printf(" ");
                } else {
                    printf("*");
                }
            }
        }
        printf("\n");        
    }

    return 0;
}