//
//  Queue.c
//  Queue
//
//  Created by 基炜 鲍 on 15/4/26.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include "Queue.h"

queue createQueue(int maxSize){
    queue newQueue = malloc(sizeof(struct queueRecord));
    newQueue->array = malloc(sizeof(int)*maxSize);
    newQueue->capacity=maxSize;
    newQueue->front=0;
    newQueue->rear=0;
    return newQueue;
}

void disposeQueue(queue Q){
    free(Q->array);
    free(Q);
}
int isEmpty(queue Q){
    return Q->size==0;
}

int isFull(queue Q){
    return Q->size==Q->capacity;
}

int nextPos(int value,queue Q){
    if(++value==Q->capacity)
        return 0;
    else
        return value;
}
void enqueue(int X,queue Q){
    if (!isFull(Q)) {
        Q->array[Q->rear]=X;
        Q->rear=nextPos(Q->rear, Q);
        Q->size++;
    }
    else
        ERR_FULL_QUEUE;
}

void dequeue(queue Q){
    if(!isEmpty(Q)){
        Q->front=nextPos(Q->front, Q);
        Q->size--;
    }
    else
        ERR_EMPTY_QUEUE;
}

int front(queue Q){
    if(!isEmpty(Q))
        return Q->array[Q->front];
    else
        ERR_EMPTY_QUEUE;
    return 0;
}

int frontAndDequeue(queue Q){
    int frontValue=front(Q);
    dequeue(Q);
    return frontValue;
}

void printQueue(queue Q){
    int curPos=Q->front;
    for (int i=Q->size; i>0; i--,curPos=nextPos(curPos, Q)) {
        printf(" %d ",Q->array[curPos]);
    }
    printf("\n");
}

