/*
파일명: ex20-02-structure-pointer2.c

화살표연산자 (arrow operator)
    -> : 포인터 사용하는 구조체의 멤버에 접근하기 위해 사용
*/

#include <stdio.h>

typedef struct 
{
    int x; int y;
}Point;

typedef struct 
{
    Point* start;   // 구조체 포인터변수 start
    Point* end;     // 구조체 포인터변수 end
}Line;

int main(void)
{
    Point p1 = {10, 8};
    Point p2 = {20, 40};

    Line line = {&p1, &p2};

    printf("선의 시작점: [%d %d]\n", line.start->x, line.start->y);
    printf("선의 끝점: [%d %d]\n", line.end->x, line.end->y);

    printf("선의 시작점: [%d %d]\n", (*line.start).x, (*line.start).y);
    printf("선의 끝점: [%d %d]\n", (*line.end).x, (*line.end).y);

    return 0;
}










