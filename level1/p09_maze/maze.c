#include "maze.h"

pMaze creatMaze(int SIZE)
{
    pMaze pmaze = (pMaze)malloc(sizeof(Maze));
    setBoard(pmaze, SIZE);

    pSite psite = (pSite)malloc(sizeof(Site));
    psite->x = pmaze->x;
    psite->y = pmaze->y;
    psite->pNext=NULL;
    PSTACK ps = (PSTACK)malloc(sizeof(STACK));
    init(ps);
    push(ps, psite);

    pSite pSite1 = NULL;
    while((pSite1 = pop(ps))){
        ;
        int x = pSite1->x;
        int y = pSite1->y;
        int xU = x-2;
        int xD = x+2;
        int yL = y-2;
        int yR = y+2;
        int index[4]={0,1,2,3};
        for(int i = 0;i < 10;i++){
            int j = rand()%4;
            int p = index[j];
            index[j]=index[3-j];
            index[3-j]=p;
        }
        int flag = 0;
        for(int i=0;i<4;i++) {
            int r=index[i];
            switch (r) {
                case 0:
                    if (xU > 0 && pmaze->board[xU][y] == 1) {
                        pSite pSite2 = (pSite) malloc(sizeof(Site));
                        pSite2->x = xU;
                        pSite2->y = y;
                        push(ps, pSite1);
                        push(ps, pSite2);
                        pmaze->board[xU+1][y] = 1;
                        pmaze->board[x][y] = 2;
                        pmaze->board[xU][y] = 2;
                        flag = 1;
                    }
                    break;
                case 1:
                    if (xD < SIZE && pmaze->board[xD][y] == 1) {
                        pSite pSite2 = (pSite) malloc(sizeof(Site));
                        pSite2->x = xD;
                        pSite2->y = y;
                        push(ps, pSite1);
                        push(ps, pSite2);
                        pmaze->board[xD-1][y] = 1;
                        pmaze->board[x][y] = 2;
                        pmaze->board[xD][y] = 2;
                        flag=1;
                    }
                    break;
                case 2:
                    if (yL > 0 && pmaze->board[x][yL] == 1) {
                        pSite pSite2 = (pSite) malloc(sizeof(Site));
                        pSite2->x = x;
                        pSite2->y = yL;
                        push(ps, pSite1);
                        push(ps, pSite2);
                        pmaze->board[x][yL+1] = 1;
                        pmaze->board[x][y] = 2;
                        pmaze->board[x][yL] = 2;
                        flag=1;
                    }
                    break;
                case 3:
                    if (yR < SIZE && pmaze->board[x][yR] == 1) {
                        pSite pSite2 = (pSite) malloc(sizeof(Site));
                        pSite2->x = x;
                        pSite2->y = yR;
                        push(ps, pSite1);
                        push(ps, pSite2);
                        pmaze->board[x][yR - 1] = 1;
                        pmaze->board[x][y] = 2;
                        pmaze->board[x][yR] = 2;
                        flag=1;
                    }
                    break;
                default:
                    break;
            }
            if(flag)break;
        }
        if (!flag)free(pSite1);
    }
    return pmaze;
}

void setBoard(pMaze pmaze, int SIZE)
{
    pmaze->x=1;
    pmaze->y=1;
    pmaze->board = (int**)malloc(sizeof(int*) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        pmaze->board[i] = (int*)malloc(sizeof(int) * SIZE);
    }
    for(int i=0; i < SIZE; i++){
        for(int j=0; j < SIZE; j++){
            if(i!=0 && i!=SIZE-1 && i%2!=0 && j!=0 && j!=SIZE-1 && j%2!=0){
                pmaze->board[i][j]=1;
            }
            else{
                pmaze->board[i][j]=0;
            }
        }
    }
    pmaze->board[pmaze->x][0] = 2;
    pmaze->board[pmaze->x][pmaze->y] = 2;
    pmaze->board[SIZE-1][SIZE-2] = 2;
}
void displayMaze(pMaze pmaze, int SIZE)
{
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(pmaze->board[i][j]==0){
                printf("#");
            } else if (pmaze->board[i][j]==3){
                printf("O");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
void play(pMaze pmaze, int SIZE)
{
    system("cls");
    pmaze->board[pmaze->x][pmaze->y] = 3;
    int x=1, y=1;
    displayMaze(pmaze, SIZE);
    while(pmaze->board[SIZE-2][SIZE-2] != 3){
        char c = _getch();
        switch (c){
            case W:
                if(x-1>0&&pmaze->board[x-1][y]!=0){
                    pmaze->board[x][y]=2;
                    pmaze->board[x-1][y]=3;
                    x=x-1;
                    system("cls");
                    displayMaze(pmaze,SIZE);
                }
                break;
            case S:
                if(x+1<SIZE-1&&pmaze->board[x+1][y]!=0){
                    pmaze->board[x][y]=2;
                    pmaze->board[x+1][y]=3;
                    x=x+1;
                    system("cls");
                    displayMaze(pmaze,SIZE);
                }
                break;
            case A:
                if(y-1>0&&pmaze->board[x][y-1]!=0){
                    pmaze->board[x][y]=2;
                    pmaze->board[x][y-1]=3;
                    y=y-1;
                    system("cls");
                    displayMaze(pmaze,SIZE);
                }
                break;
            case D:
                if(y+1<SIZE-1&&pmaze->board[x][y+1]!=0){
                    pmaze->board[x][y]=2;
                    pmaze->board[x][y+1]=3;
                    y=y+1;
                    system("cls");
                    displayMaze(pmaze,SIZE);
                }
                break;
            default:
                break;
        }
    }
    
    printf("GAME OVER!");
    free(pmaze);
}
