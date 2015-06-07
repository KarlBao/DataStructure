//
//  BinaryHeap.h
//  PriorityHeap
//
//  Created by 基炜 鲍 on 15/6/7.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#ifndef __PriorityHeap__BinaryHeap__
#define __PriorityHeap__BinaryHeap__

#include <stdio.h>
#include <stdlib.h>
struct BinaryHeapStruct;
typedef struct BinaryHeapStruct* binaryHeap;

//@return: an initialized binary heap
binaryHeap initializeBHeap(int maxSize);

//@return: the min value;
int findMin(binaryHeap H);

//@return: the deleted minimum node value
int deleteMin(binaryHeap H);

//insert value priority into the binary heap and keep the order
void insert(int priority, binaryHeap H);

//@return: the new slot position after percolating down
int percolateDown(int slotPos, int slotVal, binaryHeap H);

//@return: 1 if the heap is full
int isFull(binaryHeap H);

//@return: 1 if the heap is empty
int isEmpty(binaryHeap H);

struct BinaryHeapStruct{
    int* elements;
    int capacity;
    int size;
};
#endif /* defined(__PriorityHeap__BinaryHeap__) */
