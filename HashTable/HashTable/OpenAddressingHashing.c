//
//  OpenAddressingHashing.c
//  HashTable
//
//  Created by 基炜 鲍 on 15/6/2.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include "OpenAddressingHashing.h"

oHashTable oInitialize(int tableSize){
    oHashTable H = malloc(sizeof(struct oHashTbl));
    if(H==NULL)
        printf("Out of memory!\n");
    H->tableSize=tableSize;
    H->cells = malloc(sizeof(struct oHashEntry)*H->tableSize);
    if(H->cells==NULL)
        printf("Out of memort!\n");
    for (int i=0; i<tableSize; i++) {
        H->cells[i].info = empty;
    }
    return H;
}

oPosition oFind(const char* keyVal, oHashTable H){
    int hashVal = oHash(keyVal,H->tableSize);
    int curPos = hashVal;
    while(H->cells[curPos].info!=empty){
        if(strcmp(H->cells[curPos].keyVal,keyVal)==0){
            if(H->cells[curPos].info==legitimate)
                return curPos;
            else
                break;
        }
        curPos=curPos*curPos;
        
        while(curPos>=H->tableSize)
            curPos=curPos-H->tableSize;
        if(curPos==hashVal)
            break;
    }
    return curPos;
}

void oInsert(const char* keyVal, oHashTable H){
    oPosition pos = oFind(keyVal, H);
    if(H->cells[pos].info!=legitimate){
        H->cells[pos].info=legitimate;
        H->cells[pos].keyVal=keyVal;
    }
}

void oDestroy(oHashTable H){
    free(H->cells);
    free(H);
}

const char* oRetrieve(oPosition pos, oHashTable H){
    return H->cells[pos].keyVal;
}

void oPrintHashTable(oHashTable H){
    for(int i=0;i<H->tableSize;i++){
        if(H->cells[i].info==legitimate)
            printf("CELL %d [%s] \n",i,H->cells[i].keyVal);
    }
}
int oHash(const char* keyVal,int tableSize){
    unsigned int hashVal=0;
    
    while(*keyVal!='\0')
        hashVal = (hashVal<<5)+ *keyVal++;
    return hashVal%tableSize;
    
}