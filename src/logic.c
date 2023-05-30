#include <stdlib.h>
#include <stdio.h>
#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif
#include "draw.h"
int run_game_logic( SDL_Renderer** renderer ){
    int quit = 0;
    // Event handler
    SDL_Event event;
    // While application is running
    while (!quit) {
        // Handle events on queue
        SDL_Delay(500);
        draw_game(renderer);
        while (SDL_PollEvent(&event) != 0) {
            // Quit event (e.g., window close button)
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }
        // SDL_RenderClear(*renderer);
        // SDL_RenderPresent(*renderer);
    }
   return 0;
}