/*
파일명: ex18-06-malloc-realloc-wchar_t.c
한글 입력/출력
*/
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_BUFFER_SIZE 1

int main(void)
{   
    printf("sizeof: %d\n", sizeof(wchar_t));

    wchar_t c;
    int len = 0;
    int buffer_size = INITIAL_BUFFER_SIZE;
    wchar_t* str = (wchar_t*)malloc(buffer_size * sizeof(wchar_t));

    if (str == NULL)
    {
        wprintf(L"Memory allocation failed\n");
        return 1;
    }

    wprintf(L"Enter a string: ");

    while((c = getwchar()) != L'\n' && c != WEOF)
    {
        str[len++] = c;

        if (len == buffer_size)
        {
            buffer_size *=2;
            str = (wchar_t*)realloc(str, buffer_size * sizeof(wchar_t));

            if (str == NULL)
            {
                wprintf(L"Memory allocation failed\n");
                return 1;
            }
        }
    }

    str[len] = L'\0';

    wprintf(L"You entered: %ls\n", str);

    free(str);


    return 0;
}