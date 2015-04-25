//
//  CursorList.h
//  LinkedList
//
//  Created by 基炜 鲍 on 15/4/25.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//
/****   Linked List without pointer ***/
#ifndef __LinkedList__CursorList__
#define __LinkedList__CursorList__

#include <stdio.h>
#include "include.h"

typedef int PtrToCursorNode;
typedef PtrToCursorNode CList;
typedef PtrToCursorNode CPosition;

#define ERR_NO_SPACE printf("Out of memory!\n")
#define ERR_NO_POSITION printf("Node not found\n")
void initialize();

// @return : allocate new space
CPosition CursorAlloc(void);

// free the space
void CursorFree(CPosition P);

// @return : position of previous node with value X, -1 if not found
CPosition CFindPrevious(int X,CList L);

// print out the list
void CPrintList(CList L);

// @return empty list
CList CMakeEmpty(CList L);

// delete node with value X
void CDelete(int X,CList L);

// insert new node
void CInsert(int X,CPosition P,CList L);


#endif /* defined(__LinkedList__CursorList__) */
