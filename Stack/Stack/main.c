//
//  main.c
//  Stack
//
//  Created by 基炜 鲍 on 15/4/25.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include <stdio.h>
#include "StackArray.h"
#include "Calculator.h"
#define STACK_SIZE 10
void testStack();
void testCalc(String s);
int main(int argc, const char * argv[]) {
    //testStack();
    testCalc("32+8*(9+12)/3+2^2^3");
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

void testCalc(String s){
    stack mfStack = getMidFixStack(s);
    printCalcStack(mfStack);
    stack pfStack = getPostFixStack(mfStack);
    printCalcStack(pfStack);
    int result = calcPostFixExpr(pfStack);
    printf("Result: %d\n",result);
}
