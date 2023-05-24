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
    draw_game();
    run_game_logic();
    SDL_Window *window = NULL;
  
  /*
  * Initialises the SDL video subsystem (as well as the events subsystem).
  * Returns 0 on success or a negative error code on failure using SDL_GetError().
  */
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "SDL failed to initialise: %s\n", SDL_GetError());
    return 1;
  }
  init_game(window);

  SDL_Quit(); 
  
  return 0;
}
