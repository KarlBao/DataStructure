//
//  Polynomial.h
//  List
//
//  Created by 基炜 鲍 on 15/4/24.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#ifndef __List__Polynomial__
#define __List__Polynomial__

#include <stdio.h>
#include "linkedList.h"
typedef struct Node* PtrToNode;
typedef PtrToNode Polynomial;
typedef PtrToNode Variable;
#define ERR_NULL_POLY printf("Polynomial does not exist.\n")

//return: new empty Polynomial
Polynomial createPolynomial();

//@return: previous Variable node
Variable findPrev(Variable, Polynomial);

//Insert a new variable into polynomial with coefficient A and exponent B
void insertVar(int coe,int exp,Polynomial P);

//@return: sum of 2 Polynomials
Polynomial addPolynomials(Polynomial P1,Polynomial P2);

//@return: product of 2 Polynomials
Polynomial multiPolynomials(Polynomial P1,Polynomial P2);

//Print the Polynomial
void printPolynomial(Polynomial P);


#endif /* defined(__List__Polynomial__) */
