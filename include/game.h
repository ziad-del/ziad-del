#ifndef __GAME__H
#define __GAME__H
#include <stddef.h>
#include <stdbool.h>
enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

struct Food
{
    int x;
    int y;
};
typedef struct Food Food;

struct Snake_node
{
    int x;
    int y;
};
typedef struct Snake_node Snake_node;
#define H 1001
#define L 1001
#define STEP 40

struct Snake
{
    Snake_node *firstp;
    Snake_node *lastp;
    size_t snake_size;
};
typedef struct Snake Snake;

struct Game
{
    /* data */
    bool state;
    Snake snake;
    int score;
    int dir;
    Food food;
};
typedef struct Game Game;

#endif