#ifndef __LOGIC__H
#define __LOGIC__H
#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif
#include "draw.h"
int run_game_logic( SDL_Renderer** renderer , snake *s);
int increase_snake_size(snake * s);
#endif