//
//  main.c
//  Tree
//
//  Created by 基炜 鲍 on 15/5/10.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include <stdio.h>
#include "AVLTree.h"
void testAVLTree();
int main(int argc, const char * argv[]) {
    // insert code here...
    testAVLTree();
    return 0;
}

void testAVLTree(){
    AVLTree T;
    T=insertNode(10, T);
    T=insertNode(6, T);
    T=insertNode(15, T);
    T=insertNode(8, T);
    T=insertNode(3, T);
    T=insertNode(1, T); // left single rotate passed!!!
    T=insertNode(20, T);
    T=insertNode(25, T);// right single rotate passed!!!
    T=insertNode(18, T);// right double rotate passed!!!
    T=insertNode(16, T);
    T=insertNode(17, T);// left double rotate passed!!!
    T=insertNode(20, T);// repeated node igored!!!
    T=makeEmpty(T);// make empty passed!!!
    printf("%d\n",retrieve(findMin(T)));// findMax passed!!!
    printf("%d\n",retrieve(findMax(T)));// findMin passed!!!
    printTree(T);
    
}
