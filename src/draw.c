#include <stdlib.h>
#include <stdio.h>
#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif
#include "draw.h"

int draw_game(void){
    printf("Drawing the game \n");
    return 0;
}
int init_game(SDL_Window * window){
int ret=create_window(window);
if (ret !=0){
	return 1;
}
SDL_Delay(DELAY);
destroy_windows(window);
return 0;
}

int create_window(SDL_Window *window ){
      window = SDL_CreateWindow("SDL Example", /* Title of the SDL window */
			    SDL_WINDOWPOS_UNDEFINED, /* Position x of the window */
			    SDL_WINDOWPOS_UNDEFINED, /* Position y of the window */
			    WIDTH, /* Width of the window in pixels */
			    HEIGHT, /* Height of the window in pixels */
			    0); /* Additional flag(s) */

  if (window == NULL) {
    fprintf(stderr, "SDL window failed to initialise: %s\n", SDL_GetError());
    return 1;
  }
  return 0;
}


void destroy_windows(SDL_Window *window ){
	SDL_DestroyWindow(window);
  
}