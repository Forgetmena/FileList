#include "FileList_main.h"
#include "FileList_Method.h"

//创建一个空链表
void createEmptyFileList(FILELISTPTR* headPtrPtr) {
    (*headPtrPtr) = malloc(sizeof(FILELIST));
    if (*headPtrPtr == NULL) {
        printf("内存分配失败\n");
        return;
    }
    (*headPtrPtr)->fileName = NULL;
    (*headPtrPtr)->prevPtr = (*headPtrPtr);
    (*headPtrPtr)->nextPtr = (*headPtrPtr); 
}

//功能一：遍历函数，如果存在则返回该节点的指针，不存在则输出提示信息并返回headPtr
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
    printf("文件不存在\n");
    return headPtr;
}

//功能二：查看历史文件并且将文件提到第一位，并且删除原本的历史记录
void moveHistoryFileToFirst(FILELISTPTR* headPtrPtr, char* fileName) {
    FILELISTPTR currentPtr = findFileNodePtr((*headPtrPtr), fileName);
    if (currentPtr == (*headPtrPtr)) {
        return;
    }
    currentPtr->prevPtr->nextPtr = currentPtr->nextPtr;
    currentPtr->nextPtr->prevPtr = currentPtr->prevPtr;
    currentPtr->nextPtr = (*headPtrPtr)->nextPtr;
    (*headPtrPtr)->nextPtr->prevPtr = currentPtr;
    (*headPtrPtr)->nextPtr = currentPtr;
    currentPtr->prevPtr = (*headPtrPtr);
}

//功能三：添加历史文件，如果已经存在则调用功能二，如果不存在则添加到第一位
void addHistoryFile(FILELISTPTR* headPtrPtr, FILELISTPTR newPtr) {
    FILELISTPTR currentPtr = findFileNodePtr((*headPtrPtr), newPtr->fileName);
    if (currentPtr == (*headPtrPtr)) {
        newPtr->nextPtr = (*headPtrPtr)->nextPtr;
        (*headPtrPtr)->nextPtr->prevPtr = newPtr;
        (*headPtrPtr)->nextPtr = newPtr;
        newPtr->prevPtr = (*headPtrPtr);
    } 
}

//判断链表是否超出最大存储量10，如果超出则删除最后一个节点
void isBoundaryValid(FILELISTPTR* headPtrPtr) {
    int cnt = 0;
    FILELISTPTR currentPtr = (*headPtrPtr)->nextPtr;
    while (currentPtr != (*headPtrPtr)) {
        cnt++;
        currentPtr = currentPtr->nextPtr;
    } 
    if (cnt > 10) {
        FILELISTPTR lastPtr = (*headPtrPtr)->prevPtr;
        lastPtr->prevPtr->nextPtr = (*headPtrPtr);
        (*headPtrPtr)->prevPtr = lastPtr->prevPtr;
        free(lastPtr);
    }
    return; 
}