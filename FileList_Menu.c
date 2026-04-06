#include "FileList_Menu.h"

void showMenu() {
    FILELISTPTR headPtr;
    FILELISTPTR lastPtr;
    createEmptyFileList(&headPtr, &lastPtr);
    int flag = 1;
    while (1) {
        printf("请选择操作：\n");
        printf("1. 打开文件\n");
        printf("2. 查看历史文件\n");
        printf("3. 返回上一个文件\n");
        printf("4. 前进到下一个文件\n");
        printf("5. 退出程序\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // 打开文件的操作
                printf("请输入要打开的文件名：\n");
                char fileName[100];
                scanf("%s", fileName);
                printf("打开文件：%s\n", fileName);
                printf("请输入要打开的文件名：\n");
                FILELISTPTR newPtr = malloc(sizeof(FILELIST));
                if (newPtr == NULL) {
                    printf("内存分配失败\n");
                    break;
                }
                newPtr->fileName = malloc((strlen(fileName) + 1) * sizeof(char));
                if (newPtr->fileName == NULL) {
                    printf("内存分配失败\n");
                    free(newPtr);
                    break;
                }
                strcpy(newPtr->fileName, fileName);
                // 将新节点添加到历史记录中
                addFileToList(&headPtr, &lastPtr, newPtr);
                break;
            case 2:
                // 查看历史文件的操作
                printHistoryFileList(headPtr);
                break;
            case 3:
                // 返回上一个文件的操作
                printf("请输入要返回的文件名：\n");
                scanf("%s", fileName);
                FILELISTPTR previousFilePtr = goBackToPreviousFile(&headPtr, &lastPtr, fileName);
                if (previousFilePtr != headPtr) {
                    printf("返回到上一个文件：%s\n", previousFilePtr->fileName);
                }
                break;
            case 4:
                // 前进到下一个文件的操作
                printf("请输入要前进的文件名：\n");
                scanf("%s", fileName);
                FILELISTPTR nextFilePtr = goForwardToNextFile(&headPtr, &lastPtr, fileName);
                if (nextFilePtr != headPtr) {
                    printf("前进到下一个文件：%s\n", nextFilePtr->fileName);
                }
                break;
            case 5:
                flag = 0;
                printf("退出程序\n");
                return;
            default:
                printf("无效的选择，请重新输入\n");
        }
        if (!flag) {
            break;
        }
    }
}