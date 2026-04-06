#include "FileList_main.h"
#include "FileList_Method.h"

//创建一个空链表
void createEmptyFileList(FILELISTPTR* headPtrPtr, FILELISTPTR* lastPtrPtr) {
    (*headPtrPtr) = malloc(sizeof(FILELIST));
    if (*headPtrPtr == NULL) {
        printf("内存分配失败\n");
        return;
    }
    (*headPtrPtr)->fileName = NULL;
    (*headPtrPtr)->prevPtr = (*headPtrPtr);
    (*headPtrPtr)->nextPtr = (*headPtrPtr); 
    (*lastPtrPtr) = (*headPtrPtr);
}

//功能一：遍历函数，如果存在则返回该节点的指针，不存在则输出提示信息并返回NULL
FILELISTPTR findFileNodePtr(FILELISTPTR headPtr, char* fileName) {
    FILELISTPTR currentPtr = headPtr -> nextPtr;
    while (currentPtr != headPtr)
    {
        if (strcmp(currentPtr->fileName, fileName) == 0)
        {
            return currentPtr;
        }
        currentPtr = currentPtr->nextPtr;
    }
    return headPtr;
}

//功能二：查看历史文件并且将文件提到第一位（注意对lastPtr的处理）,并且删除原本的历史记录
void moveHistoryFileToFirst(FILELISTPTR* headPtrPtr, FILELISTPTR* lastPtrPtr, char* fileName) {
    FILELISTPTR currentPtr = findFileNodePtr((*headPtrPtr), fileName);
    if (currentPtr == (*headPtrPtr)) {
        return;
    }
    if (currentPtr == (*lastPtrPtr)) {
        (*lastPtrPtr) = currentPtr->prevPtr;
    }
    currentPtr->prevPtr->nextPtr = currentPtr->nextPtr;
    currentPtr->nextPtr->prevPtr = currentPtr->prevPtr;
    currentPtr->nextPtr = (*headPtrPtr)->nextPtr;
    (*headPtrPtr)->nextPtr->prevPtr = currentPtr;
    (*headPtrPtr)->nextPtr = currentPtr;
    currentPtr->prevPtr = (*headPtrPtr);
}

//功能三：添加历史文件，如果已经存在则调用功能二，如果不存在则添加到第一位
void addHistoryFile(FILELISTPTR* headPtrPtr, FILELISTPTR* lastPtrPtr, FILELISTPTR newPtr) {
    FILELISTPTR currentPtr = findFileNodePtr((*headPtrPtr), newPtr->fileName);
    if (currentPtr == (*headPtrPtr)) {
        newPtr->nextPtr = (*headPtrPtr)->nextPtr;
        (*headPtrPtr)->nextPtr->prevPtr = newPtr;
        (*headPtrPtr)->nextPtr = newPtr;
        newPtr->prevPtr = (*headPtrPtr);
        (*lastPtrPtr) = (*lastPtrPtr)->nextPtr;
        (*headPtrPtr)->prevPtr = (*lastPtrPtr);
    } else {
        moveHistoryFileToFirst(headPtrPtr, lastPtrPtr, newPtr->fileName);
    }
    RemoveBoundaryInvalid(headPtrPtr, lastPtrPtr);
}

//判断链表是否超出最大存储量10，如果超出则删除最后一个节点
void RemoveBoundaryInvalid(FILELISTPTR* headPtrPtr, FILELISTPTR* lastPtrPtr) {
    int cnt = 0;
    FILELISTPTR currentPtr = (*headPtrPtr)->nextPtr;
    while (currentPtr != (*headPtrPtr)) {
        cnt++;
        currentPtr = currentPtr->nextPtr;
    } 
    if (cnt > 10) {
        FILELISTPTR tempPtr = (*lastPtrPtr);
        (*lastPtrPtr) = (*lastPtrPtr)->prevPtr;
        (*lastPtrPtr)->nextPtr = (*headPtrPtr);
        (*headPtrPtr)->prevPtr = (*lastPtrPtr);
        free(tempPtr->fileName);
        free(tempPtr);
    }
    return; 
}