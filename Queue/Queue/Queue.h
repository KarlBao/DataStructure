//
//  Queue.h
//  Queue
//
//  Created by 基炜 鲍 on 15/4/26.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#ifndef __Queue__Queue__
#define __Queue__Queue__

#include <stdio.h>
#include "header.h"
#define ERROR(s) printf("Error: %s\n",s)
#define ERR_EMPTY_QUEUE ERROR("empty queue!")
#define ERR_FULL_QUEUE ERROR("the queue is full!")

struct queueRecord;
typedef struct queueRecord* queue;

// add an element at the end of queue
void enqueue(int X,queue Q);

// delete an element from the front of queue
void dequeue(queue Q);

// return: the next position of queue
int nextPos(int value,queue Q);
// @return: a new empty queue with size
queue createQueue(int maxSize);

// @return: the element at the front of queue
int front(queue Q);

// @return the element at the front of queue, and delete it from queue
int frontAndDequeue(queue Q);

// @return: 1 if empty
int isEmpty(queue Q);

// @return: 1 if full
int isFull(queue Q);

// dispose all elements in the queue
void disposeQueue(queue Q);

// print the queue
void printQueue(queue Q);
struct queueRecord{
    int capacity;
    int size;
    int front;
    int rear;
    int *array;
};
#endif /* defined(__Queue__Queue__) */
