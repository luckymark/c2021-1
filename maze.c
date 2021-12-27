#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define Height 57  
#define Width 109 
#define Wall 1
#define Road 0
#define Start 2
#define End 3
#define Esc 5
#define Up 1
#define Down 2
#define Left 3
#define Right 4


int map[Height+2][Width+2];
int x=2,y=1;

void menu();
void hidden();
void prepare();
void create(int x,int y);
void paint(int x,int y);
void game();
int get_key();
void gotoxy(int x,int y);


void gotoxy(int x,int y){ 
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}

void hidden(){
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);
	cci.bVisible=0;
	SetConsoleCursorInfo(hOut,&cci);
}

int get_key(){
	char c;
	while(c=getch())
	{
		if(c==27) return Esc;
		if(c!=-32)continue;
		c=getch();
		if(c==72) return Up;
		if(c==80) return Down;
		if(c==75) return Left;
		if(c==77) return Right;
	}
	return 0;
}

void game()
{
	int x=2,y=1;
	int c;
	while(1)
	{
		gotoxy(2*y-2,x-1);
		
		printf("☆");
		if(map[x][y]==End)
		{
			gotoxy(30,24);
			printf("到达终点，按任意键结束");
			getch();
			break;
		}
		c=get_key();
		if(c==Esc)
		{
			gotoxy(0,24);
			break;
		}
		
		switch(c)
		{
			
			case Up:
				if(map[x-1][y]!=Wall)
				{
					paint(x,y);
					x--;
				}
				else{
					system("color d");
					system("color b");
				}
				break;

			case Down:
				if(map[x+1][y]!=Wall)
				{
					paint(x,y);
					x++;
				}
				else{
					system("color d");
					system("color b");
				}
				break;

			case Left:
				if(map[x][y-1]!=Wall)
				{
					paint(x,y);
					y--;
				}
				else{
					system("color d");
					system("color b");
				}
				break;

			case Right:
				if(map[x][y+1]!=Wall)
				{
					paint(x,y);
					y++;
				}
				else{
					system("color d");
					system("color b");
				}
				break;		
		}
	}
}

void paint(int x,int y){
	gotoxy(2*y-2,x-1);
	switch(map[x][y])
	{
		case Start:
		printf("ST");break;
		case End:
		printf("END");break;
		case Wall:
		printf("■");break;
		case Road:
		printf(" ");break;
	}
}

void create(int x,int y){
	int c[4][2]={0,1,1,0,0,-1,-1,0};
	int i,j,t;
	for(i=0;i<4;i++)
	{
		j=rand()%4;
		t=c[i][0];c[i][0]=c[j][0];c[j][0]=t;
		t=c[i][1];c[i][1]=c[j][1];c[j][1]=t;
	}
	map[x][y]=Road;
	for(i=0;i<4;i++)
	if(map[x+2*c[i][0]][y+2*c[i][1]]==Wall)
	{
		map[x+c[i][0]][y+c[i][1]]=Road;
		create(x+2*c[i][0],y+2*c[i][1]);
	}
}

void prepare()
{
	int i,j;
	srand((unsigned)time(NULL));
	hidden();

	for(i=0;i<=Height+1;i++){
		for(j=0;j<=Width+1;j++){
			if(i==0||i==Height+1||j==0||j==Width+1){
				map[i][j]=Road;
			}
			else{
				map[i][j]=Wall;
			}
		}
	}

	create(2*(rand()%(Height/2)+1),2*(rand()%(Width/2)+1));

	for(i=0;i<=Height+1;i++){
		map[i][0]=Wall; 
		map[i][Width+1]=Wall; 
	}
	for(j=0;j<=Width+1;j++){
		map[0][j]=Wall; 
		map[Height+1][j]=Wall;
	}

	map[2][1]=Start;
	map[Height-1][Width]=End;

	for(i=1;i<=Height;i++)
		for(j=1;j<=Width;j++)
			paint(i,j);
}

void menu()
{
	int i,j,n=0;
		
	gotoxy(60,10);printf("■■■■■■ ■■■■■ ■■■■■ ■■■■■■ \n"); 
	gotoxy(60,11);printf("■   ■   ■ ■      ■        ■  ■        ■ \n"); 
	gotoxy(60,12);printf("■   ■   ■ ■      ■      ■    ■■■■■■ \n"); 
	gotoxy(60,13);printf("■   ■   ■ ■     ■     ■      ■         \n"); 
	gotoxy(60,14);printf("■   ■   ■ ■■■■■ ■■■■■ ■■■■■■ \n"); 
		
	gotoxy(60,17);printf("走迷宫游戏\n"); 
	gotoxy(60,20);printf("按Enter键随机生成迷宫&开始\n\n");
	gotoxy(60,23);printf("按Esc键退出\n\n\n");

	hidden();
	while(n<2){
		for(i=0;i<19999999;i++);
			system("color d");
		for(i=0;i<19999999;i++);
			system("color a");
		for(i=0;i<19999999;i++);
			system("color c");
		for(i=0;i<19999999;i++);
			system("color b");
		for(i=0;i<19999999;i++);
			system("color c");
		for(i=0;i<19999999;i++);
			system("color e");
		n++;
	}
	system("color b");
	getch();	
	system("cls");	
}
	
int main()
{
	menu();	
	prepare();
	game();
	getch();
	return 0;
}

