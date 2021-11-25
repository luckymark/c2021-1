//
// Created by 24962 on 2021/11/15.
//

#ifndef MAZE_MAZE_H
#define MAZE_MAZE_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "Stack.h"
#include <stddef.h>
#include "conio.h"
//#define SIZE 45
#define W 'w'
#define S 's'
#define A 'a'
#define D 'd'

typedef struct Maze{
 //   int board[SIZE][SIZE];
    int** board;
    int x;
    int y;
}Maze, *pMaze;

void setBoard(pMaze, int);
pMaze creatMaze(int);
void displayMaze(pMaze, int);
void play(pMaze, int);
#endif //MAZE_MAZE_H
