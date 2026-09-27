#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "strfunc.h"
#include "array.h"

#define len(a) (sizeof(a) / sizeof(a[0]))
#define COLOR_RED_BOLD "\x1b[31;1m"
#define COLOR_RESET "\x1b[0m"

void SwapPointers(char** a1, char** a2)
{
    char* temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

void PrintPointerArr (char** arr, int leng)
{
    for (int ind = 0; ind < leng; ind++)
    {
        puts(arr[ind]);
    }
}

void BubbleSort(char** arr, int leng)
{
    for (int nPass = 0; nPass < leng; nPass++)
    {
        for (int idx = 0; idx < leng - nPass - 1; idx++)
        {
            if (StringCmp(arr[idx], arr[idx + 1]))
            {
                SwapPointers(&(arr[idx]), &(arr[idx + 1]));
            }
        }
    }
}

void SafeCalloc(char** pointer, size_t num, size_t size)
{
    char** test_pointer = (char**)calloc(num, size);
    if (test_pointer == 0)
    {
        printf(COLOR_RED_BOLD "Error: calloc returned 0 in file: %d in line %d" COLOR_RESET,
        __FILE__, __LINE__);
    }
    else
    {
        pointer = test_pointer;
    }
}
