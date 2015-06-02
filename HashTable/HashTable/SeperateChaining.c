//
//  SeperateChaining.c
//  HashTable
//
//  Created by 基炜 鲍 on 15/6/2.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include "SeperateChaining.h"

int Hash(const char* key, int tableSize){
    unsigned int HashVal=0;
    while(*key!='\0')
        HashVal = (HashVal<<5) + *key++;
    return HashVal%tableSize;
}

HashTable InitializeTable(int TableSize){
    HashTable hashTable = malloc(sizeof(struct HashTbl));
    if(hashTable==NULL)
        printf("Out of memory!\n");
    hashTable->tableSize=TableSize;
    hashTable->Lists=malloc(sizeof(hashTable->tableSize * sizeof(List)));
    if(hashTable->Lists==NULL)
        printf("Out of memory!\n");
    for (int i=0; i<hashTable->tableSize; i++) {
        hashTable->Lists[i] = malloc(sizeof(struct ListNode));
        hashTable->Lists[i]->next=NULL;
        if(hashTable->Lists[i]==NULL)
            printf("Out of memory!\n");
    }
    return hashTable;
}

Position Find(const char* key, HashTable H){
    int hashVal=Hash(key, H->tableSize);
    Position pos = H->Lists[hashVal]->next;
    
    while(pos!=NULL&&pos->keyVal!=NULL && strcmp(pos->keyVal,key)!=0)
        pos=pos->next;
    return pos;

}

void InsertKey(const char* key, HashTable H){
    if(Find(key, H)==NULL){
        Position newKey = malloc(sizeof(struct ListNode));
        newKey->keyVal=key;
        //insert the new key to the beginning of list
        int hashVal = Hash(key,H->tableSize);
        Position temp=H->Lists[hashVal]->next;
        newKey->next=temp;
        H->Lists[hashVal]->next=newKey;
    }
}

void DestroyTable(HashTable H){
    for (int i=0; i<H->tableSize; i++) {
        H->Lists[i]=NULL;
        free(H->Lists[i]);
    }
    free(H->Lists);
    free(H);
}

const char* Retrieve(Position pos){
    return pos->keyVal;
}

void printHashTable(HashTable H){
    for (int i = 0; i<H->tableSize; i++) {
        Position pos=H->Lists[i]->next;
        printf("LINE %d: ",i);
        while(pos!=NULL&&pos->keyVal!=NULL){
            printf(" [%s] ",Retrieve(pos));
            pos=pos->next;
        }
        printf("\n");
    }
}
