# FileList

##  背景：

### 完成一个有关C语言的链表的任务

## 程序：

### 用C语言的链表有关知识，制作一个能够访问历史文件的程序，实现仿照WPS、IDE、浏览器等查看历史记录的功能；

>总体代码逻辑
```
1，在链表节点的结构体中定义文件，从而可以添加历史文件并且储存在链表中，通过对链表的增添节点、删减节点、移动节点等操作，实现模拟WPS查看历史记录文件的各项功能
2，链表应是双向环形链表，并且应有空节点在首节点作为哨兵节点
```

>功能一：能够查看历史文件，并且能够打开该文件
```
实现逻辑：通过获取需要访问的历史文件的地址（例如输入对应文件的名字、点击对应文件等），从而能够访问携带有该文件的链表节点，进而可以访问该文件
```

>功能二：查看相应的历史文件时，将该文件提前到历史记录的第一位，并且删除原本的历史记录
```
实现逻辑；为了节约内存，从而直接更改节点的prevPtr和nextPtr
```
`currentPtr->prevPtr->nextPtr = currentPtr->nextPtr;`  
`currentPtr->nextPtr->prevPtr = currentPtr->prevPtr`  
`currentPtr->nextPtr = headPtr->nextPtr;`   
`headPtr->nextPtr->prevPtr = currentPtr;`   
`headPtr->nextPtr = currentPtr;`  
`currentPtr->prevPtr = headPtr;`

>功能三：新添加文件时，若原链表有该文件，应该删除原有链表（历史记录）的文件，若没有文件，则应该添加文件
```
实现逻辑：通过遍历查看是否有该文件
情况一：当原链表有该文件时，可以转化为功能二
情况二：若没有该文件，应该在首节点（哨兵节点/headPtr）后增加一个新的节点，并附加判断是否超出历史记录最大存储数量的函数
```
`currentPtr->nextPtr = headPtr->nextPtr;`  
`headPtr->nextPtr->prevPtr = currentPtr;`  
`headPtr-.nextPtr = currentPtr;`  
`currentPtr->prevPtr = headPtr;`

>功能四；当处在历史记录的某一文档时，能够回到历史记录中上一个文档，以及到达历史记录中下一个文档，并附带有边界判断
```
实现逻辑；通过prevPtr和nextPtr实现该功能
```
 