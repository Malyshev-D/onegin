#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>

#include "compare.h"
#include "sort.h"
#include "files.h"

int main()
{
    // названия файлов
    const char origin_file[]   = "onegin.txt";
    const char direct_file[]   = "direct.txt";
    const char reversed_file[] = "reversed.txt";
    const char copy_file[]     = "copy.txt";

    // создание буфера и массива указателей
    char* buffer = 0;
    char** index_array = 0;
    int nlines = ReadFromFile(origin_file, &index_array, &buffer);
    if (nlines = -1)
    {
        printf("Something went wrong...\n");
        abort();
    }

    // сортировка слева направо
    BubbleSort (index_array, nlines, DirectCmp);
    PrintInFile(direct_file, index_array, nlines);

    // сортировка справа налево
    BubbleSort (index_array, nlines, ReverseCmp);
    PrintInFile(reversed_file, index_array, nlines);

    // оригинальный текст
    BubbleSort (index_array, nlines, PointersCmp);
    PrintInFile(copy_file, index_array, nlines);

    free(buffer);
    free(index_array);
    return 0;
}
