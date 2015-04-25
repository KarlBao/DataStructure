//
//  StackArray.h
//  Stack
//
//  Created by 基炜 鲍 on 15/4/25.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#ifndef __Stack__StackArray__
#define __Stack__StackArray__

#include <stdio.h>
#include "header.h"
#define EmptyTOS -1
#define MinStackSize 5
struct stackRecord;
typedef struct stackRecord* stack;

//@return: 1 if empty
int isEmpty(stack S);

//@return: 1 if full
int isFull(stack S);

//@return: new stack
stack createStack(int maxSize);

//dispose the stack
void disposeStack(stack S);

//push new element to the top
void push(int X,stack S);

//pop out the element from top of stack
void pop(stack S);

//@return: the element on top of stack
int top(stack S);

//@return: the element on top of stack and pop it out
int topAndPop(stack S);

void printStack(stack S);
#endif /* defined(__Stack__StackArray__) */

struct stackRecord{
    int topOfStack;
    int capacity;
    int *array;
};