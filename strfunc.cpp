#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "strfunc.h"

bool StringCmp(void* pstr1, void* pstr2)
{
    char* current1 = (char*) pstr1;
    char* current2 = (char*) pstr2;
    while (*current1 != 0 && *current2 != 0)
    {
        if (IsLetter(*current1) == 0)
        {
            current1++;
            continue;
        }
        if (IsLetter(*current2) == 0)
        {
            current2++;
            continue;
        }

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
    if (*current1 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

bool IsLetter(char sym)
{
    if ((65 <= sym && sym <= 90) || (97 <= sym && sym <= 122))
        return true;
    return false;
}
