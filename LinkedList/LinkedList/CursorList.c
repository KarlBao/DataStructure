//
//  CursorList.c
//  LinkedList
//
//  Created by 基炜 鲍 on 15/4/25.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include "CursorList.h"
#define MAX_SPACE 10
struct cursorNode{
    int element;
    CPosition next;
};

struct cursorNode cursorSpace[MAX_SPACE+1]; // cursorSpace[0] is used to assign the next usable node

void initialize(){
    for (int i=0; i<MAX_SPACE+1; i++) {
        cursorSpace[i].next=i==MAX_SPACE?0:i+1;
    }
}

CPosition CursorAlloc(){
    CPosition P;
    if(cursorSpace[0].next!=0){
        P = cursorSpace[0].next;
        cursorSpace[0].next = cursorSpace[P].next;
        cursorSpace[P].next = 0;
        return P;
    }
    else{
        ERR_NO_SPACE;
        return 0;
    }
}

void CursorFree(CPosition P){
    cursorSpace[P].next = cursorSpace[0].next;
    cursorSpace[0].next = P;
}

CPosition CFindPrevious(int X,CList L){
    int i=L;
    while (cursorSpace[i].next!=0) {
        if (cursorSpace[cursorSpace[i].next].element==X) {
            return i;
        }
    }
    ERR_NO_POSITION;
    return -1; // 0 could be the previous node
}
void CInsert(int X,CPosition P,CList L){
    CPosition newNode = CursorAlloc();
    if (newNode) {
        cursorSpace[newNode].element=X;
        cursorSpace[newNode].next=cursorSpace[P].next;
        cursorSpace[P].next=newNode;
    }
}

void CDelete(int X, CList L){
    CPosition prevNode = CFindPrevious(X, L);
    if (prevNode!=-1) {
        CPosition tempNode=cursorSpace[prevNode].next;
        cursorSpace[prevNode].next = cursorSpace[tempNode].next;
        cursorSpace[tempNode].element=0;
        CursorFree(tempNode);
    }
}

void CPrintList(CList L){
    
    for (CPosition P = cursorSpace[L].next; P!=0; P=cursorSpace[P].next) {
        printf(" %d ",cursorSpace[P].element);
    }
    printf("\n");
}


