//
//  IdealBalanceTree.h
//  Tree
//
//  Created by 基炜 鲍 on 15/5/31.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//
/********************
 ** This exercise is to generate an absolute balanced binary tree
 ** with nodes from 1 to 2^(H+1)-1
 ********************/
 
#ifndef __Tree__IdealBalanceTree__
#define __Tree__IdealBalanceTree__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct treeNode;
typedef struct treeNode* biTree;
typedef struct treeNode* biPos;

//@return: an ideal tree with height H
biTree createIdealTree(int height);

//@return: a sub-tree with specific minimum and maximum value
biTree generateTree(int min, int max, biTree T);

//print tree in inorder
void printIdealTree(biTree T);


#endif /* defined(__Tree__IdealBalanceTree__) */
