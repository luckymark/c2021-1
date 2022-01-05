//
// Created by 24962 on 2021/11/15.
//

#ifndef MAZE_STACK_H
#define MAZE_STACK_H

typedef struct Site{
    int x;
    int y;
    struct Site *pNext;
} Site, *pSite;

typedef struct Stack
{
    pSite pTop;
    pSite pBottom;
} STACK, *PSTACK;

void init(PSTACK);
void push(PSTACK, pSite);
pSite pop(PSTACK);
void traverse(PSTACK);

#endif //MAZE_STACK_H
