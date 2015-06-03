//
//  OpenAddressingHashing.h
//  HashTable
//
//  Created by 基炜 鲍 on 15/6/2.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#ifndef __HashTable__OpenAddressingHashing__
#define __HashTable__OpenAddressingHashing__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct oHashEntry;
struct oHashTbl;
typedef struct oHashEntry Cell;
typedef struct oHashTbl* oHashTable;
typedef int oPosition;
enum KindOfEntry {legitimate,empty,deleted};

//@return: the position of specific key
oPosition oFind(const char* keyVal, oHashTable H);

//@return: an initialized hash table
oHashTable oInitialize(int tableSize);

//insert the key to the hash table
void oInsert(const char* keyVal, oHashTable H);

//destroy the hash table
void oDestroy(oHashTable H);

//@return: value of the key
const char* oRetrieve(oPosition pos, oHashTable H);
struct oHashTbl{
    int tableSize;
    Cell* cells;
};

//@return: the hash value
int oHash(const char* keyVal,int tableSize);

//print the hash table
void oPrintHashTable(oHashTable H);

struct oHashEntry{
    const char* keyVal;
    enum KindOfEntry info;
};
#endif /* defined(__HashTable__OpenAddressingHashing__) */
