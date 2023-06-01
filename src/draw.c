#include <stdlib.h>
#include <stdio.h>
#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif
#include "draw.h"
#include <SDL2/SDL_image.h>


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
  show_score(552129993,renderer);
  SDL_RenderPresent(*renderer);
  return 0;
}






void destroy_game(SDL_Window **window,SDL_Renderer ** renderer) {
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_Quit();
}

int draw_img(SDL_Renderer ** renderer,int number,int offset){
  char filename[16];
  sprintf(filename, "./media/%d.png", number);
  SDL_Texture * image_texture = IMG_LoadTexture(*renderer,filename);
  int image_width, image_height;
  SDL_QueryTexture(image_texture, NULL, NULL, &image_width, &image_height);
  SDL_Rect texture_destination;
  texture_destination.x = WIDTH*0.95-30*offset;
  texture_destination.y = 0;
  texture_destination.w = image_width*0.5;
  texture_destination.h = image_height*0.5;
  SDL_RenderCopy(*renderer, image_texture, NULL, &texture_destination);
  SDL_DestroyTexture(image_texture);
  return 0;
}


int show_score(int score,SDL_Renderer ** renderer){
    int r=0;
    int e=score;
    int offset=0;
    do {
    r=e%10;
    e=e/10;
    draw_img(renderer,r,offset);
    offset+=1;
    }
while (e!=0);
    return 0;
}
