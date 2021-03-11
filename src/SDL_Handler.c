#include "SDL_Handler.h"

SDL_Window * initSDL()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        fprintf(stderr,"ERROR: failed SDL_Init : %s \n",SDL_GetError());
        exit(errno);
    }


    SDL_Window * win = SDL_CreateWindow(WIN_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, SDL_WINDOW_SHOWN);
    if(win == NULL){
        fprintf(stderr,"ERROR: failed Create Window : %s \n",SDL_GetError());
        exit(errno);
    }

    if(TTF_Init() == -1){
        fprintf(stderr,"ERROR: failed TTF_Init : %s \n",SDL_GetError());
        exit(errno);
    }

    return win;

}

void KillSDLContext(SDL_Window * win){

    SDL_DestroyWindow(win);
    SDL_Quit();
}

void DrawRect(SDL_Renderer * renderer,SDL_Rect * rect, SDL_Color * color, bool filed){
    SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
    if(filed){
        SDL_RenderFillRect(renderer,rect);
    }else{
        SDL_RenderDrawRect(renderer,rect);
    }

    SDL_SetRenderDrawColor(renderer, BG_COLOR);

}

void DrawGrid(SDL_Renderer * renderer,SDL_Rect * rect, float width) 
{
    SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);

    for (size_t x = rect->x + width; x <= rect->w + width  * 2; x += width)
    {
        SDL_RenderDrawLine(renderer,x,rect->y,x,rect->y + rect->h);
    }
    for (size_t y = rect->y + width; y <= rect->h + width*2; y += width)
    {
        SDL_RenderDrawLine(renderer,rect->x,y,rect->x + rect->w,y);
    }

    SDL_SetRenderDrawColor(renderer, BG_COLOR);
    
}

void DrawText(SDL_Renderer * renderer, const char * text, int fontSize, int x, int y, SDL_Color * color) 
{

    TTF_Font* font = TTF_OpenFont("../assets/font/Arial.ttf", fontSize);
    int textLen = sizeof(text)/sizeof(char);
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text, *color);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect rect = {x,y,(fontSize + 2) * textLen, (fontSize + 2)};

    SDL_RenderCopy(renderer, Message, NULL, &rect);

    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(font);

}
void DrawTextR(SDL_Renderer * renderer, const char * text, int fontSize, SDL_Color * color, SDL_Rect * rect) 
{

    TTF_Font* font = TTF_OpenFont("../assets/font/Arial.ttf", fontSize);
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text, *color);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_RenderCopy(renderer, Message, NULL, rect);

    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(font);

}

void DrawButton(SDL_Renderer * renderer, button * b) 
{
    SDL_Color lineColor = {50,50,50,255};
    SDL_Color bgColor = {100,100,100,255};
    SDL_Color fontColor = {0,0,0,255};

    DrawTextR(renderer,b->title,72, &fontColor, &b->rect);
    
    DrawRect(renderer, &b->rect, &lineColor, false);
    DrawRect(renderer, &b->rect, &bgColor, false);

}

bool isInside(int x, int y, SDL_Rect * rect) 
{
    return x >= rect->x && y >= rect->y && x <= rect->x + rect->w && y <= rect->y + rect->h;
}
