#include "FileList.h"

struct FileList
{
    char* fileNames;
    struct FileList* prevPtr;
    struct FileList* nextPtr;
};

typedef struct FileList FILELIST;
typedef struct FileList* FILELISTPTR;


