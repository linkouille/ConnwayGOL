#ifndef __GAMEOFLIFE_H__
#define __GAMEOFLIFE_H__
#pragma once

#include <stdlib.h>
#include <stdio.h>

#define MAX_NODE 1024

typedef struct {
    int x;
    int y;
} node;

typedef struct {
    int size;
    int indice;
    node * array;

} Nodes;

Nodes * createNodes();

void freeNodes(Nodes * nodes);

void addNode(node node, Nodes * gB);

void addNodei(int x, int y, Nodes * gB);

void deleteNode(int x, int y, Nodes * gB);

node * getNode(int x, int y, Nodes * gB);

#endif // __GAMEOFLIFE_H__