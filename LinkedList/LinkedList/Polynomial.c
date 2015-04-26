//
//  Polynomial.c
//  List
//
//  Created by 基炜 鲍 on 15/4/24.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include "Polynomial.h"



Polynomial createPolynomial(){
    return malloc(sizeof(struct Node));
}

Variable findPrev(Variable var,Polynomial P){
    if (var) {
        for (Variable node=P; node->next!=NULL; node=node->next) {
            if (node->next==var) {
                return node;
            }
        }
    }
    else ERR_NULL_POSITION;
    return NULL;
}
void insertVar(int coe,int exp,Polynomial P){
    if (P!=NULL){
        Variable newVar = malloc(sizeof(struct Node));
        newVar->coefficient=coe;
        newVar->exponent=exp;
        if (P->next==NULL) {
            P->next=newVar;
        }
        else{
            for (Variable node=P->next; node!=NULL; node=node->next) {
                if (node->exponent <= coe) {
                    Variable prev = findPrev(node, P);
                    newVar->next = node;
                    if(prev)
                        prev->next=newVar;
                    else
                        ERR_NULL_POSITION;
                    break;
                }
                else if(node->next==NULL){
                    node->next=newVar;
                    break;
                }
            }
        }
    }
    else ERR_NULL_POLY;
}

Polynomial addPolynomials(Polynomial P1,Polynomial P2){
    Polynomial result = createPolynomial();
    if (P1&&P2) {
        Variable var1,var2;
        Variable *lastNode = &result; // remember the address of last node of result
        for (var1=P1->next, var2=P2->next; var1!=NULL || var2!=NULL;) {
            if (!var1){
                (*lastNode)->next=var2;
                var2=var2->next;
            }
            else if (!var2){
                (*lastNode)->next=var1;
                var1=var1->next;
            }
            else if (var1->exponent>var2->exponent){
                (*lastNode)->next = var1;
                var1=var1->next;
            }
            else if(var1->exponent<var2->exponent){
                (*lastNode)->next = var2;
                var2=var2->next;
            }
            else if (var1->exponent==var2->exponent){
                Variable tempVar = malloc(sizeof(struct Node));
                tempVar->coefficient = var1->coefficient+var2->coefficient;
                tempVar->exponent = var1->exponent;
                (*lastNode)->next = tempVar;
                var1=var1->next;
                var2=var2->next;
            }
            lastNode = &(*lastNode)->next;
        }
        return result;
    }
    else ERR_NULL_POLY;
    return NULL;
}


void printPolynomial(Polynomial P){
    printf("P = ");
    if (P->next==NULL)
        printf("0\n");
    else{
        for (Variable node=P->next; node!=NULL; node=node->next) {
            printf("%dX^%d",node->coefficient,node->exponent);
            if (node->next!=NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}