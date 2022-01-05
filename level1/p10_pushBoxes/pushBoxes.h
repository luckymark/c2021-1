//
// Created by 24962 on 2021/11/22.
//
#ifndef PUSHBOXES_PUSHBOXES_H
#define PUSHBOXES_PUSHBOXES_H

#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define WAY 0;
#define WALL 1;
#define PLAYER 2;
#define BOX 3;
#define DESTINATION 4;
#define RIGHT 5;

#define W 'w'
#define S 's'
#define A 'a'
#define D 'd'

typedef struct Map {
	int map[15][15];
	int x;
	int y;
	int num;
} Map, *pMap;
void load(char *, int *);
void display(int *);
void play(int *);
void move(char);
#endif //PUSHBOXES_PUSHBOXES_H
