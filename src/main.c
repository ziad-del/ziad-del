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
#include "game.h"
#include "draw.h"
#include "update.h"

int main (int argv, char ** argc){
SDL_Window *window = NULL;
SDL_Renderer* renderer = NULL;
Game  game;
// init SDL
if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "SDL failed to initialise: %s\n", SDL_GetError());
    return 1;
}
// Initialize support for loading PNG and JPEG images carefull it return 0 on failure
  if ( IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0 ) {
      fprintf(stderr, "SDL failed to initialise img loader: \n");
      return 1;
  }

if (init_game(&window,&renderer,&game)){
    fprintf(stderr, "SDL failed to init game \n");
    return 1;
}

SDL_Event event;
int quit = 0;
 while (!quit && game.state == true) {
        while (SDL_PollEvent(&event) != 0) {
            switch (event.type){
                case SDL_QUIT:
                    quit = 1;
                    break;
                case SDL_KEYDOWN:   
                     switch( event.key.keysym.sym ) {
                        case SDLK_DOWN:
                              if(game.dir != UP){
                                game.dir =DOWN;
                              } 
                             break;
                        case SDLK_UP:
                            if(game.dir != DOWN){
                                game.dir =UP;
                            } 
                             break;
                        case SDLK_RIGHT:
                            if(game.dir != LEFT){
                                game.dir =RIGHT;
                              } 
                            break;
                        case SDLK_LEFT:
                            if(game.dir != RIGHT){
                                game.dir =LEFT;
                              } 
                             break;
                        default:
                            break;
                     }

                default:
                    break;
            }

        }
    SDL_Delay(200);
    draw(&game,&renderer);
    update(&game);
 }

// clean up
free(game.snake.firstp);
IMG_Quit();
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();
return EXIT_SUCCESS;    
}
