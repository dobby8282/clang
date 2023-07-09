/*
파일명: ex06-01-operator2.c

4. 논리 연산자
    && (AND): 피연산자가 모두 참이면 참
    || (OR): 피연산자 중 참이 있으면 참
    ! (NOT): 피연산자가 참이면 거짓, 거짓이면 참(반전)

5. 비트 단위 연산자
    & : 대응이 되는 비트가 모두 1이면 1반환 (비트 AND 연산자)
    | : 대응이 되는 비트 중에서 하나라도 1이면 1반환 (비트 OR 연산자)
    ^ : 대응이 되는 비트가 서로 다르면 1반환 (비트 XOR 연산자)
    ~ : 비트가 1이면 0으로, 0이면 1로 반전시킴 (비트 NOT 연산자)

6. 시프트 연산자
    << : 지정한 수만큼 비트들을 전부 왼쪽으로 이동시킴(left shift 연산자)
    >> : 부호를 유지하면서 지정한 수만큼 비트를 전부 오른쪽으로 이동시킴(right shift 연산자)

7. 증감 연산자
    ++ : 변수의 값을 1 증가시킨다.
    -- : 변수의 값을 1 감소시킨다.

8. 삼항 조건 연산자
    조건식 ? 참일 경우 결과 : 거짓일 경우 결과

*/
#include <stdio.h>

int main(void)
{
    printf("논리 연산자\n");
    int num1 = 20, num2 = 10;
    int result;
    result = 1 && 1;
    printf("1) result: %d\n", result);

    result = num1 == 20 && num2 == 10;
    printf("2) result: %d\n", result);

    result = num1 > num2 || num1 == num2;
    printf("3) result: %d\n", result);

    result = !(num1 > num2 || num1 == num2);
    printf("4) result: %d\n", result);

    printf("\n");

    // 비트 연산자
    printf("비트 연산자\n");
    int a = 3;
    int b = 5;

    printf("3 & 5 = %d\n", a & b);
    printf("3 | 5 = %d\n", a | b);
    printf("3 ^ 5 = %d\n", a ^ b);
    printf("~3 = %d\n", ~a);

    printf("\n");


    printf("시프트 연산자\n");
    int x, y;
    x = 3; // 0011 >> 2 = 0000
    y = x << 2;
    printf("%d << 2 = %d\n", x, y);
    y = x >> 2;
    printf("%d >> 2 = %d\n", x, y);

    printf("\n");

    printf("증감 연산자\n");
    // 전위 증감연산자
    int i = 1;
    printf("1)전위 증감연산자: %d\n", ++i);
    printf("2)전위 증감연산자: %d\n", i);

    // 후위 증감연산자
    int j = 1;
    printf("1)후위 증감연산자: %d\n", j++);
    printf("2)후위 증감연산자: %d\n", j);
    
    printf("\n");
    
    // 삼항 연산자
    printf("삼항 연산자\n");

    int num = -10;
    int absolute = num > 0 ? num : num * -1;

    printf("절대값: %d\n", absolute);

    return 0;
}
