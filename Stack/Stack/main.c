//
//  main.c
//  Stack
//
//  Created by 基炜 鲍 on 15/4/25.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include <stdio.h>
#include "StackArray.h"
#define STACK_SIZE 10
void testStack();
int main(int argc, const char * argv[]) {
    testStack();
    return 0;
}

void testStack(){
    stack S = createStack(STACK_SIZE);
    pop(S);
    push(5, S);
    push(19, S);
    push(-5, S);
    printStack(S);
    pop(S);
    printStack(S);
    push(5, S);
    push(19, S);
    push(-5, S);
    push(5, S);
    push(19, S);
    push(-5, S);
    push(5, S);
    push(19, S);
    push(-5, S);
    printStack(S);
}
