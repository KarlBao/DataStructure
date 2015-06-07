//
//  BinaryHeap.c
//  PriorityHeap
//
//  Created by 基炜 鲍 on 15/6/7.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include "BinaryHeap.h"

binaryHeap initializeBHeap(int maxSize){
    binaryHeap H = malloc(sizeof(struct BinaryHeapStruct));
    if(H==NULL)
        printf("OUT OF MEMORY!");
    H->elements = malloc(maxSize * sizeof(int));
    if(H->elements==NULL)
        printf("OUT OF MEMORY!");
    H->capacity=maxSize;
    H->size=0;
    return H;
}

int findMin(binaryHeap H){
    if(isEmpty(H))
        return -1;
    return H->elements[1];
}

void insert(int priorityVal, binaryHeap H){
    if(!isFull(H)){
        int slotPos=H->size+1;
        /* if slotPos==1, the inserted value will be the the root of heap */
        for(;slotPos!=1 && priorityVal<=H->elements[slotPos/2];slotPos=slotPos/2){
            H->elements[slotPos]=H->elements[slotPos/2];
        }
        H->elements[slotPos]=priorityVal;
        H->size++;
    }
}

int deleteMin(binaryHeap H){
    if(isEmpty(H))
        return -1;
    int min = findMin(H);
    int lastEle = H->elements[H->size];
    H->size--; // size will be reduced by 1 if an element is deleted
    percolateDown(1, lastEle, H);
    return min;
}

int percolateDown(int slotPos, int slotVal, binaryHeap H){
    int childPos=0;
    if(isEmpty(H))
        return -1;
    for(;slotPos*2<=H->size;slotPos=childPos){
        childPos = (H->size>=slotPos*2+1 && H->elements[slotPos*2]<=H->elements[slotPos*2+1])?slotPos*2:slotPos*2+1;
        if(slotVal<=H->elements[childPos])
            break;
        H->elements[slotPos]=H->elements[childPos];
    }
    H->elements[slotPos]=slotVal;
    return slotPos;
}

int isFull(binaryHeap H){
    return H->size==H->capacity;
}

int isEmpty(binaryHeap H){
    return H->size==0;
}