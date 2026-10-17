#ifndef FILESS
#define FILESS

int   ReadFromFile  (const char* name,        char*** index_array, char** buffer);
void   FillIndexArray(char***     index_array, char**  buffer,      size_t size);
int    CountLines    (char**      buffer,      size_t  size);
size_t GetSize       (const char* name);
void    PrintInFile   (const char* name, char**  index_array, int    nlines);

#endif
