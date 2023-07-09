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
#include "update.h"

int init_game_struct(Game * game){
game->score=0;
game->snake.snake_size=1;
game->snake.firstp=(Snake_node *) malloc(game->snake.snake_size * sizeof(Snake_node));

if (game->snake.firstp == NULL){
    fprintf(stderr,"Error failed to allocated\n");
    return EXIT_FAILURE;
}
game->snake.lastp=game->snake.firstp;
game->state=true;

game->snake.firstp->x=STEP*12;
game->snake.firstp->y=STEP*12;
game->dir=UP;
game->food.x=(rand() % 20)*STEP;
game->food.y=(rand() % 20)*STEP;
return EXIT_SUCCESS;
}
void auto_move(Game * game){
    for (int i =game->snake.snake_size-1; i > 0;i--){
        game->snake.firstp[i].x=game->snake.firstp[i-1].x;
        game->snake.firstp[i].y=game->snake.firstp[i-1].y;

    }
    // moving the HEAD
    switch (game->dir)
    {
    case UP:
        game->snake.firstp[0].y-=STEP;
        break;
    case DOWN:
        game->snake.firstp[0].y+=STEP;
        break;
    case LEFT:
        game->snake.firstp[0].x-=STEP;
        break;
    case RIGHT:
        game->snake.firstp[0].x+=STEP;
        break;
    default:
        break;
    }
    if ( game->snake.firstp[0].y < 0 ||game->snake.firstp[0].y > L || game->snake.firstp[0].x < 0 ||game->snake.firstp[0].x > L )
    {
        game->state=false;
        printf("you lose ! your score is %d \n",game->score);
    }

}


void check_for_collision(Game * game){
    if (game->snake.snake_size != 1){
        for (int i=1;i<game->snake.snake_size;i++){
            if (game->snake.firstp[0].x==game->snake.firstp[i].x && game->snake.firstp[0].y == game->snake.firstp[i].y){
             game->state=false;
             printf("you collided \n");   
            }
        }    
    }
}



int increase_snake_size(Game * game){
// copy the last element
int save_y =game->snake.firstp[game->snake.snake_size-1].y;
int save_x= game->snake.firstp[game->snake.snake_size -1].x;
auto_move(game);
game->snake.snake_size+=1;
game->snake.firstp= (Snake_node *) realloc(game->snake.firstp,game->snake.snake_size*sizeof(Snake_node) );
game->snake.firstp[game->snake.snake_size-1].y=save_y;
game->snake.firstp[game->snake.snake_size -1].x=save_x;
return EXIT_SUCCESS;
}

void check_if_food_was_eaten(Game * game){
    if (game->snake.firstp[0].x == game->food.x && game->snake.firstp[0].y == game->food.y){
        game->score+=1;
        increase_snake_size(game);
        game->food.x=(rand() % 20)*STEP;
        game->food.y=(rand() % 20)*STEP;    
    }

}

void update(Game * game){
    auto_move(game);
    check_if_food_was_eaten(game);
    check_for_collision(game); 
    
}
