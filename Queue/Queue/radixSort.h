//
//  radixSort.h
//  Queue
//
//  Created by 基炜 鲍 on 15/4/27.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//
        //******************************//
        //  Sort numbers from 0-999     //
        //  with three times scanning   //
        //  Time complexity is O(3N)    //
        //Disadvantage: high space cost //
        // Linked list is better choice //
        //******************************//
#ifndef __Queue__radixSort__
#define __Queue__radixSort__

#include <stdio.h>
#include "Queue.h"

int *radixSort(int* array,int length);

int calcPow(int base,int index);
queue* initQArr(int maxSize);
#endif /* defined(__Queue__radixSort__) */
