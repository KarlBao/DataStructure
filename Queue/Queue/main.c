//
//  main.c
//  Queue
//
//  Created by 基炜 鲍 on 15/4/26.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include <stdio.h>
#include "Queue.h"

void testQueue();
int main(int argc, const char * argv[]) {
    
    testQueue();
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