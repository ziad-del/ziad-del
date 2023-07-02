#include <stdlib.h>
#include <stdio.h>
#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif
#include "draw.h"
#include <SDL2/SDL_image.h> 

int increase_snake_size(snake * s){
    s->snake_size+=1;
    s->snake_array= (struct snake_element *) realloc(s->snake_array,sizeof(struct snake_element)*s->snake_size);
    if (s->snake_array == NULL){
        printf("failed realloc \n");
        return EXIT_FAILURE;
    }
    // we must fill the new stuff
    s->snake_array[s->snake_size-1].is_head=0;
    s->snake_array[s->snake_size-1].dir=  s->snake_array[s->snake_size-2].dir;
    switch (s->snake_array[s->snake_size-2].dir)
    {
    case UP :
         s->snake_array[s->snake_size-1].posx=  s->snake_array[s->snake_size-2].posx;
         s->snake_array[s->snake_size-1].posy=  s->snake_array[s->snake_size-2].posy + STEP;
        break;
    case DOWN :
        s->snake_array[s->snake_size-1].posx=  s->snake_array[s->snake_size-2].posx - STEP;
        break;
    case LEFT:
        s->snake_array[s->snake_size-1].posy= s->snake_array[s->snake_size-2].posy;
        s->snake_array[s->snake_size-1].posx=  s->snake_array[s->snake_size-2].posx+STEP;

        break;
    case RIGHT:
            s->snake_array[s->snake_size-1].posy= s->snake_array[s->snake_size-2].posy;
            s->snake_array[s->snake_size-1].posx=  s->snake_array[s->snake_size-2].posx-STEP;

        break;
    default:
        printf("something went wrong when parsing direction");
        return EXIT_FAILURE;
        break;
    }
    
    return EXIT_SUCCESS;
}

int run_game_logic( SDL_Renderer** renderer , snake * s){
    int quit = 0;
    // Event handler
    SDL_Event event;
    while (!quit) {
        SDL_Delay(200);
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
                             increase_snake_size(s);
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