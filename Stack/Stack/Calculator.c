//
//  Calculator.c
//  Stack
//
//  Created by 基炜 鲍 on 15/4/26.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include "Calculator.h"

String pushUnit(String s,stack S){
    if(isDigit(*s)){
        int sum,i;
        i=1;
        sum=0;
        for (int d=0; isDigit(*s); s=++s,i*=10) {
            d=*s;
            sum=sum*i+(d-'0'); //calculate with 'real' number
        }
        push(sum+'0', S);
        return s;
    }
    else if(isOperation(*s)){
        push(*s, S);
        return ++s;
    }
    printf("Illegal expression!\n");
    return NULL;
}

int isDigit(int c){
    return c>='0'&&c<='9'?1:0;
}

int isOperation(int c){
    int opt[]={'+','-','*','/','(',')','^'};
    int length = sizeof(opt)/sizeof(opt[0]);
    for (int i=0; i<length; i++) {
        if(opt[i]==c)
            return 1;
    }
    return 0;
}

stack getMidFixStack(String s){
    stack mfStack = createStack(30);
    while (*s!='\0') {
        s=pushUnit(s,mfStack);
    }
    return getReverseStack(mfStack);
}

stack getPostFixStack(stack mfStack){
    stack pfStack = createStack(30);
    stack optStack = createStack(30);
    int c;
    while (!isEmpty(mfStack)) {
        c=topAndPop(mfStack);
        
        if(c==')'){
            while (top(optStack)!='(') {
                push(topAndPop(optStack), pfStack);
            }
            pop(optStack); // pop '('
        }
        else if (!isOperation(c)) {
            push(c, pfStack);
        }
        else if(isOperation(c)){
            while(!isEmpty(optStack)    // operator stack is not empty
                  &&top(optStack)!='(' // top of stack is not '('
                &&(getPriority(top(optStack))>getPriority(c) ||
                   (getPriority(top(optStack))==getPriority(c) && LEFT_TO_RIGHT(c))))
            {
                push(topAndPop(optStack), pfStack); // push the operation on top of stack into pf stack
            }
            push(c, optStack);  // push new operation into operation stack
        }
    }
    // mid-fixed stack is empty, push all operation into post-fixed stack
    while (!isEmpty(optStack)) {
        push(topAndPop(optStack), pfStack);
    }
    return getReverseStack(pfStack);
}

stack getReverseStack(stack S){
    stack rsStack = createStack(30);
    while (!isEmpty(S)) {
        push(topAndPop(S), rsStack);
    }
    return rsStack;
}

int calcPostFixExpr(stack pfStack){
    
    stack calcStack = createStack(30);
    int result=0;
    int firstNum,secNum;
    int top;
    while (!isEmpty(pfStack)) {
        top=topAndPop(pfStack);
        if(!isOperation(top))
            push(top,calcStack);
        else if (isOperation(top)){
            secNum=topAndPop(calcStack);
            firstNum=topAndPop(calcStack);
            if(firstNum&&secNum){
                result=doCalc(top,firstNum-'0',secNum-'0');
                push(result+'0', calcStack);    // push the ascii number to stack
            }
            else{
                printf("Illegal Expression!");
                return 0;
            }
        }
        else{
            printf("Illegal Expression!");
        }
    }
    return result;
}

int doCalc(int opt,int firstNum,int secNum){
    int result=1;
    switch (opt) {
        case '+':
            return firstNum+secNum;
            break;
        case '-':
            return firstNum-secNum;
            break;
        case '*':
            return firstNum*secNum;
            break;
        case '/':
            return firstNum/secNum;
            break;
        case '^':
            for(int i=0;i<secNum;i++){
                result*=firstNum;
            }
            return result;
            break;
        default:
            printf("Illegal Expression!");
            return 0;
            break;
    }
}
int getPriority(int opt){
    
    //  ( has priority of 100
    //  calculate from right to left if priority is from 51-99
    //  calculate from left to right if priority is from 1-50
    
    int priority=0;
    switch (opt) {
        case '+':
        case '-':
            priority = 10;
            break;
        case '*':
        case '/':
            priority = 11;
            break;
        case '(':
            priority = 100;
            break;
        case '^':
            priority = 60;
            break;
        default:
            break;
    }
    return priority;
}

void printCalcStack(stack S){
    for(int i=S->topOfStack;i>=0;i--) {
        printf("%c",(char)(S->array[i]));
    }
    printf("\n");
}