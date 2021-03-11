#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "variables.h"
#include "gameOfLife.h"
#include "SDL_Handler.h"

int main(int argc, char const *argv[])
{
    
    gameBoard * gB = initGoLEmpty(MAX_NODE, MAX_NODE);

    SDL_Window * win = initSDL();
    SDL_Renderer * renderer = SDL_CreateRenderer(win,0,SDL_RENDERER_ACCELERATED);

    bool gameLoop = true;

    int itt = 0;

    SDL_Event e;

    float counter = TIMESTAMP * 1000;
    // float start, end, deltaTime;

    // struct timespec spec;

    SDL_Color whiteColor = {255,255,255,255};

    SDL_Color blackColor = {0,0,0,255};

    int size = round((WIN_H-100)/(MAX_NODE));

    SDL_Rect rect = {50,50,WIN_W-100,WIN_H-100};
    SDL_Rect titleRect = {0, 0, 100,26};

    button nextButton;
    SDL_Rect nextButtonRect = {(WIN_W / 2) - 150, WIN_H - 50, 100,50};
    nextButton.rect = nextButtonRect;
    nextButton.title = "Run";

    button pauseButton;
    SDL_Rect pauseButtonRect = {(WIN_W / 2) + 50, WIN_H - 50, 100,50};
    pauseButton.rect = pauseButtonRect;
    pauseButton.title = "Pause";

    char title[1024];

    bool edit = true;
    bool pause = false;
    bool pressed = false;
    bool moved = false;

    int mouseX, mouseY;

    while (gameLoop)
    {
        //RENDER

        SDL_SetRenderDrawColor(renderer, BG_COLOR);
        SDL_RenderClear(renderer);

        sprintf(title, "Connay's game of life (gen %d)",itt);
        DrawText(renderer, title, 24, 0,0, &blackColor);
        DrawButton(renderer, &nextButton);
        DrawButton(renderer, &pauseButton);

        DrawRect(renderer, &rect, &whiteColor, true);
        DrawGrid(renderer, &rect,size);

        for (size_t y = 0; y < gB->h; y++)
        {
            for (size_t x = 0; x < gB->w; x++)
            {
                if(gB->board[y][x]){
                    SDL_Rect cellrect = {rect.x + x * size,rect.y + y * size, size,size};
                    DrawRect(renderer,&cellrect, &blackColor,true);
                }
                    
            }
            
        }
        
        
        SDL_RenderPresent(renderer);

        counter++;

        if((counter / 1.0e3) > TIMESTAMP && !pause && !edit){
            computeRule(gB);

            itt++;
            counter = 0;

        }
        if(pressed && moved){

            if(edit && isInside(mouseX,mouseY, &rect)){

                int x=0,y=0;
                x = (mouseX - rect.x) / size;
                y = (mouseY - rect.y) / size;

                gB->board[y][x] = !gB->board[y][x];
                moved = false;
            }
        }

        // sleep(TIMESTAMP);//Handle event
        while(SDL_PollEvent(&e)){
            SDL_GetMouseState(&mouseX, &mouseY);
            switch (e.type)
            {
                case SDL_QUIT:
                    gameLoop = false;
                    break;
                case SDL_KEYDOWN:
                    if(e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_q)
                        gameLoop = false;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(isInside(mouseX,mouseY, &nextButton.rect)){
                        // printf("Next Button Pressed\n");
                        edit = !edit;
                    }
                    if(isInside(mouseX,mouseY, &pauseButton.rect)){
                        // printf("Pause Button Pressed\n");
                        pause = !pause;
                    }
                    pressed = true;
                    break;
                
                case SDL_MOUSEBUTTONUP:
                    pressed = false;                   
                    break;
                case SDL_MOUSEMOTION:
                    moved = true;
                    break;
                default:
                    break;
            }
        }
    }

    freeGameboard(gB);
    KillSDLContext(win);

    return 0;
}
