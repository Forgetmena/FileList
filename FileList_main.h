#ifndef FILELIST_MAIN_H
#define FILELIST_MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FileList
{
    char* fileName;
    struct FileList* prevPtr;
    struct FileList* nextPtr;
};

typedef struct FileList FILELIST;
typedef struct FileList* FILELISTPTR;

#endif // FILELIST_MAIN_H
