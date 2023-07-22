/*
파일명: ex18-02-malloc.c

메모리 동적할당
    malloc 함수
        사용자가 생성과 소멸의 시기를 결정할 수 있는 변수선언

*/
#include <stdio.h>
#include <stdlib.h> // 동적 할당 함수를 사용하기 위한 헤더파일 선언

int main(void)
{
    // int형 5개만큼 사이즈로 메모리공간 선언
    int* iptr = (int*)malloc(sizeof(int) * 5); 
    // double형 3개 만큼 공간선언
    double* dptr = (double*)malloc(sizeof(double) * 3); 

    for (int i = 0; i < 5; i++)
    {
        iptr[i] = 10 * (i+1);
    }
    for (int i = 0; i < 5; i++) 
    {
        printf("%d ", iptr[i]);
    }
    printf("\n");

    dptr[0] = 3.14; dptr[1] = 4.31; dptr[2] = 1.43;

    if(iptr != NULL) free(iptr); // 동적으로 할당한 메모리 해제
    if(dptr != NULL) free(dptr); // 동적으로 할당한 메모리 해제




    return 0;
}

