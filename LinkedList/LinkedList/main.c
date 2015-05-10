//
//  main.c
//  List
//
//  Created by 基炜 鲍 on 15/4/23.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include <stdio.h>
#include "linkedList.h"
#include "Polynomial.h"
#include "CursorList.h"
#include "JosephusProblem.h"
void testLink();
void testPolynomial();
void testCursorList();
void testTransPotato(int playersNum,int intervalTimes); // ex 3.10
void testFindEle();
int main(int argc, const char * argv[]) {
    
    //testLink();
    //testPolynomial();
    //testCursorList();
    //testTransPotato(15000,1);
    testFindEle();
    return 0;
}

void testLink(){
    List L=createList();
    Insert(8,L,L);
    Insert(15, L, L);
    Insert(19, L, L);
    Insert(3,L,L);
    Insert(5, L, L);
    Insert(9, L, L);
    PrintList(L);
    Delete(8, L);
    PrintList(L);
    if(IsLast(Find(15, L),L))
        printf("Is last.\n");
    else
        printf("Is not the last.\n");
    
    MakeEmpty(L);
    
    if(IsEmpty(L))
        printf("Empty\n");
    else
        printf("Not Empty\n");
}

void testPolynomial(){
    // set P1
    Polynomial P1 = createPolynomial();
    insertVar(5, 830, P1);
    insertVar(17, 517, P1);
    insertVar(9, 63, P1);
    insertVar(5, 0, P1);
    printPolynomial(P1);
    
    // set P2
    Polynomial P2 = createPolynomial();
    insertVar(63, 417, P2);
    insertVar(8, 63, P2);
    insertVar(1, 1, P2);
    printPolynomial(P2);
    
    // get sum
    Polynomial sum = createPolynomial();
    sum = addPolynomials(P1, P2);
    printPolynomial(sum);
}

void testCursorList(){
    initialize();
    CList CL = CursorAlloc();
    CInsert(5, CL,CL);
    CInsert(19, CL,CL);
    CInsert(7, CL,CL);
    CPrintList(CL);
    
    CDelete(7, CL);
    CPrintList(CL);
    
}

void testTransPotato(int playersNum,int intervalTimes){
    Position winner = transHotPotato(playersNum, intervalTimes);
    printf("Winner is player %d",winner->element);
}

void testFindEle(){
    List L=createList();
    initPlayers(L, 2000000);
    Position P;
    P=Find(1900000, L); // Never crash even do more than 2 million times search
    //P=recursiveFind(150000, L); // Crash when do more than 170000 times recursion
    printf("%d",P->element);
}

