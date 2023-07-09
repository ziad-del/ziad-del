#ifndef __DRAW__H
#define __DRAW__H
#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif
int init_game(SDL_Window ** window, SDL_Renderer ** renderer,Game * game);
void draw(Game * game,SDL_Renderer ** renderer);
void draw_grid(SDL_Renderer ** renderer);
#endif