//
//  main.c
//  HashTable
//
//  Created by 基炜 鲍 on 15/6/2.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include <stdio.h>
#include "SeperateChaining.h"
#include "OpenAddressingHashing.h"
void testSeperateChaining();
void testOpenAddressingHashing();
int main(int argc, const char * argv[]) {
    // insert code here...
    testSeperateChaining();
    //testOpenAddressingHashing();
    return 0;
}

void testSeperateChaining(){
    HashTable H=InitializeTable(20);
    InsertKey("FUCK", H);
    InsertKey("YOUR", H);
    InsertKey("Grandmother", H);
    InsertKey("And", H);
    InsertKey("YOUR", H);
    InsertKey("Grand-grandmother", H);
    InsertKey("LOL", H);
    printHashTable(H);
}

void testOpenAddressingHashing(){
    oHashTable H=oInitialize(20);
    oInsert("FUCK", H);
    oInsert("YOUR", H);
    oInsert("Grandmother", H);
    oInsert("And", H);
    oInsert("YOUR", H);
    oInsert("Grand-grandmother", H);
    oInsert("LOL", H);
    oPrintHashTable(H);
}
