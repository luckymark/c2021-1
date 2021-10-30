#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define LENGTH 9
#define WIDTH 9 

int map[LENGTH][WIDTH] = {
	{1,1,1,1,1,0,0,0,0},
	{1,2,0,0,1,0,0,0,0},
	{1,0,3,3,1,0,1,1,1},
	{1,0,3,0,1,0,1,4,1},
	{1,1,1,0,1,1,1,4,1},
	{0,1,1,0,0,0,0,4,1},
	{0,1,0,0,0,1,0,0,1},
	{0,1,0,0,0,1,1,1,1},
	{0,1,1,1,1,1,0,0,0}
};

int x,y,j;
void getmap()
{
	int a, b;
	for(a = 0; a<LENGTH; a++){
		for(b = 0; b < WIDTH; b++) {
			switch(map[a][b]) {
				case 1:printf("回");break;
				case 2:printf("嬲");break;
				case 4:printf("口");break;
				case 3:printf("箱");break; 
				default:printf("  ");break;
			}
		}
		printf("\n");
	}
}

void up()
{
	if(map[--x][y] != 3) {
		if(map[x][y] == 1) {
			x++;
		} else {
			map[x][y] = 2;map[x+1][y] = 0;
		}
	} else {
		if(map[x-1][y] == 0) {
			map[x][y] = 2;map[x+1][y] = 0;map[x-1][y] = 3;
		}else if(map[x-1][y] == 4) {
			map[x][y] = 2;map[x+1][y] = 0;map[x-1][y] = 3;
			if(x == 4) {
				map[x+1][y] = 4;
			}
		}else {
			x++;
		}
	}
}

void down()
{
	if(map[++x][y] != 3) {
		if(map[x][y] == 1) {
			x--;
		}else if(x-1 == 4&&y == 7) {
			map[x-1][y] = 4;map[x][y] = 2;
		}else if(x-1 == 5&&y == 7) {
			map[x-1][y] = 4;map[x][y] = 2;
		}else {
			map[x][y] = 2;map[x-1][y] = 0;
		}
	} else {
		if(map[x+1][y] == 0) {
			map[x][y] = 2;map[x-1][y] = 0;map[x+1][y] = 3;
		}else {
			x--;
		}
		if(x+2 == 8) {
	  j = -1;
	}
	}
}

void left()
{
	if(map[x][--y] != 3) {
		if(map[x][y] == 1) {
			y++;
		}else if(x == 5&&y == 6) {
			map[x][y] = 2;map[x][y+1] = 4;
		}
		 else {
			map[x][y] = 2;map[x][y+1] = 0;
		}
	} else {
		if(map[x][y-1] == 0) {
			map[x][y] = 2;map[x][y+1] = 0;map[x][y-1] = 3;
		}else {
			y++;
		}
			if(y-2 == 0||y-2 == 1) {
		j = -1;
	}
	}
}

void right()
{
	if(map[x][++y] != 3) {
		if(map[x][y] == 1) {
			y--;
		} else {
			map[x][y] = 2;map[x][y-1] = 0;
		}
	} else {
		if(map[x][y+1] == 0) {
			map[x][y] = 2;map[x][y-1] = 0;map[x][y+1] = 3;
		}else if(map[x][y+1] == 4) {
			map[x][y] = 2;map[x][y-1] = 0;map[x][y+1] = 3;
		}else {
			y--;
		}
	}
}

void play(){
	int direction;
	while(1){
		system("cls");
		getmap();
		if(map[3][7] == 3&&map[4][7] == 3&&map[5][7] == 3){
			map[x][y]=0;
			break;
		}else if(j == -1) {
			break;
		}
		direction=getch();

	    switch(direction){
	    	case 72:up();break;
	    	case 75:left();break;
	    	case 80:down();break;
	    	case 77:right();break;
		}}
	if(j == 1) {
		printf("恭喜你通关游戏！\n");
	}else {
		printf("游戏失败，请关闭程序重新开始"); 
	}
}

int main()
{
	x=1,y=1;
	j = 1;
	play();
	return 0;
}
