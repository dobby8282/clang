/*
파일명: ex12-02-array3d.c

3차원 배열
*/
#include <stdio.h>

int main(void)
{
    short sarr[2][3][4];
    int iarr[2][3][4];

    printf("size of sarr: %d\n", sizeof(sarr));
    printf("szie of iarr: %d\n", sizeof(iarr));

    // 3차원 배열 선언과 동시에 초기화
    int arr[2][3][4] = {
        {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12}
        },
        {
            {21,22,23,24},
            {25,26,27,28},
            {29,30,31,32}
        }
    };

    /*
    
        1 2 3 4
        5 6 7 8
        9 10 11 12

        21 22 23 24
        25 26 27 28
        29 30 31 32
    
    
    */

   // 3차 배열 전체 출력
   int i, j, k;
   for (i = 0; i < 2; i++)
   {
        for (j = 0; j < 3; j++)
        {
            for(k = 0; k < 4; k++)
            {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
   }
   return 0;
}