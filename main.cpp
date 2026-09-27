#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "strfunc.h"
#include "array.h"

#define len(a) (sizeof(a) / sizeof(a[0]))
#define COLOR_RED_BOLD "\x1b[31;1m"
#define COLOR_RESET "\x1b[0m"

int main()
{
    char str1 [] = "My uncle";
    char str2 [] = "WhEN";
    char str3 [] = "when";
    char str4 [] = "role";
    char str5 [] = "te1ddy bear";
    char str6 [] = " beep";
    char str7 [] = "excuse me";
    char str8 [] = "stop";
    char str9 [] = "Again";
    char str10[] = "The gates";

    const int leng = 10;
    char** arr;
    SafeCalloc(arr, leng, sizeof(char*));

    arr[0] = str1;
    arr[1] = str2;
    arr[2] = str3;
    arr[3] = str4;
    arr[4] = str5;
    arr[5] = str6;
    arr[6] = str7;
    arr[7] = str8;
    arr[8] = str9;
    arr[9] = str10;

    BubbleSort(arr, leng);
    PrintPointerArr(arr, leng);
}
