#ifndef FILELIST_METHOD_H
#define FILELIST_METHOD_H
#include "FileList_main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createEmptyFileList(FILELISTPTR* headPtrPtr, FILELISTPTR* lastPtrPtr);

FILELISTPTR findFileNodePtr(FILELISTPTR headPtr, char* fileName);

void moveHistoryFileToFirst(FILELISTPTR* headPtrPtr, FILELISTPTR* lastPtrPtr, char* fileName);

void addHistoryFile(FILELISTPTR* headPtrPtr, FILELISTPTR* lastPtrPtr, FILELISTPTR newPtr);

void RemoveBoundaryInvalid(FILELISTPTR* headPtrPtr, FILELISTPTR* lastPtrPtr);

FILELISTPTR goBackToPreviousFile(FILELISTPTR* headPtrPtr, FILELISTPTR* lastPtrPtr, char* fileName);

FILELISTPTR goForwardToNextFile(FILELISTPTR* headPtrPtr, FILELISTPTR* lastPtrPtr, char* fileName);

void printHistoryFileList(FILELISTPTR headPtr);

void freeFileList(FILELISTPTR* headPtrPtr);

#endif // FILELIST_METHOD_H
