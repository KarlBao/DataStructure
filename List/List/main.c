//
//  main.c
//  List
//
//  Created by 基炜 鲍 on 15/4/23.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include <stdio.h>
#include "linkedList.h"
int main(int argc, const char * argv[]) {
    
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
    //Position first=First(L);
    return 0;
}


