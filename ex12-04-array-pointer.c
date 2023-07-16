/*
파일명: 12-04-array-pointer.c

배열 포인터
*/

#include <stdio.h>

int main(void)
{

    // 2개의 행과 3개의 열로 이루어진 2차원배열
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // 열이 3개인 2차원 배열의 포인터
    int(*arrptr)[3] = arr;

    int i, j;
    for (i = 0; i < 2; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d", arrptr[i][j]);
        }
        printf("\n");
    }

    return 0;
}