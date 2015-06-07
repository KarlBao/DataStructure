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
        int lastPos=H->size+1;
        percolateUp(lastPos, priorityVal, H);
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
int percolateUp(int slotPos, int slotVal, binaryHeap H){
    /* if slotPos==1, the inserted value will be the the root of heap */
    for(;slotPos!=1 && slotVal<=H->elements[slotPos/2];slotPos=slotPos/2){
        H->elements[slotPos]=H->elements[slotPos/2];
    }
    H->elements[slotPos]=slotVal;
    return slotPos;
}
int percolateDown(int slotPos, int slotVal, binaryHeap H){
    int childPos=0;
    if(isEmpty(H))
        return -1;
    for(;slotPos*2<=H->size;slotPos=childPos){
        childPos = (H->size>=slotPos*2+1 && H->elements[slotPos*2+1]<=H->elements[slotPos*2])?slotPos*2+1:slotPos*2;
        if(slotVal<=H->elements[childPos])
            break;
        H->elements[slotPos]=H->elements[childPos];
    }
    H->elements[slotPos]=slotVal;
    return slotPos;
}

binaryHeap buildHeap(int *arr, int arrSize, int maxHeapSize){
    if(arrSize+1>maxHeapSize)
        maxHeapSize=arrSize+1;
    binaryHeap H = initializeBHeap(maxHeapSize);
    H->size=arrSize;
    /* Note that H->elements[0] should be empty */
    for(int i=0;i<arrSize;i++)
        H->elements[i+1]=arr[i];
    for(int j=H->size/2;j>0;j--)
        percolateDown(j, H->elements[j], H);
    return H;
}
int isFull(binaryHeap H){
    return H->size==H->capacity;
}

int isEmpty(binaryHeap H){
    return H->size==0;
}