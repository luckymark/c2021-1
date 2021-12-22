#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define HEIGHT 20
#define WIDTH 20

int map[HEIGHT][WIDTH]={
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 2, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1},    //1 代表墙
{1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1},    //2 代表人                                                                       
{1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1},    
{1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1},
{1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1},
{1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1},
{1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1},
{1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1},
{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
{1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
{1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1},
{1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1},
{1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
{1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
{1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1}, 
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
int x,y;

void setmap()
{
	int i,j;
	for(i=0;i<HEIGHT;i++){
		for(j=0;j<HEIGHT;j++){
			if(map[i][j]==0)
			{
				printf("  ");
			}
			else if(map[i][j]==1)
			{
				printf("國");
			}
			else if(map[i][j]==2)
			{
				printf("♀");
			}
			else if(map[i][j]==3)
			{
				printf("￥");
			}
		}
		printf("\n");
	}
}

void upwards()
{	
	if(map[x-1][y]==1 )
	{
		//do nothing
		x=x+1;
	}
	else if(map[x-1][y]==0)
	{
		map[x-1][y]=2;
		map[x][y]=0;
	}
	
	x=x-1;	
}

void downwards()
{	
	if(map[x+1][y]==1 )
	{
		//do nothing
		x=x-1;
	}
	else if(map[x+1][y]==0 ||map[x+1][y]==3)
	{
		map[x+1][y]=2;
		map[x][y]=0;
	}
	
	x=x+1;	
}

void left()
{	
	if(map[x][y-1]==1 )
	{
		//do nothing
		y=y+1;
	}
	else if(map[x][y-1]==0)
	{
		map[x][y-1]=2;
		map[x][y]=0;
	}
	
	y=y-1;	
}

void right()
{	
	if(map[x][y+1]==1 )
	{
		//do nothing
		y=y-1;
	}
	else if(map[x][y+1]==0 ||map[x][y+1]==3)
	{
		map[x][y+1]=2;
		map[x][y]=0;
	}
	
	y=y+1;	
}

void play()
{
	int direction;
	while(1){
		system("cls");
		setmap();
		if(x==18&&y==18)
		{
			map[x][y]=0;
			break;
		}
		direction=getch();
		
	    switch(direction){
	    	case 72:upwards();break;
	    	case 75:left();break;
	    	case 80:downwards();break;
	    	case 77:right();break;
		}
	}
    printf("恭喜你通关游戏！\n");
    return;
}

int main()
{
	x=1,y=1;
	play();
	return 0;
}
