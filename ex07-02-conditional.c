/*
파일명: ex07-02-conditional.c

2. switch 문

*/
#include <stdio.h>

int main(void)
{
    int num = 1;
    switch (num)
    {
    case 0:
        printf("0 입니다. \n");
        break;
    case 1:
        printf("1 입니다. \n");
        break;
    case 2:
        printf("2 입니다. \n");
        break;
    case 3:
        printf("3 입니디. \n");
        break;
    default:
        printf("0 ~ 3 이 아닙니다.");
        break;
    }


    char btn = 'a';

    switch (btn)
    {
    case 'w':
        printf("앞으로 이동\n");
        break;
    case 'a':
        printf("좌측으로 이동\n");
        break;
    case 's':
        printf("뒤로 이동\n");
        break;
    case 'd':
        printf("우측으로 이동\n");
        break;
    default:
        printf("Hold!\n");
        break;
    }

    /*
    
    rtnCd 
        1: 환불신청
        2: 검토중
        3: 이체중
        4: 완료
    
    */

    int rtnCd = 1;

    switch (rtnCd)
    {
    case 1:
    case 2:
    case 3:
        printf("환불 불가 상태 rtnCd: %d\n", rtnCd);
        break;
    }

    return 0;
}