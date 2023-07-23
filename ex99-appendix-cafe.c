// 보안 경고를 무시하는 매크로 정의
#define _CRT_SECURE_NO_WARNINGS
// 필요한 헤더 파일 포함
#include <stdio.h>
#include <string.h>

// 상수 정의
#define MAX_LEN 10     // 음료 최대 추가 가능 개수
#define TRUE 1         // 참을 나타내는 상수
#define FALSE 0        // 거짓을 나타내는 상수

// 메뉴 선택을 위한 상수 정의
#define ADD 1          // 음료 추가
#define REMOVE 2       // 음료 삭제
#define CHECK 3        // 선택 음료 확인
#define ORDER 4        // 선택 음료 주문
#define END 5          // 프로그램 종료

// 음료 선택을 위한 상수 정의
#define AMERICANO 1    // 아메리카노
#define CAFELATTE 2    // 카페라떼
#define JUICE 3        // 주스
#define ICECREAM 4     // 아이스크림
#define CANCEL 5       // 동작 취소

// 음료 가격 상수 정의
#define AMERICANO_PRICE 4000
#define CAFELATTE_PRICE 4500
#define JUICE_PRICE 5000
#define ICECREAM_PRICE 5500

// 음료 리스트를 위한 구조체 정의
typedef struct
{
    char* foods[MAX_LEN];    // 음료를 저장하는 배열
    int idxOfFoods;          // 음료 배열의 현재 인덱스
    int totalPrice;          // 선택한 음료의 총 가격
} ItemList;

// 메인 메뉴 출력 함수
void select()
{
    puts("====== WHAT DO YOU WANT ======");
    puts("1. 음료 추가");
    puts("2. 음료 삭제");
    puts("3. 선택 음료 확인");
    puts("4. 선택 음료 주문");
    puts("5. 프로그램 종료");
}

// 음료 추가 메뉴 출력 함수
void showMenu()
{
    puts("====== ADD MENU ======");
    puts("1. 아메리카노 (4000)");
    puts("2. 카페라떼 (4500)");
    puts("3. 주스 (5000)");
    puts("4. 아이스크림 (5500)");
    puts("5. 동작 취소");
}

// 음료 삭제 메뉴 출력 함수
void showRemoveMenu()
{
    puts("====== REMOVE MENU ======");
    puts("1. 아메리카노 (4000)");
    puts("2. 카페라떼 (4500)");
    puts("3. 주스 (5000)");
    puts("4. 아이스크림 (5500)");
    puts("5. 동작 취소");
}

// 음료 추가 함수
void addMenu(ItemList* itemlist)
{
    // 이미 선택 가능한 최대 음료를 선택한 경우 오류 메시지 출력 후 함수 종료
    if (itemlist->idxOfFoods >= MAX_LEN)
    {
        puts("더 이상 추가할 수 없습니다!");
        return;
    }

    int choice; // 사용자의 선택을
    // 저장할 변수 선언
    showMenu(); // 음료 추가 메뉴 출력
    printf("선택 : "); 
    scanf("%d", &choice); // 사용자로부터 입력 받음
    switch (choice) // 사용자의 선택에 따라 적절한 작업 수행
    {
    case AMERICANO: // 아메리카노 선택 시
        puts("아메리카노 추가");
        itemlist->foods[(itemlist->idxOfFoods)++] = "아메리카노"; // 아메리카노를 음료 리스트에 추가
        itemlist->totalPrice += AMERICANO_PRICE; // 총 가격에 아메리카노 가격 추가
        break;
    case CAFELATTE: // 카페라떼 선택 시
        puts("카페라떼 추가");
        itemlist->foods[(itemlist->idxOfFoods)++] = "카페라떼"; // 카페라떼를 음료 리스트에 추가
        itemlist->totalPrice += CAFELATTE_PRICE; // 총 가격에 카페라떼 가격 추가
        break;
    case JUICE: // 주스 선택 시
        puts("주스 추가");
        itemlist->foods[(itemlist->idxOfFoods)++] = "주스"; // 주스를 음료 리스트에 추가
        itemlist->totalPrice += JUICE_PRICE; // 총 가격에 주스 가격 추가
        break;
    case ICECREAM: // 아이스크림 선택 시
        puts("아이스크림 추가");
        itemlist->foods[(itemlist->idxOfFoods)++] = "아이스크림"; // 아이스크림을 음료 리스트에 추가
        itemlist->totalPrice += ICECREAM_PRICE; // 총 가격에 아이스크림 가격 추가
        break;
    case CANCEL: // 취소 선택 시
        puts("동작 취소");
        break;
    default: // 그 외 잘못된 입력 시
        puts("잘못된 입력입니다. 동작을 취소합니다.");
        break;
    }
}

// 음료 삭제 함수
int removeItem(ItemList* itemlist, char* itemToRemove)
{
    int i, rmIdx = -1; // 삭제할 음료의 인덱스를 저장할 변수 선언 및 초기화
    for (i = 0; i < itemlist->idxOfFoods; i++) // 음료 리스트를 순회
    {
        if (!strcmp(itemlist->foods[i], itemToRemove)) // 삭제할 음료를 찾았을 경우
        {
            rmIdx = i; // 삭제할 음료의 인덱스 저장
            break;
        }
    }
    if (rmIdx >= 0) // 삭제할 음료를 찾았을 경우
    {
        for (i = rmIdx; i < itemlist->idxOfFoods; i++) // 삭제할 음료 이후의 음료들을 왼쪽으로 이동
        {
            itemlist->foods[i] = itemlist->foods[i + 1];
        }
        if (rmIdx == 0 && itemlist->idxOfFoods == 1)
        {
            itemlist->foods[0] = NULL; // 음료 리스트에 음료가 하나만 있었을 경우 NULL로 설정
        }
        printf("%s 삭제했습니다\n", itemToRemove); // 삭제 완료 메시지 출력
        return TRUE;
    }
    else
    {
        printf("삭제할 대상이 없습니다!\n"); // 삭제할 음료를 찾지 못했을 경우 메시지 출력
        return FALSE;
    }
}

// 음료 삭제 메뉴 출력 및 삭제 작업 수행 함수
void removeMenu(ItemList* itemlist)
{

    if (itemlist->idxOfFoods <= 0) // 음료 리스트가 비어있을 경우
    {
        puts("더 이상 삭제할 수 없습니다!"); // 메시지 출력
        return;
    }

    int choice;
    showRemoveMenu(); // 음료 삭제 메뉴 출력
    printf("선택 : ");
    scanf("%d", &choice); // 사용자로부터 선택 입력 받음
    switch (choice) // 사용자의 선택에 따라 적절한 작업 수행
    {
    case AMERICANO: // 아메리카노 선택 시
        if (removeItem(itemlist, "아메리카노")) // 아메리카노 삭제 시도
        {
            itemlist->totalPrice -= AMERICANO_PRICE; // 총 가격에서 아메리카노 가격 차감
            (itemlist->idxOfFoods)--; // 음료 리스트에서 아메리카노 제거
        }
        break;
    case CAFELATTE: // 카페라떼 선택 시
        if (removeItem(itemlist, "카페라떼")) // 카페라떼 삭제 시도
        {
            itemlist->totalPrice -= CAFELATTE_PRICE; // 총 가격에서 카페라떼 가격 차감
            (itemlist->idxOfFoods)--; // 음료 리스트에서 카페라떼 제거
        }
        break;
    case JUICE: // 주스 선택 시
        if (removeItem(itemlist, "주스")) // 주스 삭제 시도
        {
            itemlist->totalPrice -= JUICE_PRICE; // 총 가격에서 주스 가격 차감
            (itemlist->idxOfFoods)--; // 음료 리스트에서 주스 제거
        }
        break;
    case ICECREAM: // 아이스크림 선택 시
        if (removeItem(itemlist, "아이스크림")) // 아이스크림 삭제 시도
        {
            itemlist->totalPrice -= ICECREAM_PRICE; // 총 가격에서 아이스크림 가격 차감
            (itemlist->idxOfFoods)--; // 음료 리스트에서 아이스크림 제거
        }
        break;
    case CANCEL: // 취소
        puts("동작 취소"); // 사용자가 취소를 선택하면 취소 메시지 출력
        break;
    default:
        puts("잘못된 입력입니다. 동작을 취소합니다."); // 유효하지 않은 선택일 경우 메시지 출력
        break;
    }
}

// 선택한 음료와 총액을 출력하는 함수
void checkMenu(ItemList* itemlist)
{
    int i = 0;
    printf("주문 품목 총액은 %d원입니다! 품목은 다음과 같습니다.\n ==> ", itemlist->totalPrice); // 총액과 메시지 출력
    for (i = 0; i < itemlist->idxOfFoods; i++) // 선택한 모든 음료 출력
    {
        printf("%s,", itemlist->foods[i]);
    }
    printf("\b "); // 마지막 쉼표 제거
    printf(" \n");
}

// 주문을 처리하는 함수
int order(ItemList* itemlist)
{
    if (itemlist->idxOfFoods <= 0) // 선택한 음료가 없을 경우
    {
        puts("아무것도 선택하지 않아 주문 불가합니다!"); // 메시지 출력
        return -1;
    }

    int choice;
    checkMenu(itemlist); // 선택한 음료와 총액 출력
    puts("정말로 주문하시겠어요?"); // 주문 확인 메시지 출력
    printf("yes (1) , no (2) : "); // 사용자에게 주문 확인 여부 물음
    scanf("%d", &choice); // 사용자의 응답 입력 받음

    if (choice == 1) // 사용자가 'yes'를 선택하면
        return TRUE; // 참 반환
    else // 사용자가 'no'를 선택하면
        return FALSE; // 거짓 반환
}

// 메인 함수
int main(void)
{
    ItemList itemlist; // 주문 정보를 저장할 구조체 선언
    itemlist.idxOfFoods = 0; // 선택한 음료 개수 초기화
    itemlist.totalPrice = 0; // 총액 초기화
    int choice;

    while (1) // 무한 반복
    {
        select(); // 메인 메뉴 출력
        printf("선택 : ");
        scanf("%d", &choice); // 사용자로부터 선택 입력 받음
        printf("\n\n");
        switch (choice) // 사용자의 선택에 따라 적절한 작업 수행
        {
        case ADD: // 음료 추가
            addMenu(&itemlist);
            printf("\n\n");
            break;
        case REMOVE: // 음료 삭제
            removeMenu(&itemlist);
            printf("\n\n");
            break;
        case CHECK: // 선택한 음료 확인
            checkMenu(&itemlist);
            printf("\n\n");
            break;
        case ORDER: // 주문
            if (order(&itemlist)) // 주문이 성공적으로 이루어졌을 경우
            {
                puts("주문 완료! 프로그램을 종료합니다."); // 주문 완료
                // 주문 완료 메시지 출력하고 프로그램 종료
                return 0;
            }
            else
            {
                puts("주문 보류!"); // 주문이 보류되었음을 알리는 메시지 출력
                printf("\n\n");
            }
            break;
        case END: // 프로그램 종료
            puts("프로그램을 종료합니다."); // 프로그램 종료 메시지 출력
            return 0;
        default: // 유효하지 않은 선택일 경우 메시지 출력하고 프로그램 종료
            puts("잘못된 입력입니다. 동작을 취소합니다.");
            return 0;
        }
    }

    return 0;
}
