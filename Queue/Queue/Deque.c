//
//  Deque.c
//  Queue
//
//  Created by 基炜 鲍 on 15/4/29.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include "Deque.h"

void push(int X,queue D){
    if (!isFull(D)){
        D->array[prevPos(D->front, D)]=X;
        D->front=prevPos(D->front,D);
        D->size++;
    }
}

int pop(queue D){
    return frontAndDequeue(D);
}

int prevPos(int front,queue D){
    if (front==0)
        return D->capacity-1;
    return front-1;
}

void inject(int X,queue D){
    enqueue(X, D);
}

int eject(queue D){
    int rearVal=0;
    if (!isEmpty(D)) {
        rearVal=D->array[prevPos(D->rear, D)];
        D->rear=prevPos(D->rear, D);
        D->size--;
    }
    return rearVal;
}