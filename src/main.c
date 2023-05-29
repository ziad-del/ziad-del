#include <stdio.h>
#include <stdlib.h>
#include "../include/logic.h"
#include "../include/draw.h"
#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif

int main (int argc, char **argv)
{
  /* Initialises data */
  SDL_Window *window = NULL;
  SDL_Renderer* renderer = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "SDL failed to initialise: %s\n", SDL_GetError());
    return 1;
  }
  if (init_game(&window,&renderer)){
    fprintf(stderr, "SDL failed to init game \n");
    return 1;
  }

  run_game_logic(&renderer);
  destroy_game(&window,&renderer);
  return 0;
}
