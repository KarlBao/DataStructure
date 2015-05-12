//
//  SplayTree.c
//  Tree
//
//  Created by 基炜 鲍 on 15/5/10.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include "SplayTree.h"

SplayTree insertSNode(int x, SplayTree T){
    // only possible in the empty tree
    if(T==NULL){
        T=malloc(sizeof(struct SplayNode));
        T->ele=x;
        T->lNode=T->rNode=NULL;
        T->parent=NULL;
    }
    else if(x<T->ele){
        if(T->lNode==NULL){
            T->lNode=malloc(sizeof(struct SplayNode));
            T->lNode->ele=x;
            T->lNode->lNode=T->lNode->rNode=NULL;
            T->lNode->parent=T;
            T=doRotate(T->lNode);
        }
        else
            T=insertSNode(x, T->lNode);
    }
    else if(x>T->ele){
        if(T->rNode==NULL){
            T->rNode=malloc(sizeof(struct SplayNode));
            T->rNode->ele=x;
            T->rNode->lNode=T->rNode->rNode=NULL;
            T->rNode->parent=T;
            T=doRotate(T->rNode);
        }
        else
            T=insertSNode(x, T->rNode);
    }
    else if(x==T->ele)
        T=doRotate(T);
    return T;
}

SplayTree deleteSNode(int x, SplayTree T){
    SplayTree newTree;
    if(T!=NULL){
        T=visitNode(x, T);
        SplayTree TL=T->lNode;
        SplayTree TR=T->rNode;
        
        TL->parent=TR->parent=NULL;
        T->lNode=T->rNode=NULL;
        free(T);
        
        TL=visitMax(TL);
        
        
        if(TL!=NULL){
            TL->rNode=TR;
            newTree=TL;
        }
        else
            newTree=TR;
    }
    return newTree;
}

SplayTree visitNode(int x,SplayTree T){
    if(T!=NULL){
        SplayPosition curNode=T;
        while(x!=curNode->ele&&(curNode->lNode!=NULL || curNode->rNode!=NULL)){
            if(x>curNode->ele)
                curNode=curNode->rNode;
            else if(x<curNode->ele)
                curNode=curNode->lNode;
        }
        T=doRotate(curNode);
    }
    return T;
}

SplayTree visitMax(SplayTree T){
    if(T!=NULL){
        SplayPosition curNode=T;
        while(curNode->rNode!=NULL)
            curNode=curNode->rNode;
        T=doRotate(curNode);
    }
    return T;
}
SplayTree doRotate(SplayPosition newNode){
    while (newNode->parent!=NULL) {
        if(newNode->ele>newNode->parent->ele){
            if(newNode->parent->parent==NULL)
                newNode=zigRightRotate(newNode);
            else if(newNode->parent->ele<newNode->parent->parent->ele)
                newNode=zigzagLeftRotate(newNode);
            else if(newNode->parent->ele>newNode->parent->parent->ele)
                newNode=zigzigRightRotate(newNode);
        }
        else if(newNode->ele < newNode->parent->ele){
            if (newNode->parent->parent==NULL)
                newNode=zigLeftRotate(newNode);
            else if(newNode->parent->ele > newNode->parent->parent->ele)
                newNode=zigzagRightRotate(newNode);
            else if(newNode->parent->ele < newNode->parent->parent->ele)
                newNode=zigzigLeftRotate(newNode);
        }
    }
    return newNode;
}

SplayTree zigzagLeftRotate(SplayPosition bottom){
    return zigLeftRotate(zigRightRotate(bottom));
}

SplayTree zigzagRightRotate(SplayPosition bottom){
    return zigRightRotate(zigLeftRotate(bottom));
}

SplayTree zigzigLeftRotate(SplayPosition bottom){
    zigLeftRotate(bottom->parent);
    return zigLeftRotate(bottom);
}

SplayTree zigzigRightRotate(SplayPosition bottom){
    SplayPosition midNode=zigRightRotate(bottom->parent);
    bottom = zigRightRotate(midNode->rNode);
    return bottom;
}

SplayTree zigLeftRotate(SplayPosition lowNode){
    SplayPosition highNode = lowNode->parent;
    lowNode->parent=highNode->parent;
    highNode->parent=lowNode;
    highNode->lNode=lowNode->rNode;
    lowNode->rNode=highNode;
    return lowNode; //new high node
}

SplayTree zigRightRotate(SplayPosition lowNode){
    SplayPosition highNode = lowNode->parent;
    lowNode->parent=highNode->parent;
    highNode->parent=lowNode;
    highNode->rNode=lowNode->lNode;
    lowNode->lNode=highNode;
    return lowNode; //new high node
}

void printTreeInPreorder(SplayTree T){
    if(T!=NULL){
        
        printTreeInPreorder(T->lNode);
        printf(" %d ",T->ele);
        printTreeInPreorder(T->rNode);
    }
}