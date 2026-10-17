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
    size_t size = GetSize(name);
    // открытие файла
    FILE* file = fopen(name, "r");
    if (file == 0)
    {
        printf("Error: calloc returned 0 in file: %d in line %d", __FILE__, __LINE__);
        return -1;
    }
    // создание буфера и массива с указателями
    *buffer = (char*)calloc(size + 1, sizeof(char));
    if (*buffer == 0)
    {
        printf("Error: calloc returned 0 in file: %d in line %d", __FILE__, __LINE__);
        return -1;
    }
    // заполнение буфера
    fread(*buffer, sizeof(char), size, file);
    // подсчет строк в файле
    int lines_count = CountLines(buffer, size);
    *index_array = (char**)calloc(lines_count + 1, sizeof(char*));
    if (*index_array == 0)
    {
        printf("Error: calloc returned 0 in file: %d in line %d", __FILE__, __LINE__);
        return -1;
    }
    // заполнение массива с указателями
    FillIndexArray(index_array, buffer, size);
    // закрытие файла
    fclose(file);
    return lines_count;
}

size_t GetSize(const char* name)
{
    struct stat st;
    stat(name, &st);
    return st.st_size;
}

int CountLines(char** buffer, size_t size)
{
    char sym = 0;
    int line_count = 0;
    for (long long buf_idx = 0; buf_idx < size; buf_idx++)
    {
        sym = *(*buffer + buf_idx);
        assert(sym != '\r');
        if (sym == '\n')
        {
            line_count++;
            *(*buffer + buf_idx) = '\0';
        }
    }
    return line_count;
}

void FillIndexArray(char*** index_array, char** buffer, size_t size)
{
    char sym = 0;
    (*index_array)[0] = *buffer;
    int line_idx = 1;
    for (long long buf_idx = 1; buf_idx < size; buf_idx++)
    {
        sym = *(*buffer + buf_idx);

        if (sym == '\0')
        {
            (*index_array)[line_idx] = *buffer + buf_idx + 1;
            line_idx++;
        }
    }
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
