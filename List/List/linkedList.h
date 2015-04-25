//
//  linkedList.h
//  List
//
//  Created by 基炜 鲍 on 15/4/23.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#ifndef __List__linkedList__
#define __List__linkedList__

#include <stdio.h>
#include <stdlib.h>
#define ERR_NULL_POSITION printf("Can not find the node\n");
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

//@return: an empty list
List MakeEmpty(List L);

//@return: 1 if empty, and 0 if not
int IsEmpty(List L);

//@return: 1 if last, and 0 if not
int IsLast(Position P, List L);

//@return: Position of X in L; NULL if not found
Position Find(int X, List L);

//Delete the node
void Delete(int X, List L);

//@return: The previous node position(pointer)
Position FindPrevious(int X, List L);

//Insert X after P
void Insert(int X,Position P,List L);

//Delete the list
void DeleteList(List L);

//@return: the first node of L
Position First(List L);

//@return: create an empty list and return the header
List createList(void);

//Print the list
void PrintList(List L);
#endif /* defined(__List__linkedList__) */
