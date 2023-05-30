#include <stdlib.h>
#include <stdio.h>
#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif
#include "draw.h"


int init_game(SDL_Window ** window, SDL_Renderer ** renderer){
  *window = SDL_CreateWindow("SNAKE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  if (*window == NULL) {
    fprintf(stderr, "SDL window failed to initialise: %s\n", SDL_GetError());
    return 1;
  }
  *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (*renderer == NULL) {
    fprintf(stderr, "SDL renderer failed to initialise: %s\n", SDL_GetError());
    return 1;
  }
  draw_random_food_on_table(renderer);
return 0;
}

void draw_random_food_on_table(SDL_Renderer ** renderer){
SDL_Rect box;
int random_number_WIDTH = rand() % WIDTH*0.95  + 10;
int random_number_HEIGHT = rand() % HEIGHT*0.95 + 10;

box.w = 15; 
box.h = 15; 
box.x = random_number_WIDTH;
box.y = random_number_HEIGHT; 
SDL_SetRenderDrawColor(*renderer, 255 , 0 , 0, 255);
SDL_RenderDrawRect(*renderer, &box);
SDL_RenderFillRect(*renderer, &box);
}

int draw_game(SDL_Renderer ** renderer){
  SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
  SDL_RenderClear(*renderer);
  draw_random_food_on_table(renderer);
  SDL_RenderPresent(*renderer);
  return 0;
}


void destroy_game(SDL_Window **window,SDL_Renderer ** renderer) {
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_Quit();
}
