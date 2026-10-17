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
    int lines_count = ReadFromFile(origin_file, &index_array, &buffer);
    if (lines_count == -1)
    {
        printf("Something went wrong...\n");
        free(buffer);
        free(index_array);
        return 0;
    }

    // сортировка слева направо
    BubbleSort (index_array, lines_count, DirectCmp);
    PrintInFile(direct_file, index_array, lines_count);

    // сортировка справа налево
    BubbleSort (index_array, lines_count, ReverseCmp);
    PrintInFile(reversed_file, index_array, lines_count);

    // оригинальный текст
    BubbleSort (index_array, lines_count, PointersCmp);
    PrintInFile(copy_file, index_array, lines_count);

    free(buffer);
    free(index_array);
    return 0;
}
