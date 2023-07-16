/*
파일명: ex16-02-function-array2.c
*/
#include <stdio.h>

int readArray(int arr[], int length) // int arr[] = 005ffe90 int length = 3
{
    int i;
    printf("배열의 요소 읽어보기: [ ");
    for (i = 0; i < length; i++)
    {
        printf("%d", arr[i]);
        if (i + 1 < length)
        {
            printf(", ");
        }
        else 
        {
            printf(" ");
        }
    }
    printf("]\n");

}

int main(void)
{
    int arr[3] = { 3, 6, 9 };

    printf("arr 주소값: %p\n", arr);

    int length = 3;
    readArray(arr, length); // 배열의 이름 arr를 포인터 변수에 대입

    return 0;
}

