#ifndef __VARIABLES_H__
#define __VARIABLES_H__
#pragma once

#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define TIMESTAMP 0.1f
#define MAX_NODE 36

#define PROBA 0.5

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define WIN_TITLE "Connay Game of Life"
#define WIN_W 820
#define WIN_H 820

#define BG_COLOR 150, 150, 150, 255


#endif // __VARIABLES_H__