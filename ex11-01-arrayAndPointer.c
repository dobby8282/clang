/*
파일명: ex11-01-arrayAndPointer.c

포인터와 배열의 관계
    배열의 이름은 포인터 변수 역할을 한다.
    시작 메모리 주소 확인 가능.
    단 값 저장이 불가능 상수(Constant) 이다.

*/

#include <stdio.h>
int main(void)
{
    int myArr[3] = {1, 2, 3};
    printf("배열 각 요소의 주소 확인\n");
    printf("배열의 이름: %p\n", myArr);
    printf("첫번째 요소: %p\n", &myArr[0]);
    printf("두번째 요소: %p\n", &myArr[1]);
    printf("세번째 요소: %p\n", &myArr[2]);

    printf("배열 이름의 사이즈: %d\n", sizeof(myArr));
    printf("첫번째 요소의 사이즈: %d\n", sizeof(myArr[0]));

    return 0;
}
