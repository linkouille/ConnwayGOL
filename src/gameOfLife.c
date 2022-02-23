#include "gameOfLife.h"
#include "variables.h"

int nbrVoisin(gameBoard * gB,int x, int y){
    int out = 0;

    if( x-1 >= 0 && y+1 < gB->h && gB->board[x-1][y+1] ){
        out++;
    }if( y+1 < gB->h && gB->board[x][y+1] ){
        out++;
    }if( x+1 < gB->w &&  y+1 < gB->h && gB->board[x+1][y+1] ){
        out++;
    }if( x-1 >= 0 && gB->board[x-1][y] ){
        out++;
    }if( x+1 < gB->w && gB->board[x+1][y] ){
        out++;
    }if( x-1 >= 0 && y-1 >= 0 && gB->board[x-1][y-1] ){
        out++;
    }if( y-1 >= 0 && gB->board[x][y-1] ){
        out++;
    }if( x+1 < gB->w && y-1 >= 0 && gB->board[x+1][y-1] ){
        out++;
    }

    return out;
}

gameBoard * initGoLEmpty(int w, int h) 
{
    gameBoard * gB = malloc(sizeof(gameBoard));

    gB->board = malloc(sizeof(bool*) * h);
    for (size_t i = 0; i < h; i++)
    {
        gB->board[i] = malloc(sizeof(bool) * w);
    }
    gB->w = w;
    gB->h = h;

    for (size_t x = 0; x < w; x++)
    {
        for (size_t y = 0; y < h; y++)
        {
            gB->board[y][x] = false;
        }
        
    }


    return gB;
}

gameBoard * initGoLRand(int w, int h, float p) 
{
    gameBoard * gB = malloc(sizeof(gameBoard));

    gB->board = malloc(sizeof(bool*) * h);
    for (size_t i = 0; i < h; i++)
    {
        gB->board[i] = malloc(sizeof(bool) * w);
    }
    gB->w = w;
    gB->h = h;
    for (size_t x = 0; x < w; x++)
    {
        for (size_t y = 0; y < h; y++)
        {
            gB->board[y][x] = (((float)rand()) / RAND_MAX) < p;
        }
        
    }

    return gB;
}

void computeRule(gameBoard * gB) 
{
    int** voisins = (int **) malloc(sizeof(int*) * gB->h);
    for (size_t i = 0; i < gB->h; i++)
        voisins[i] = (int*)malloc(sizeof(int) * gB->w);

    for (size_t x = 0; x < gB->w; x++)
    {
        for (size_t y = 0; y < gB->h; y++)
        {
            voisins[y][x] = nbrVoisin(gB,x,y);
        }
    }

    for (size_t x = 0; x < gB->w; x++)
    {
        for (size_t y = 0; y < gB->h; y++)
        {
            int nbv = voisins[y][x];
            if(gB->board[x][y] == true){
                if(nbv < 2 || nbv > 3){
                    gB->board[x][y] = false;
                }
            }else{
                if(nbv == 3){
                    gB->board[x][y] = true;
                }
            }
        }
    }

    for (size_t i = 0; i < gB->h; i++)
        free(voisins[i]);
    free(voisins);


}

void freeGameboard(gameBoard * gB) 
{
    for (size_t i = 0; i < gB->h; i++)
    {
        free(gB->board[i]);
    }
    free(gB->board);

    free(gB);
}

