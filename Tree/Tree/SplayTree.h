//
//  SplayTree.h
//  Tree
//
//  Created by 基炜 鲍 on 15/5/10.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#ifndef __Tree__SplayTree__
#define __Tree__SplayTree__

#include <stdio.h>
#include <stdlib.h>
struct SplayNode;
typedef struct SplayNode* SplayTree;
typedef struct SplayNode* SplayPosition;

//@return: new tree after inserting x into T
SplayTree insertSNode(int x,SplayTree T);

//@return: new tree after deleting x from T
SplayTree deleteSNode(int x,SplayTree T);

//@return: new restructured tree after visiting x into T
SplayTree visitNode(int x,SplayTree T);

//@return: new restructured tree after visiting the maximum value into T
SplayTree visitMax(SplayTree T);
//@return: the rotated tree
SplayTree doRotate(SplayPosition newRoot);
//@return: new tree after zig-zag left rotate
SplayTree zigzagLeftRotate(SplayPosition bottomNode);

//@return: new tree after zig-zag right rotate
SplayTree zigzagRightRotate(SplayPosition bottomNode);

//@return: new tree after zig-zig left rotate
SplayTree zigzigLeftRotate(SplayPosition bottomNode);

//@return: new tree after zig-zig right rotate
SplayTree zigzigRightRotate(SplayPosition bottomNode);

//@return: new tree after rotate the parent and its son on left side
SplayTree zigLeftRotate(SplayPosition bottomNode);

//@return: new tree after rotate the parent and its son on left side
SplayTree zigRightRotate(SplayPosition bottomNode);

void printTreeInPreorder(SplayTree T);

struct SplayNode{
    int ele;
    SplayPosition lNode;
    SplayPosition rNode;
    SplayPosition parent;
};
#endif /* defined(__Tree__SplayTree__) */
