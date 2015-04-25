//
//  StackArray.c
//  Stack
//
//  Created by 基炜 鲍 on 15/4/25.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include "StackArray.h"

stack createStack(int maxSize){
    stack S = malloc(sizeof(struct stackRecord));
    if (S) {
        S->array = malloc(sizeof(int)*maxSize);
        if (S->array) {
            S->capacity=maxSize;
            S->topOfStack=EmptyTOS;
            return S;
        }
    }
    perror("Out of memory\n");
    return NULL;
}

void disposeStack(stack S){
    if (S) {
        free(S->array);
        free(S);
    }
}

int isEmpty(stack S){
    return S->topOfStack==EmptyTOS;
}

int isFull(stack S){
    return S->topOfStack==S->capacity-1;
}

void push(int X,stack S){
    if(!isFull(S)){
        S->array[++S->topOfStack]=X;
    }
    else
        printf("Full stack\n");
}

void pop(stack S){
    if (!isEmpty(S)) {
        S->topOfStack--;
    }
    else
        printf("Empty stack\n");
}

int top(stack S){
    if(!isEmpty(S))
        return S->array[S->topOfStack];
    printf("Empty stack\n");
    return 0;
}

int topAndPop(stack S){
    int topValue;
    if (!isEmpty(S)) {
        topValue = top(S);
        pop(S);
    }
    else
        printf("Empty stack\n");
    return topValue;
}

void printStack(stack S){
    if (!isEmpty(S)) {
        for(int i=0;i<=S->topOfStack;i++){
            printf(" %d ",S->array[i]);
        }
        printf("\n");
    }
    else
        printf("Empty stack");
}