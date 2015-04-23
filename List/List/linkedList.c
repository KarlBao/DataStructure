//
//  linkedList.c
//  List
//
//  Created by 基炜 鲍 on 15/4/23.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include "linkedList.h"
#include <stdlib.h>
struct Node{
    int element;
    Position next;
};

List createList(){
    List header = malloc(sizeof(struct Node));
    header->element=0;
    header->next=NULL;
    return header;
}

Position First(List L){
    return L->next;
}

Position Find(int X, List L){
    for (Position node=L; node!=NULL; node=node->next) {
        if(node->element==X)
            return node;
    }
    return NULL;
}

Position FindPrevious(int X,List L){
    for (Position node=L; node->next!=NULL; node=node->next) {
        if (node->next->element==X) {
            return node;
        }
    }
    ERR_NULL_POSITION;
    return NULL;
}

void Insert(int X,List L, Position P){
    if (P!=NULL) {
        Position newNode = (Position)malloc(sizeof(struct Node));
        newNode->element=X;
        newNode->next=P->next;
        P->next=newNode;
    }
    else ERR_NULL_POSITION;
}

void Delete(int X,List L){
    Position preNode;
    if ((preNode=FindPrevious(X, L))!=NULL) {
        Position tempNode=preNode->next;
        preNode->next=tempNode->next;
        
        tempNode->element=0;
        tempNode->next=NULL;
        free(tempNode);
    }
}

int IsEmpty(List L){
    return First(L)==NULL;
}

int IsLast(Position P,List L){
    return (P!=NULL&&P->next==NULL);
}

List MakeEmpty(List L){
    Position firstNode;
    while ((firstNode=First(L))!=NULL){
        L->next=firstNode->next;
        
        firstNode->next=NULL;
        firstNode->element=0;
        free(firstNode);
    }
    return L;
}
void PrintList(List L){
    printf("The list is: ");
    for (Position node=First(L); node!=NULL; node=node->next) {
        printf("%d ",node->element);
    }
    printf("\n");
}