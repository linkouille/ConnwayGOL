#ifndef __GAMEOFLIFE_H__
#define __GAMEOFLIFE_H__
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct {
    bool ** board;
    int w;
    int h;
} gameBoard;


int nbrVoisin(gameBoard * gB,int x, int y);

gameBoard * initGoLEmpty(int w, int h);

gameBoard * initGoLRand(int w, int h, float p);

void computeRule(gameBoard * gB);

void freeGameboard(gameBoard * gB);

#endif // __GAMEOFLIFE_H__