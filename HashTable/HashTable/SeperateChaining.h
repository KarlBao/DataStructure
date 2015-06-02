//
//  SeperateChaining.h
//  HashTable
//
//  Created by 基炜 鲍 on 15/6/2.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#ifndef __HashTable__SeperateChaining__
#define __HashTable__SeperateChaining__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct ListNode;
typedef struct ListNode* List;
typedef struct ListNode* Position;
struct HashTbl;
typedef struct HashTbl* HashTable;

//return: the hash value after
int Hash(const char* key, int TableSize);

//return: the position of the specific key in hash table
Position Find(const char* key, HashTable H);

//return: an initialized hash table
HashTable InitializeTable(int TableSize);

//insert the key into hash table
void InsertKey(const char* key, HashTable H);

//destroy the hash table
void DestroyTable(HashTable H);

//return: the value of specific key
const char* Retrieve(Position P);

//print the hash table
void printHashTable(HashTable H);
struct HashTbl{
    int tableSize;
    List* Lists;
};

struct ListNode{
    const char* keyVal;
    Position next;
};
#endif /* defined(__HashTable__SeperateChaining__) */
