//
//  Calculator.h
//  Stack
//
//  Created by 基炜 鲍 on 15/4/26.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//
/************************************************************************/
/*  This calculator is able to solve expressions with unsigned integers */
/*  Valid operators are + - * / () and ^                                */
/*  There is no robust error handle                                     */
/************************************************************************/

#ifndef __Stack__Calculator__
#define __Stack__Calculator__

#include <stdio.h>
#include "header.h"
#include "StackArray.h"

#define LEFT_TO_RIGHT(x) x<51?1:0   // calculate from right to left if priority is less than 50
typedef char* String;
typedef int Operation;
//@return: the postfixed expression according to the midfix expression
stack getPostFixStack(stack midFixStack);

//@return: the stack of expression
stack getMidFixStack(String expression);

//@return: a reverse stack
stack getReverseStack(stack S);
//@return: the string after pushing a variable or operation unit to stack S
String pushUnit(String expr,stack S);

//@return: the priority of operation, 0 if invalid
int getPriority(Operation opt);

//@return: 1 if this is a digit
int isDigit(int c);

//@return: 1 if this is a operation
int isOperation(int c);

//@return: value of expression
int calcPostFixExpr(stack postFixStack);

//@return the calculation result with 2 numbers and 1 operator
int doCalc(int opt,int firNum,int secNum);

//translate calculate stack from int to char and print
void printCalcStack(stack S);
#endif /* defined(__Stack__Calculator__) */
