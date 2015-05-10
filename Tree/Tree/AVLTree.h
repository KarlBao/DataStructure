//
//  AVLTree.h
//  Tree
//
//  Created by 基炜 鲍 on 15/5/10.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#ifndef __Tree__AVLTree__
#define __Tree__AVLTree__

#include <stdio.h>
#include <stdlib.h>
struct AVLNode;
typedef struct AVLNode* AVLTree;
typedef struct AVLNode* AVLPos;

//@return: the empty avl tree
AVLTree makeEmpty(AVLTree T);

//@return: position of specific element X in tree T
AVLPos find(int x,AVLTree T);

//@return: position of the minumum element in tree T
AVLPos findMin(AVLTree T);

//@return: position of the maximum element in tree T
AVLPos findMax(AVLTree T);

//@return: the new AVL tree after inserting an element X
AVLTree insertNode(int x, AVLTree T);

//@return: the new avl tree after deleting the element X
AVLTree deleteNode(int x,AVLTree T);

//@return: the tree after single left rotate
AVLTree singleRotateLeft(AVLTree T);

//@return: the tree after double left rotate
AVLTree doubleRotateLeft(AVLTree T);

//@return: the tree after single right rotate
AVLTree singleRotateRight(AVLTree T);

//@return: the tree after double right rotate
AVLTree doubleRotateRight(AVLTree T);

//print the AVL tree in inorder travesal
void printTree(AVLTree T);
//@return: value of the specific node
int retrieve(AVLPos pos);

//@return: height of the node
int getHeight(AVLPos pos);

//@return: the max value
int max(int x, int y);
struct AVLNode{
    int ele;
    AVLPos lNode;
    AVLPos rNode;
    int height;
};
#endif /* defined(__Tree__AVLTree__) */
