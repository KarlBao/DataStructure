//
//  IdealBalanceTree.c
//  Tree
//
//  Created by 基炜 鲍 on 15/5/31.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include "IdealBalanceTree.h"

biTree createIdealTree(int height){
    biTree T;
    int max=pow(2, height+1)-1;
    T=generateTree(1, max, T);
    return T;
}
biTree generateTree(int min, int max, biTree T){
    T = malloc(sizeof(struct treeNode));
    if(max!=min){
        T->ele=(min+max)/2;
        T->lNode=generateTree(min, T->ele-1, T->lNode);
        T->rNode=generateTree(T->ele+1, max, T->rNode);
    }
    else{
        T->ele=min;
        T->lNode=T->rNode=NULL;
    }
        return T;
}

void printIdealTree(biTree T){
    if(T!=NULL){
        printIdealTree(T->lNode);
        printf(" %d ",T->ele);
        printIdealTree(T->rNode);
    }
}