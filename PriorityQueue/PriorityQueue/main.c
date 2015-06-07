//
//  main.c
//  PriorityQueue
//
//  Created by 基炜 鲍 on 15/6/7.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include <stdio.h>
#include "BinaryHeap.h"

void testBinaryHeap();

int main(int argc, const char * argv[]) {
    // insert code here...
    testBinaryHeap();
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
    printf("%d",findMin(H));
}
