//
//  main.c
//  Tree
//
//  Created by 基炜 鲍 on 15/5/10.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include <stdio.h>
#include "AVLTree.h"
#include "SplayTree.h"
#include "IdealBalanceTree.h"
void testAVLTree();
void testSplayTree();
void testIdealTree();
int main(int argc, const char * argv[]) {
    // insert code here...
    //testAVLTree();
    //testSplayTree();
    testIdealTree();
    return 0;
}

void testAVLTree(){
    AVLTree T;
    T=insertNode(10, T);
    T=insertNode(6, T);
    T=insertNode(15, T);
    T=insertNode(8, T);
    T=insertNode(3, T);
    //printTree(T);
    T=deleteNode(15, T);
    
    T=insertNode(1, T); // left single rotate passed!!!
    T=insertNode(20, T);
    T=insertNode(25, T);// right single rotate passed!!!
    T=insertNode(18, T);// right double rotate passed!!!
    T=insertNode(16, T);
    T=deleteNode(16, T);
    T=deleteNode(8, T);
    T=deleteNode(18, T);// delete passed!!!
    printTree(T);
    
    T=insertNode(17, T);// left double rotate passed!!!
    T=insertNode(20, T);// repeated node igored!!!
    T=makeEmpty(T);// make empty passed!!!
    printf("%d\n",retrieve(findMin(T)));// findMax passed!!!
    printf("%d\n",retrieve(findMax(T)));// findMin passed!!!
    printTree(T);
    
}

void testSplayTree(){
    SplayTree T;
    T=insertSNode(5, T);
    T=insertSNode(2, T);
    T=insertSNode(82, T);
    T=insertSNode(15, T);
    T=insertSNode(9, T);
    T=deleteSNode(5, T);
    printTreeInPreorder(T);
}

void testIdealTree(){
    biTree T=createIdealTree(4);
    printIdealTree(T);
}