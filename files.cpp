#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>

#include "files.h"

// macros ERROR
int ReadFromFile(const char* name, char*** index_array, char** buffer)
{
    // запись размера файла
    struct stat st;
    FILE* file;
    stat(name, &st);
    size_t size = st.st_size;
    assert(size != 0);
    // создание буфера
    *buffer = (char*)calloc(size + 1, sizeof(char));
    if (*buffer == 0)
    {

        // printf("Error: calloc returned 0 in file: %d in line %d",
        // __FILE__, __LINE__);
        // abort();
    }

    // открытие файла и заполнение буфера
    file = fopen(name, "r");
    if (file == 0)
    {
        printf("Error: calloc returned 0 in file: %d in line %d",
        __FILE__, __LINE__);
        return -1;
    }
    fread(*buffer, sizeof(char), size, file);

    // подсчет строк в файле
    // СДЕЛАТЬ НОВУЮ ФУЦНКИЮ!!!
    char sym = 0;
    int line_count = 0;
    for (long long buf_idx = 0; buf_idx < size; buf_idx++)
    {
        sym = (*buffer)[buf_idx];
        assert(sym != '\r');
        if (sym == '\n')
        {
            line_count++;
            (*buffer)[buf_idx] = '\0';
        }
    }

    // создание массива указателей
    *index_array = (char**)calloc(line_count + 1, sizeof(char*));
    if (*index_array == 0)
    {
        printf("Error: calloc returned 0 in file: %d in line %d",
        __FILE__, __LINE__);
        abort();

    }
    char** array = *index_array
    // заполнение массива указателей

    array[0] = *buffer;
    int line_idx = 1;
    for (long long buf_idx = 1; buf_idx < size; buf_idx++)
    {
        sym = (*buffer)[buf_idx];
        if (sym == '\0')
        {
            array[line_idx] = (*buffer) + buf_idx + 1;
            line_idx++;
        }
    }

    // закрытие файла
    fclose(file);
    return line_count;
}

void PrintInFile(const char* name, char** index_array, int nlines)
{
    assert(name != nullptr);
    assert(index_array != nullptr);
    // открытие файла
    FILE* fp = fopen(name, "w");
    assert(fp != 0);

    // вывод в файл
    for (int line = 0; line < nlines; line++)
    {
        fputs(index_array[line], fp);
        putc('\n', fp);
    }
    fclose(fp);
}
