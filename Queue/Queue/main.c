//
//  main.c
//  Queue
//
//  Created by 基炜 鲍 on 15/4/26.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include <stdio.h>
#include "Queue.h"
#include "radixSort.h"
#include "Deque.h"
void testQueue();
void testRadixSort(int* array,int length);
void testDeque();
int main(int argc, const char * argv[]) {
    
    //testQueue();
    //int array[]={29,1,442,10,927,32,8,88,888,193,111,116};
    //testRadixSort(array,sizeof(array)/sizeof(int));
    testDeque();
    return 0;
}

void testQueue(){
    queue Q=createQueue(5);
    enqueue(3, Q);
    enqueue(19, Q);
    enqueue(1, Q);
    enqueue(0, Q);
    printQueue(Q);
    enqueue(5, Q);
    enqueue(99, Q);
    printQueue(Q);
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    printQueue(Q);
    enqueue(7, Q);
    printQueue(Q);
}

void testRadixSort(int* array,int length){
    int* result = radixSort(array,length);
    for (int i=0; i<length; i++) {
        printf(" %d ",result[i]);
    }
    printf("\n");
}

void testDeque(){
    queue D=createQueue(5);
    pop(D); //empty
    printQueue(D);
    push(2, D);
    push(19, D);
    printQueue(D);
    push(7, D);
    inject(22, D);
    inject(28, D);
    inject(1, D);
    eject(D);
    printQueue(D);
}