//
//  JosephusProblem.c
//  LinkedList
//
//  Created by 基炜 鲍 on 15/4/26.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#include "JosephusProblem.h"

Position transHotPotato(int playersNum,int intervalTimes){
    List L = createList();
    initPlayers(L, playersNum);
    Position startPos=L->next;
    Position loser;
    intervalTimes=intervalTimes%playersNum;
    while (!IsLast(First(L),L)) {
        loser=findLoser(L, intervalTimes, startPos);
        startPos=findNextPlayer(loser, L);
        printf("Player %d is out of game!\n",loser->element);
        Delete(loser->element, L);
    }
    return First(L);
}

void initPlayers(List L,int playersNum){
    for (; playersNum>0; playersNum--) {
        Insert(playersNum, L, L);
    }
}

Position findLoser(List L,int intervalTimes,Position startPos){
    Position curPos = startPos;
    for (; intervalTimes>0; intervalTimes--) {
        curPos=findNextPlayer(curPos, L);
    }
    return curPos;
}

Position findNextPlayer(Position P,List L){
    if (IsLast(P, L)) {
        return L->next;
    }
    return P->next;
}