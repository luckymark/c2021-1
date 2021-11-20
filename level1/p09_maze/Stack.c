//
// Created by 24962 on 2021/11/16.
//
#include "maze.h"
void init(PSTACK pS)
{
    pSite p = (pSite)malloc(sizeof(Site));
    p->x=-1;
    p->y=-1;
    p->pNext = NULL;
    pS->pBottom = p;
    pS->pTop = p;
}

void push(PSTACK pS, pSite psite)
{
    psite->pNext = pS->pTop;
    pS->pTop = psite;
}

pSite pop(PSTACK pS)
{

//    pSite p = (pSite)malloc(sizeof(Site));
    pSite p = pS->pTop;
    if(p->pNext==NULL) return NULL;
    pS->pTop = pS->pTop->pNext;

    return p;
}

//void traverse(PSTACK pS)
//{
//
//    while (pS->pTop != pS->pBottom)
//    {
//        pSite pTail = pS->pTop;
//        printf("%d\n", pS->pTop->data);
//        pS->pTop = pS->pTop->pNext;
//        free(pTail);
//    }
//}

