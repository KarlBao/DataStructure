//
//  JosephusProblem.h
//  LinkedList
//
//  Created by 基炜 鲍 on 15/4/26.
//  Copyright (c) 2015年 基炜 鲍. All rights reserved.
//

#ifndef __LinkedList__JosephusProblem__
#define __LinkedList__JosephusProblem__

#include <stdio.h>
#include "include.h"
#include "linkedList.h"

//@return: position of winner
Position transHotPotato(int playersNum,int intervalTimes);

//initialize the player list
void initPlayers(List L, int playersNum);

//@return: position of next loser
Position findLoser(List L,int intervalTimes,Position startPos);

//@return: next player's position according to rule of circular list
Position findNextPlayer(Position P,List L);
#endif /* defined(__LinkedList__JosephusProblem__) */
