/*
파일명: ex17-03-multiple-pointer.c

다중 포인터

*/
#include <stdio.h>

int main(void)
{
    int num = 999;
    int* ptr = &num;
    int** dptr = &ptr;
    int*** tptr = &dptr;
    int**** qptr = &tptr;
    int***** fptr = &qptr;

    printf("%d %d %d %d %d %d\n", num, *ptr, **dptr, ***tptr, ****qptr, *****fptr);

    return 0;
}