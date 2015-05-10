//
//  AVLTree.c
//  Tree
//
//  Created by 基炜 鲍 on 15/5/10.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include "AVLTree.h"

// Postorder traversal
AVLTree makeEmpty(AVLTree T){
    if (T->lNode!=NULL)
        makeEmpty(T->lNode);
    if (T->rNode!=NULL)
        makeEmpty(T->rNode);
    free(T);
    return NULL;
}

AVLPos find(int x,AVLTree T){
    AVLPos pos = T;
    while(pos!=NULL){
        if(x>pos->ele)
            pos=pos->rNode;
        if(x<pos->ele)
            pos=pos->lNode;
        if(x==pos->ele)
            return pos;
    }
    return NULL;
}

AVLPos findMin(AVLTree T){
    AVLPos pos=T;
    if(T==NULL)
        return NULL;
    while(pos->lNode!=NULL)
        pos=pos->lNode;
    return pos;
}

AVLPos findMax(AVLTree T){
    AVLPos pos=T;
    if(T==NULL)
        return NULL;
    while(pos->rNode!=NULL)
        pos=pos->rNode;
    return pos;
}

AVLTree insertNode(int x,AVLTree T){
    
    if (T==NULL) {
        T=malloc(sizeof(struct AVLNode));
        T->ele=x;
        T->height=0;
        T->lNode=NULL;
        T->rNode=NULL;
    }
    else if(x<T->ele){
        T->lNode=insertNode(x, T->lNode);
        if(getHeight(T->lNode)-getHeight(T->rNode)==2){
            if(x<T->lNode->ele)
                T=singleRotateLeft(T);
            else if (x>T->lNode->ele)
                T=doubleRotateLeft(T);
        }
    }
    else if(x>T->ele){
        T->rNode=insertNode(x, T->rNode);
        if (getHeight(T->rNode)-getHeight(T->lNode)==2) {
            if(x>T->rNode->ele)
                T=singleRotateRight(T);
            else if(x<T->rNode->ele)
                T=doubleRotateRight(T);
        }
    }
    T->height=(getHeight(T->lNode)>getHeight(T->rNode)?getHeight(T->lNode):getHeight(T->rNode))+1;
    return T;
}

int retrieve(AVLPos pos){
    if(pos==NULL)
        return 0;
    return pos->ele;
}
void printTree(AVLTree T){
    if(T!=NULL){
        
        printTree(T->lNode);
        printf("element: %d ,height: %d\n",T->ele,T->height);
        printTree(T->rNode);
    }
}
AVLTree singleRotateLeft(AVLTree T){
    AVLPos tempNode=T;
    T=T->lNode;
    tempNode->lNode=T->rNode;
    T->rNode=tempNode;
    //reset the height of two rotated nodes
    tempNode->height=(getHeight(tempNode->rNode)>getHeight(tempNode->lNode)?
                      getHeight(tempNode->rNode):getHeight(tempNode->lNode))+1;
    T->height=(getHeight(T->lNode)>getHeight(T->rNode)?getHeight(T->lNode):getHeight(T->rNode))+1;
    return T;
}

AVLTree singleRotateRight(AVLTree T){
    AVLPos newRoot=T->rNode;
    T->rNode=newRoot->lNode;
    newRoot->lNode=T;
    //reset height of two rotated nodes
    newRoot->height=max(getHeight(newRoot->lNode),getHeight(newRoot->rNode))+1;
    T->height=max(getHeight(T->lNode), getHeight(T->rNode))+1;
    return newRoot;
}

AVLTree doubleRotateLeft(AVLTree T){
    AVLPos newRoot=T->lNode->rNode;
    T->lNode->rNode=newRoot->lNode;
    newRoot->lNode=T->lNode;
    T->lNode=newRoot->rNode;
    newRoot->rNode=T;
    newRoot->lNode->height=max(getHeight(newRoot->lNode->lNode), getHeight(newRoot->lNode->rNode))+1;
    newRoot->rNode->height=max(getHeight(newRoot->rNode->lNode), getHeight(newRoot->rNode->rNode))+1;
    newRoot->height=max(getHeight(newRoot->lNode), getHeight(newRoot->rNode));
    return newRoot;
}

AVLTree doubleRotateRight(AVLTree T){
    AVLPos newRoot=T->rNode->lNode;
    T->rNode->lNode=newRoot->rNode;
    newRoot->rNode=T->rNode;
    T->rNode=newRoot->lNode;
    newRoot->lNode=T;
    newRoot->lNode->height=max(getHeight(newRoot->lNode->lNode), getHeight(newRoot->lNode->rNode))+1;
    newRoot->rNode->height=max(getHeight(newRoot->rNode->lNode), getHeight(newRoot->rNode->rNode))+1;
    newRoot->height=max(getHeight(newRoot->lNode), getHeight(newRoot->rNode));
    return newRoot;
}

int getHeight(AVLPos pos){
    if(pos==NULL)
        return -1;
    else
        return pos->height;
}

int max(int x,int y){
    return x>y?x:y;
}