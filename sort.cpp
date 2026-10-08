#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "compare.h"
#include "sort.h"

#define COLOR_RED_BOLD "\x1b[31;1m"
#define COLOR_RESET "\x1b[0m"

void SwapPointers(char** a1, char** a2)
{
    char* temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}


void BubbleSort(char** arr, int leng, bool (*Compare) (void* pstr1, void* pstr2))
{
    bool checker = true;
    for (int nPass = 0; nPass < leng; nPass++)
    {
        checker = true;
        for (int idx = 0; idx < leng - nPass - 1; idx++)
        {
            if (Compare(arr[idx], arr[idx + 1]))
            {
                SwapPointers(&(arr[idx]), &(arr[idx + 1]));
                if (checker == true)
                    checker = false;
            }
        }
        if (checker == true)
            break;
    }
}
