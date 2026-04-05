#include "FileList_main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createEmptyFileList(FILELISTPTR* headPtrPtr);

FILELISTPTR findFileNodePtr(FILELISTPTR headPtr, char* fileName);

void moveHistoryFileToFirst(FILELISTPTR* headPtrPtr, char* fileName);