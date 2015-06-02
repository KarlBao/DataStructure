//
//  main.c
//  HashTable
//
//  Created by 基炜 鲍 on 15/6/2.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include <stdio.h>
#include "SeperateChaining.h"

void testSeperateChaining();
int main(int argc, const char * argv[]) {
    // insert code here...
    testSeperateChaining();
    return 0;
}

void testSeperateChaining(){
    HashTable H=InitializeTable(7);
    InsertKey("FUCK", H);
    InsertKey("YOUR", H);
    InsertKey("Grandmother", H);
    InsertKey("And", H);
    
    InsertKey("YOUR", H);
    InsertKey("Grand-grandmother", H);
    InsertKey("LOL", H);
    printHashTable(H);
}
