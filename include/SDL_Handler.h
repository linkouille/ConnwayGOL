#ifndef __SDL_HANDLER_H__
#define __SDL_HANDLER_H__
#pragma once

#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <errno.h>
#include <stdbool.h>

#include "variables.h"

SDL_Window * initSDL();

void KillSDLContext(SDL_Window * win);

void DrawRect(SDL_Renderer * renderer,SDL_Rect * rect, SDL_Color * color, bool filed);

void DrawGrid(SDL_Renderer * renderer,SDL_Rect * rect, float width);

typedef struct {
    SDL_Rect rect;
    const char * title;
    
    void (* callBack)(void);
}button;

void DrawText(SDL_Renderer * renderer, const char * text, int fontSize, int x, int y, SDL_Color * color);

void DrawTextR(SDL_Renderer * renderer, const char * text, int fontSize, SDL_Color * color, SDL_Rect * rect);

void DrawButton(SDL_Renderer * renderer, button * b);

bool isInside(int x, int y, SDL_Rect * rect);

#endif // __SDL_HANDLER_H__