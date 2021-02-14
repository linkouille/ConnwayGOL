#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "gameOfLife.h"

#define TIMESTAMP 1

int main(int argc, char const *argv[])
{

    Nodes * gameBoard = createNodes();

    addNodei(0,0,gameBoard);
    addNodei(1,0,gameBoard);
    addNodei(0,1,gameBoard);

    bool gameLoop;

    while (gameLoop)
    {
        
        


        sleep(TIMESTAMP);
    }

    freeNodes(gameBoard);

    return 0;
}
