/*
파일명: ex12-01-array2d.c

2차원 배열

*/
#include <stdio.h>

int main(void)
{
    int i, j;
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    printf("%d\n", arr[0][0]);
    printf("%d\n", arr[1][1]);

    // 전체 출력하기
    for (i = 0; i < 2; i++) 
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // 배열의 요소 값들 모두 10으로 변경하기
    for(i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            arr[i][j] = 10;
        }
    }


    // 전체 출력하기
    for (i = 0; i < 2; i++) 
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}