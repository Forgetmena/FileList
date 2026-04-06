#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileList_Method.h"
#include "FileList_Menu.h"

struct FileList
{
    char* fileName;
    struct FileList* prevPtr;
    struct FileList* nextPtr;
};

typedef struct FileList FILELIST;
typedef struct FileList* FILELISTPTR;