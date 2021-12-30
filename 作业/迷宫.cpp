#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h> 
using namespace std;

int map[11][11]=
{
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,4,4,4,3,0,4,0,1},
	{1,0,0,4,0,0,4,0,0,0,1},
	{1,0,0,4,0,0,4,0,0,0,1},
	{1,0,0,4,4,0,4,0,0,0,1},
	{1,0,0,0,0,0,4,0,0,0,1},
	{1,0,0,4,0,4,4,0,0,0,1},
	{1,0,0,4,0,0,4,0,0,0,1},
	{1,0,0,4,0,0,0,0,0,0,1},
	{1,0,2,4,0,0,4,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1},
}; 

void draw(){
	for(int i=0;i<=10;i++)
	{
		for(int j=0;j<=10;j++)
		{
			switch(map[i][j])
			{
				case 0:cout<<"  ";break;
				case 1:cout<<"■";break;
				case 2:cout<<"▲";break;
				case 3:cout<<"**";break;
				case 4:cout<<"□";break; 
			}
		}
		cout<<"\n";
	}
}

void play(){
	int x,y;
	for(int i=0;i<=10;i++)
	{
		for(int j=0;j<=10;j++)
		{
			if(map[i][j]==2)
			{
				x=i;
				y=j;
			}
		}
	}//找小人位置 
	
	char k;
	k=getch();
	switch(k)
	{
		case 'w':
			if(map[x-1][y]==0)
			{
				map[x-1][y]=2;
				map[x][y]=0;
			}
			else if(map[x-1][y]==3)
			{
				system("cls");
				cout<<"恭喜你通关!!!"; 
				exit(0);
			}
			break;
		case 'a':
			if(map[x][y-1]==0)
			{
				map[x][y-1]=2;
				map[x][y]=0;
			}
			else if(map[x][y-1]==3)
			{
				system("cls");
				cout<<"恭喜你通关!!!"; 
				exit(0);
			}
			break;
		case 'd':
			if(map[x][y+1]==0)
			{
				map[x][y+1]=2;
				map[x][y]=0;
			}
			else if(map[x][y+1]==3)
			{
				system("cls");
				cout<<"恭喜你通关!!!"; 
				exit(0);
			}
			break;
		case 's':
			if(map[x+1][y]==0)
			{
				map[x+1][y]=2;
				map[x][y]=0;
			}
			else if(map[x+1][y]==3)
			{
				system("cls");
				cout<<"恭喜你通关!!!"; 
				exit(0);
			}
			break;
		
	}//wasd控制小人走动 
}

int main(){
	while(1){
		system("cls");
		draw();
		play();
	}
	return 0;
}
