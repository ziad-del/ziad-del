#include <stdio.h>
#include <stddef.h>  
#include <stdbool.h>
#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#include <SDL/SDL_image.h>
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#include <SDL2/SDL_image.h>
#endif
#include <assert.h>  // assert
#define unreachable assert(false);exit(99);
#include "game.h"
#include "update.h"

int init_game(SDL_Window ** window, SDL_Renderer ** renderer,Game * game){
  int ret=init_game_struct(game);
  if (ret == EXIT_FAILURE) {
    fprintf(stderr,"Failed to allocated memory");
    return EXIT_FAILURE;
  }
  *window = SDL_CreateWindow("SNAKE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, L, H, SDL_WINDOW_SHOWN);
  if (*window == NULL) {
    fprintf(stderr, "SDL window failed to initialise: %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }
  *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (*renderer == NULL) {
    fprintf(stderr, "SDL renderer failed to initialise: %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }
return EXIT_SUCCESS;
}


void draw_grid(SDL_Renderer ** renderer){
SDL_SetRenderDrawColor(*renderer, 128, 128, 128, 1);
int x= 0;

while (x <= H){
   SDL_RenderDrawLine(*renderer, x, 0, x, L);
   SDL_RenderDrawLine(*renderer, 0, x, L, x);

   x+=STEP;
}

}
void draw_snake(Game * game, SDL_Renderer ** renderer){

for (int i=0; i < game->snake.snake_size; i++){
SDL_Rect box;
box.w = STEP; 
box.h = STEP; 
SDL_SetRenderDrawColor(*renderer, 255 , 0 , 0, 255);
box.x = game->snake.firstp[i].x;
box.y = game->snake.firstp[i].y;
SDL_RenderDrawRect(*renderer, &box);
SDL_RenderFillRect(*renderer, &box);

}

}
int draw_food(Game * game,SDL_Renderer ** renderer){
SDL_Rect box;
box.w = STEP; 
box.h = STEP; 
SDL_SetRenderDrawColor(*renderer, 0 , 255 , 0, 255);
box.x = game->food.x;
box.y = game->food.y;
SDL_RenderDrawRect(*renderer, &box);
SDL_RenderFillRect(*renderer, &box);
}

int draw_score(SDL_Renderer ** renderer,int number,int offset){
  char filename[16];
  sprintf(filename, "./media/%d.png", number);
  SDL_Texture * image_texture = IMG_LoadTexture(*renderer,filename);
  int image_width, image_height;
  SDL_QueryTexture(image_texture, NULL, NULL, &image_width, &image_height);
  SDL_Rect texture_destination;
  texture_destination.x = L*0.95-30*offset;
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
    draw_score(renderer,r,offset);
    offset+=1;
    }
while (e!=0);
    return 0;
}

void draw(Game * game,SDL_Renderer ** renderer){
// clear screen content
SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
SDL_RenderClear(*renderer);

draw_grid(renderer);
draw_snake(game,  renderer);
// draw buffer
draw_food(game,renderer);
show_score(game->score,renderer);
SDL_RenderPresent(*renderer);
}
