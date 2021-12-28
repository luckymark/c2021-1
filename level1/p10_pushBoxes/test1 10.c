#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


struct box{
    int onDre;
};

struct box bbox[3];


int x = 0;
int y = 0;
int score = 100;
int standDre = 0;
int moveNum = 0;

void printMap(int **mapArr,int lineNum,int lieNum);
int move(int mx,int my,int ** mapArr);
int success();
void HideCursor();
void goToXY(short ,short );
int ** readMap(int * mLine,int * mLie,const char * mapNa);
int playGame(int mLine,int mLie,int ** mapArr);
int scorePrint(FILE * playerData,const char * mapNa);



int main(){

    FILE *playerData;
    fopen_s(&playerData,"playerData.txt","a+");
    
    int mLine,mLie;
    char * mapCh[3]={
            "A.map",
            "B.map",
            "C.map",
    };
    int i,j;
    for (i = 0; i < 3; ++i) {

        int **mapArr = readMap(&mLine, &mLie, mapCh[i]);
        system("cls");

        printMap(mapArr, mLine, mLie);
        do {
            playGame(mLine, mLie, mapArr);
        } while (!success());
        free(mapArr);
        scorePrint(playerData, mapCh[i]);
    }

}


void printMap(int **mapArr,int lineNum,int lieNum)
{	int i,j;
    for(i = 0; i < lineNum ; ++i)
    {
        for (j = 0; j < lieNum; ++j)
        {
            switch(mapArr[i][j])
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("#");
                    break;
                case 2:
                    printf("1");
                    break;
                case 5:
                case 6:
                case 7:
                    printf("G");
                    break;
                case 4:
                    printf("X");
                    break;
                default:
                    printf("?");
                    break;
            }
        }
        printf("\n");
    }

}

int move(int mx,int my,int ** mapArr){
    int temX = x;
    int temY = y;
    temX += mx;
    temY += my;
    if (mapArr[temX][temY] == 0) {
        mapArr[x][y] = standDre?4:0;
        mapArr[temX][temY] = 2;
        x = temX;
        y = temY;
        standDre = 0;
        ++moveNum;
    }
    if (mapArr[temX][temY] == 4){
        mapArr[x][y] = standDre?4:0;
        mapArr[temX][temY] = 2;
        x = temX;
        y = temY;
        standDre = 1;
        ++moveNum;
    }
    if(mapArr[temX][temY] == 5 ||mapArr[temX][temY] == 6 || mapArr[temX][temY] == 7){
        int boxNum = mapArr[temX][temY]-5;
        if(mapArr[temX+mx][temY+my] == 0){


            mapArr[x][y] = standDre?4:0;
            mapArr[temX + mx][temY + my] = mapArr[temX][temY];
            mapArr[temX][temY] = 2;
            if(bbox[boxNum].onDre == 1){
                standDre = 1;
            }
            if(bbox[boxNum].onDre == 0){
                standDre = 0;
            }

            x = temX;
            y = temY;
            bbox[boxNum].onDre = 0;
        }
        if(mapArr[temX+mx][temY+my] == 4){

            mapArr[x][y] = standDre?4:0;
            mapArr[temX+mx][temY+my] = mapArr[temX][temY];
            mapArr[temX][temY] = 2;
            if(bbox[boxNum].onDre == 1){
                standDre = 1;
            }
            if(bbox[boxNum].onDre == 0){
                standDre = 0;
            }

            x = temX;
            y = temY;
            bbox[boxNum].onDre = 1;
        }
        ++moveNum;
    }
    return 1;
}

int success(){
	int i;
    for (i = 0; i < 3; ++i) {
        if(bbox[i].onDre == 0)
            return 0;
    }
    return 1;
}

void goToXY(short wx,short wy){
    HANDLE hOutput;
    COORD loc;
    loc.X= wx;
    loc.Y=wy;
    hOutput= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput, loc);
}

void HideCursor(){

    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

}

int ** readMap(int * mLine,int * mLie,const char * mapNa){
	int i,j;
    FILE *map;
    fopen_s(&map,mapNa,"r");

    if (map == NULL){
        printf("The Map Is Not Found.");
        return NULL;
    }

    if(fscanf_s(map,"mLine:%d\nmLie:%d\n",mLine,mLie) != 2){
        printf("Map Error 1.");
        return NULL;
    }

    int ** mapArr =(int **)malloc(sizeof(int *) * *mLine);
    for (i = 0; i < *mLine; ++i) {
        mapArr[i] = malloc(sizeof(int) * *mLie);
    }
    if(mapArr == NULL){
        printf("Memory access failed.");
        return NULL;
    }

    if(fscanf_s(map,"playerX:%d\nplayerY:%d\n",&x,&y) != 2){
        printf("Map Error 2.");
        return NULL;
    }
    for (i = 0; i < 3; ++i) {
        bbox[i].onDre = 0;
    }
    for (i = 0; i < *mLine; ++i) {
        for (j = 0; j < *mLie; ++j) {
            fscanf_s(map,"%d",&(mapArr[i][j]));
        }
    }
    return mapArr;
}

int playGame(int mLine,int mLie,int ** mapArr){

    HideCursor();
    int tem = _getch();
    int ipt;
    if (tem == 224)
        ipt = _getch();
    else
        ipt = tem;
    switch (ipt) {
        case 72:
        case 119:
            move(-1, 0,mapArr);
            break;
        case 80:
        case 115:
            move(1, 0,mapArr);
            break;
        case 75:
        case 97:
            move(0, -1,mapArr);
            break;
        case 77:
        case 100:
            move(0, 1,mapArr);
            break;
        default:
            ;
        }
    goToXY(0,0);
    printMap(mapArr,mLine,mLie);

    return 0;
}
int scorePrint(FILE * playerData,const char * mapNa) {

    if (moveNum < 10)
        score = 90;
    else if (moveNum < 50)
        score = 70;
    else if (moveNum < 100)
        score = 50;
    else
        score = 30;
    printf("\nSuccess!Your score is %d", score);
    fprintf(playerData, "%s", mapNa);
    fprintf(playerData, "Score : %d\n", score);

    Sleep(1000);
    return 0;

}
