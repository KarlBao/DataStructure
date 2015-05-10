//
//  Deque.h
//  Queue
//
//  Created by 基炜 鲍 on 15/4/29.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#ifndef __Queue__Deque__
#define __Queue__Deque__

#include <stdio.h>
#include "Queue.h"

//push X to the front of D
void push(int X,queue D);

//@return: dequeue and get the front of D
int pop(queue D);

//push X to the end of D
void inject(int X, queue D);

//@return: dequeue and get the end of D
int eject(queue D);

//@return: the previous position of current position
int prevPos(int front,queue D);
#endif /* defined(__Queue__Deque__) */
