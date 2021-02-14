#include "gameOfLife.h"

Nodes * createNodes(){
    Nodes * out = (Nodes *)malloc(sizeof(Nodes));
    out->size = MAX_NODE;
    out->indice = 0;
    out->array = (node *)malloc(sizeof(node) * MAX_NODE);

    return out;
}

void freeNodes(Nodes * nodes){

    if(nodes->array != NULL){
        free(nodes->array);
    }
    free(nodes);
}

void addNode(node node, Nodes * gB) 
{
    if(gB == NULL || gB->array == NULL){
        fprintf(stderr, "ERROR: NULL nodes pointer when adding");
        exit(-1);
    }

    if(gB->indice + 1 == gB->size){
        gB->size = gB->size * 2;

        gB->array = realloc( gB->array, sizeof(node)*gB->size );
    }

    gB->array[gB->indice] = node;
    gB->indice++;
}

void addNodei(int x, int y, Nodes * gB) 
{
    node n;
    n.x = x;
    n.y = y;
    addNode(n,gB);
}

void deleteNode(int x, int y, Nodes * gB) 
{
    if(gB == NULL || gB->array == NULL){
        fprintf(stderr, "ERROR: NULL nodes pointer when deleting");
        exit(-1);
    }

    for (size_t i = gB->indice - 1; i >= 0; i--)
    {
        if(gB->array[i].x == x && gB->array[i].y == y){
            for (size_t j = i; j < gB->indice; j++)
            {
                gB->array[j] = gB->array[j+1];
            }
            gB->indice--;
            return;

        }
    
    }
    
}

node * getNode(int x, int y, Nodes * gB) 
{
    if(gB == NULL || gB->array == NULL){
        fprintf(stderr, "ERROR: NULL nodes pointer when getting");
        exit(-1);
    }

    for (size_t i = gB->indice - 1; i >= 0; i--)
    {
        if(gB->array[i].x == x && gB->array[i].y == y){
            return &(gB->array[i]);
        }
    
    }

}

