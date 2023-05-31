#include <stdio.h>
#include <stdlib.h>
#include "../include/logic.h"
#include "../include/draw.h"
#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif
#include <SDL2/SDL_image.h>

int main (int argv, char ** argc)
{
  /* Initialises data */
  SDL_Window *window = NULL;
  SDL_Renderer* renderer = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "SDL failed to initialise: %s\n", SDL_GetError());
    return 1;
  }
      // Initialize support for loading PNG and JPEG images carefull it return 0 on failure
  if ( IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0 ) {
      fprintf(stderr, "SDL failed to initialise img loader: \n");
      return 1;
  }

  if (init_game(&window,&renderer)){
    fprintf(stderr, "SDL failed to init game \n");
    return 1;
  }

  run_game_logic(&renderer);
  IMG_Quit();
  destroy_game(&window,&renderer);
  return 0;
}
