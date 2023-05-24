#include <stdlib.h>
#include <stdio.h>
#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif

int run_game_logic(void){
    printf("running the game \n");
    return 0;
}