//
//  algorithms.c
//  PriorityQueue
//
//  Created by 基炜 鲍 on 15/6/7.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include "algorithms.h"

int chooseProblem(int k, int* arr, int arrSize){
    int Sk; // the K th maximum value in heap S
    
    binaryHeap S = buildHeap(arr, k, k+1);
    /**
    
     **/
    Sk=findMin(S);
    for(int i=k;i<arrSize;i++){
        //printf("compare %d with %d\n",arr[i],Sk);
        if(arr[i]>Sk){
            deleteMin(S);
            insert(arr[i], S);
            Sk=findMin(S);
        }
    }
    return Sk;
}