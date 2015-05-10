//
//  radixSort.c
//  Queue
//
//  Created by 基炜 鲍 on 15/4/27.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include "radixSort.h"

int *radixSort(int* array,int length){
    queue *digitsQArr = initQArr(length);
    int digit = 0;
    
    //Firstly, enqueue the numbers into different queues according to digits
    for (int i=0; i<length; i++) {
        digit = array[i]%10;
        enqueue(array[i], digitsQArr[digit]);
    }
    
    //get the numbers from queues and enqueue again according to next digit
    queue *curQArr=digitsQArr;
    int times=2; // do two more times. This number is flexible
    for (int j=10; j<=calcPow(10, times); j*=10) {
        queue *nextQArr=initQArr(length);
        int number;
        for (int i=0; i<10; i++) {
            while (!isEmpty(curQArr[i])) {
                number = frontAndDequeue(curQArr[i]);
                enqueue(number, nextQArr[(number/j)%10]);
            }
        }
        curQArr = nextQArr;
    }
    
    int result;
    int ai=0;
    for (int i=0; i<10; i++) {
        while (!isEmpty(curQArr[i])) {
            result = frontAndDequeue(curQArr[i]);
            array[ai]=result;
            ai++;
        }
    }
    return array;
}

queue* initQArr(int maxSize){
    queue* arr=malloc(10*sizeof(struct queueRecord));
    for (int i=0; i<10; i++) {
        arr[i]=createQueue(maxSize);
    }

    return arr;
}

int calcPow(int base,int index){
    for (int i=1; i<index; i++) {
        base*=base;
    }
    return base;
}