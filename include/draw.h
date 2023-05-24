#ifndef __DRAW__H
#define __DRAW__H

#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif
int draw_game(void);
int create_window(SDL_Window *window );
void destroy_windows(SDL_Window *window );
int init_game(SDL_Window * window);
#define WIDTH 800
#define HEIGHT 600
#define DELAY 3000
#endif