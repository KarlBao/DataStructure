//
//  algorithms.h
//  PriorityQueue
//
//  Created by 基炜 鲍 on 15/6/7.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#ifndef __PriorityQueue__algorithms__
#define __PriorityQueue__algorithms__

#include <stdio.h>
#include "BinaryHeap.h"
/**
 *@brief The complexity is O(N*logN);
 *@return: the kth maximum value in arr
 *@param k the sequence number of maximum elements to get
 *@param arr the array to choose from
 *@param arrSize the size of array
 */
 int chooseProblem(int k, int *arr, int arrSize);

#endif /* defined(__PriorityQueue__algorithms__) */
