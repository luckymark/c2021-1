#include<stdio.h>
#include<stdlib.h>
#define HIGH 17
#define WIDE 17
    int map[HIGH][WIDE]={
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 2, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1},
            {1, 0, 4, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1},
            {1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
            {1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
            {1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
            {1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 1, 1, 3, 0, 0, 0, 1, 0, 1, 1, 0, 1},
            {1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 4, 0, 1},
            {1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1},
            {1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 3, 1, 1, 0, 0, 1, 1},
            {1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1},
            {1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1},
            {1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
void paint() {
    	int i,j;
    for ( i = 0; i < HIGH; i++) {
        for ( j = 0; j < WIDE; j++) {
            if (map[i][j] == 0) {
                printf("  ");
            } else if (map[i][j] == 1) {
                printf("※");
            } else if (map[i][j] == 2) {
                printf("♀");
            } else if (map[i][j] == 3) {
                printf("出");
            } else if(map[i][j]==4){
            	printf("卍");
            } 
        }
        printf("\n");
    }
}
int x,y,count;
void up(){
    if(map[x-1][y]==0){
        map[x-1][y]=2;
        map[x][y]=0;
    }else if(map[x-1][y]==4&&map[x-2][y]==0){
        map[x-2][y]=4;
        map[x-1][y]=2;
        map[x][y]=0;
	}x--;
}
void down(){
    if(map[x+1][y]==0){
        map[x+1][y]=2;
        map[x][y]=0;
    }else if(map[x+1][y]==4&&map[x+2][y]==0){
    	map[x+2][y]=4;
        map[x+1][y]=2;
       	map[x][y]=0;
    }x++;
}
void left(){
    if(map[x][y-1]==0){
        map[x][y-1]=2;
        map[x][y]=0;
    }else if(map[x][y-1]==4&&map[x][y-2]==0){
    	map[x][y-2]=4;
        	map[x][y-1]=2;
        	map[x][y]=0;
    }else if(map[x][y-1]==4&&map[x][y-2]==3){
    	map[x][y-2]=4;
        map[x][y-1]=2;
        map[x][y]=0;
	}y--;
}
void right(){
    if(map[x][y+1]==0){
        map[x][y+1]=2;
        map[x][y]=0;
    }else if(map[x][y+1]==4&&map[x][y+2]==0){
    	map[x][y+2]=4;
        map[x][y+1]=2;
        map[x][y]=0;
    }y++;
}
void run(){
int direction;
int count=0;
    while (1) {
        system("cls");
        paint();
        if (x == 7 && y == 9) {
        	map[x][y-2]=3;
        }
        if(x==9&&y==10){
        	map[x+2][y]=3;
        	break; 
        }
    direction=getch();
    switch (direction) {
        case 72:
            up();
            break;
        case 80:
            down();
            break;
        case 75:
            left();
            break;
        case 77:
            right();
            break;
        }
    }
}
int main()
{
	x=1;y=1;
	run();
	printf("你一共走了%d步\n",count);
	printf("得分是%d分",210-count);
	printf("恭喜通关");
	return 0;
}

