/*
파일명: ex15-03-function3.c
*/

int getBigger(int n1, int n2)
{
    if (n1 > n2)
    {
        return n1;
    }
    else if (n1 < n2)
    {
        return n2;
    }
    else 
    {
        return 0;
    }
}

int main(void)
{
    int result; // 반환값을 저장하는 변수

    result = getBigger(3, 5);
    printf("첫번째 결과: %d\n", result);

    result = getBigger(8, 2);
    printf("두번째 결과: %d\n", result);

    result = getBigger(4, 4);
    printf("세번째 결과: %d\n", result);

    return 0;
}



