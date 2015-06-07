//
//  main.c
//  PriorityQueue
//
//  Created by 基炜 鲍 on 15/6/7.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include <stdio.h>
#include "BinaryHeap.h"
#include "algorithms.h"
void testBinaryHeap();
void testChooseProblem();

int main(int argc, const char * argv[]) {
    // insert code here...
    //testBinaryHeap();
    testChooseProblem();
    return 0;
}

void testBinaryHeap(){
    binaryHeap H = initializeBHeap(20);
    insert(8, H);
    insert(5,H);
    insert(9, H);
    insert(-9, H);
    insert(0, H);
    deleteMin(H);
    deleteMin(H);
    printf("%d\n",findMin(H));
    int arr[]={5,1,3,90,2,5,6,3,13,44,0,3};
    H=buildHeap(arr, sizeof(arr)/sizeof(int), 20);
    printf("%d\n",findMin(H));
}

void testChooseProblem(){
    int arr[]={5,1,3,90,2,5,6,3,13,44,0,3,7,6};
    int k = chooseProblem(5, arr, sizeof(arr)/sizeof(int));
    printf("%d\n",k);
}
