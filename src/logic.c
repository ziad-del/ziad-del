#include <stdlib.h>
#include <stdio.h>
#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif
#include "draw.h"
#include <SDL2/SDL_image.h> 
int run_game_logic( SDL_Renderer** renderer , snake * s){
    int quit = 0;
    // Event handler
    SDL_Event event;
    while (!quit) {
        SDL_Delay(100);
        draw_game(renderer,*s);
        move_snake(s);
        while (SDL_PollEvent(&event) != 0) {

            switch (event.type){
                case SDL_QUIT:
                    quit = 1;
                    break;

                case SDL_KEYDOWN:   
                     switch( event.key.keysym.sym ) {
                        case SDLK_DOWN:
                            s->snake_array[0].dir=DOWN;
                             break;
                        case SDLK_UP:
                            s->snake_array[0].dir=UP;
                             break;

                        case SDLK_RIGHT:
                            s->snake_array[0].dir=RIGHT;
                            break;
                        case SDLK_LEFT:
                             s->snake_array[0].dir=LEFT;
                             break;
                        default:
                            break;
                     }
                default:
                    break; 
            }
            // Quit event (e.g., window close button)

            

    }
}
   return 0;

}