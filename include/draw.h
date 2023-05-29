#ifndef __DRAW__H
#define __DRAW__H

#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif
int init_game(SDL_Window ** window , SDL_Renderer ** renderer  );
void destroy_game(SDL_Window **window,SDL_Renderer ** renderer );
#define WIDTH 800
#define HEIGHT 600
#endif