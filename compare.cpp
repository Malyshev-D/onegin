#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "compare.h"

bool DirectCmp(void* pstr1, void* pstr2)
{
    // инициализируем бегунки
    char* current1 = (char*) pstr1;
    char* current2 = (char*) pstr2;
    assert(current1 != 0);
    assert(current2 != 0);


    while (*current1 != 0 && *current2 != 0)
    {
        // проверка на алфавит: не буква - бегунок идет дальше
        if (isalpha(*current1) == 0)
        {
            current1++;
            continue;
        }
        if (isalpha(*current2) == 0)
        {
            current2++;
            continue;
        }

        // сравнение букв
        if (tolower(*current1) == tolower(*current2))
        {
            current1++;
            current2++;
            continue;
        }
        if (tolower(*current1) > tolower(*current2))
        {
            return true;
        }

        if (tolower(*current1) < tolower(*current2))
        {
            return false;
        }
    }
    // если первый бегунок дошел первым, то вторая строка "больше"
    if (*current1 == '\0')
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool ReverseCmp(void* pstr1, void* pstr2)
{
    // инициализируем бегунки
    char* current1 = (char*) pstr1;
    char* current2 = (char*) pstr2;
    assert(current1 != 0);
    assert(current2 != 0);

    // сдвигаем бегунки до конца
    while (*current1 != 0 || *current2 != 0)
    {
        if (*current1 != 0)
        {
            current1++;
        }
        if (*current2 != 0)
        {
            current2++;
        }
    }
    current1--;
    current2--;

    while (current1 != pstr1 && current2 != pstr2)
    {
        // проверка на алфавит: не буква - бегунок идет дальше
        if (isalpha(*current1) == 0)
        {
            current1--;
            continue;
        }
        if (isalpha(*current2) == 0)
        {
            current2--;
            continue;
        }

        // сравнение букв
        if (tolower(*current1) == tolower(*current2))
        {
            current1--;
            current2--;
            continue;
        }
        if (tolower(*current1) > tolower(*current2))
        {
            return true;
        }
        if (tolower(*current1) < tolower(*current2))
        {
            return false;
        }
    }
    // если первый бегунок дошел первым, то вторая строка "больше"
    if (current1 == pstr1)
    {
        return false;
    }
    else
    {
        return true;
    }

}

bool PointersCmp(void* pstr1, void* pstr2)
{
    if (pstr1 > pstr2)
        return 1;
    return 0;
}
