#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define TIMESTAMP 1
#define MAX_NODE 16

#define PROBA 0.5

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

bool gB[MAX_NODE][MAX_NODE];
bool gBtmp[MAX_NODE][MAX_NODE];

bool screenVoisin = false;

int nbrVoisin(int x, int y){
    int out = 0;

    if(gB[x-1][y+1]){
        out++;
    }if(gB[x][y+1]){
        out++;
    }if(gB[x+1][y+1]){
        out++;
    }if(gB[x-1][y]){
        out++;
    }if(gB[x+1][y]){
        out++;
    }if(gB[x-1][y-1]){
        out++;
    }if(gB[x][y-1]){
        out++;
    }if(gB[x+1][y-1]){
        out++;
    }

    return out;
}

int main(int argc, char const *argv[])
{
    for (size_t x = 0; x < MAX_NODE; x++)
    {
        for (size_t y = 0; y < MAX_NODE; y++)
        {
            gB[y][x] = false;
        }
        
    }

    //Init
    // gB[8][8] = true;
    // gB[8][7] = true;
    // gB[8][6] = true;

    // gB[9][8] = true;
    // gB[9][7] = true;
    // gB[9][9] = true;

    for (size_t x = 0; x < MAX_NODE; x++)
    {
        for (size_t y = 0; y < MAX_NODE; y++)
        {
            gB[y][x] = (((float)rand()) / RAND_MAX) < PROBA;
        }
        
    }

    for (size_t x = 0; x < MAX_NODE; x++)
    {
        for (size_t y = 0; y < MAX_NODE; y++)
        {
            gBtmp[y][x] = gB[y][x];
        }
        
    }

    bool gameLoop = true;
    
    system("clear");

    int itt = 0;

    while (gameLoop)
    {

        system("clear");
        printf("--------------------------- Turn %d ---------------------------\n", itt);
        for (size_t x = 0; x < MAX_NODE; x++)
        {
            for (size_t y = 0; y < MAX_NODE; y++)
            {
                if(gB[x][y]){
                    if(screenVoisin){
                        printf(KRED " %d " KWHT,nbrVoisin(x,y));

                    }else{
                        printf("#");
                    }
                }else{
                    if(screenVoisin){
                        printf(" %d ",nbrVoisin(x,y));
                    }else{
                        printf(".");

                    }

                }
            }
            printf("\n");
            
        }
        printf("------------------------------------------------------------------------\n");

        for (size_t x = 0; x < MAX_NODE; x++)
        {
            for (size_t y = 0; y < MAX_NODE; y++)
            {
                int nbV = nbrVoisin(x,y);

                if(gB[x][y] == true){
                    if(nbV < 2 || nbV > 3){
                        gBtmp[x][y] = false;
                    }

                }else{
                    if(nbV == 3){
                        gBtmp[x][y] = true;
                    }
                }
            }
            
        }

        itt++;

        for (size_t x = 0; x < MAX_NODE; x++)
        {
            for (size_t y = 0; y < MAX_NODE; y++)
            {
                gB[y][x] = gBtmp[y][x];
            }
            
        }

        sleep(TIMESTAMP);

    }

    return 0;
}
