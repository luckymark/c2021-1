#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#define	N	100
int	count=500;
int	cas=0;
int g_map[10][12] = 
{
	{ 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },

	{ 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0 },

	{ 1, 0, 4, 0, 1, 0, 1, 1, 1, 1, 1, 1 },

	{ 1, 0, 4, 6, 1, 0, 1, 0, 0, 0, 3, 1 },

	{ 1, 1, 1, 4, 1, 1, 1, 0, 0, 0, 3, 1 },

	{ 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 3, 1 },

	{ 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 },

	{ 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 },

	{ 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 }
};
void drawMap();		
void up();		
void down();		
void left();	
void right();	
int gameOver();	

POINT GetGamerPostion();

int main()
{
	SetConsoleTitleA("推箱子");
	system("mode con cols=30 lines=12");
	printf("第%d关",cas+1);
	while (1)
	{	
		system("cls");
		drawMap();
		gameOver();
		char ch = _getch();		
		switch (ch)
		{
		case 'w':case 72:
			up();
			break;
		case 's':case 80:
			down();
			break;
		case 'a':case 75:
			left();
			break;
		case 'd':case 77:
			right();
			break;
		}
		if(gameOver()==1){
			cas++;
			printf("第%d关",cas+1); 
			FILE	*fp=fopen("map1.cpp","r");
			char	str[N+1]; 
			while(fgets(str,N,fp)!=NULL){
				printf("%s",str);
			}
			fclose(fp);
			char c = _getch();		
			switch (c){
				case 'w':case 72:
				up();
				break;
			case 's':case 80:
				down();
				break;
			case 'a':case 75:
				left();
				break;
			case 'd':case 77:
				right();
				break;
				}
		}
		count--;
	}	
	FILE	*fp=fopen("map1.cpp","w");
	fprintf(fp,"%d",count);
	fclose(fp);		
	return 0;
}

void drawMap()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			switch (g_map[i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("■");
				break;
			case 3:
				printf("☆");
				break;
			case 4:
				printf("□");
				break;
			case 6://人
				printf("♀");
				break;
			case 7:
				printf("★");
				break;
			case 9:
				printf("♀");
				break;
			}
		}
		printf("\n");
	}
}

void up()
{
	POINT pos = GetGamerPostion();
	if (g_map[pos.x - 1][pos.y] == 0)
	{
		g_map[pos.x - 1][pos.y] = 6;	
		if (g_map[pos.x][pos.y] == 9)		
		{
			g_map[pos.x][pos.y] = 3;
		}
		else
			g_map[pos.x][pos.y] = 0;			
	}
	if (g_map[pos.x - 1][pos.y] == 3)
	{
		g_map[pos.x - 1][pos.y] = 9;	
		if (g_map[pos.x][pos.y] == 9)	
		{
			g_map[pos.x][pos.y] = 3;
		}
		else
			g_map[pos.x][pos.y] = 0;			
	}
	if (g_map[pos.x - 1][pos.y] == 4)
	{
		if (g_map[pos.x - 2][pos.y] == 0)
		{
			g_map[pos.x - 2][pos.y] = 4;	
			g_map[pos.x - 1][pos.y] = 6;		
			if (g_map[pos.x][pos.y] == 9)		
			{
				g_map[pos.x][pos.y] = 3;
			}
			else
				g_map[pos.x][pos.y] = 0;
		}
		if (g_map[pos.x - 2][pos.y] == 3)
		{
			g_map[pos.x - 2][pos.y] = 7;	
			g_map[pos.x - 1][pos.y] = 6;		
			if (g_map[pos.x][pos.y] == 9)		
			{
				g_map[pos.x][pos.y] = 3;
			}
			else
				g_map[pos.x][pos.y] = 0;
		}
	}
	if (g_map[pos.x - 1][pos.y] == 7)
	{
		if (g_map[pos.x - 2][pos.y] == 0)
		{
			g_map[pos.x - 2][pos.y] = 4;	
			g_map[pos.x - 1][pos.y] = 9;	
			if (g_map[pos.x][pos.y] == 9)	
			{
				g_map[pos.x][pos.y] = 3;
			}
			else
				g_map[pos.x][pos.y] = 0;
		}
		if (g_map[pos.x - 2][pos.y] == 3)
		{
			g_map[pos.x - 2][pos.y] = 7;	
			g_map[pos.x - 1][pos.y] = 9;	
			if (g_map[pos.x][pos.y] == 9)		
			{
				g_map[pos.x][pos.y] = 3;
			}
			else
				g_map[pos.x][pos.y] = 0;
		}
	}
}


void down()
{
	POINT pos = GetGamerPostion();
	if (g_map[pos.x + 1][pos.y] == 0)
	{
		g_map[pos.x + 1][pos.y] = 6;	
		if (g_map[pos.x][pos.y] == 9)		
		{
			g_map[pos.x][pos.y] = 3;
		}
		else
			g_map[pos.x][pos.y] = 0;
	}
	if (g_map[pos.x + 1][pos.y] == 3)
	{
		g_map[pos.x + 1][pos.y] = 9;		
		if (g_map[pos.x][pos.y] == 9)		
		{
			g_map[pos.x][pos.y] = 3;
		}
		else
			g_map[pos.x][pos.y] = 0;
	}
	if (g_map[pos.x + 1][pos.y] == 4)
	{
		if (g_map[pos.x + 2][pos.y] == 0)
		{
			g_map[pos.x + 2][pos.y] = 4;	
			g_map[pos.x + 1][pos.y] = 6;	
			if (g_map[pos.x][pos.y] == 9)		
			{
				g_map[pos.x][pos.y] = 3;
			}
			else
				g_map[pos.x][pos.y] = 0;
		}
		if (g_map[pos.x + 2][pos.y] == 3)
		{
			g_map[pos.x + 2][pos.y] = 7;	
			g_map[pos.x + 1][pos.y] = 6;	
			if (g_map[pos.x][pos.y] == 9)		
			{
				g_map[pos.x][pos.y] = 3;
			}
			else
				g_map[pos.x][pos.y] = 0;
		}
	}
	if (g_map[pos.x + 1][pos.y] == 7)
	{
		if (g_map[pos.x + 2][pos.y] == 0)
		{
			g_map[pos.x + 2][pos.y] = 4;		
			g_map[pos.x + 1][pos.y] = 9;	
			if (g_map[pos.x][pos.y] == 9)	
			{
				g_map[pos.x][pos.y] = 3;
			}
			else
				g_map[pos.x][pos.y] = 0;
		}
		if (g_map[pos.x + 2][pos.y] == 3)
		{
			g_map[pos.x + 2][pos.y] = 7;	
			g_map[pos.x + 1][pos.y] = 9;		
			if (g_map[pos.x][pos.y] == 9)	
			{
				g_map[pos.x][pos.y] = 3;
			}
			else
				g_map[pos.x][pos.y] = 0;
		}
	}
}
void right()
{
	POINT pos = GetGamerPostion();
	if (g_map[pos.x][pos.y + 1] == 0)
	{
		g_map[pos.x ][pos.y + 1] = 6;	
		if (g_map[pos.x][pos.y] == 9)		
		{
			g_map[pos.x][pos.y] = 3;
		}
		else
			g_map[pos.x][pos.y] = 0;
	}
	if (g_map[pos.x][pos.y + 1] == 3)
	{
		g_map[pos.x][pos.y + 1] = 9;		
		if (g_map[pos.x][pos.y] == 9)		
		{
			g_map[pos.x][pos.y] = 3;
		}
		else
			g_map[pos.x][pos.y] = 0;
	}
	if (g_map[pos.x][pos.y + 1] == 4)
	{
		if (g_map[pos.x][pos.y + 2] == 0)
		{
			g_map[pos.x][pos.y + 2] = 4;	
			g_map[pos.x][pos.y + 1] = 6;		
			if (g_map[pos.x][pos.y] == 9)		
			{
				g_map[pos.x][pos.y] = 3;
			}
			else
				g_map[pos.x][pos.y] = 0;
		}

		if (g_map[pos.x][pos.y + 2] == 3)
		{
			g_map[pos.x][pos.y + 2] = 7;	
			g_map[pos.x][pos.y + 1] = 6;		
			if (g_map[pos.x][pos.y] == 9)	
			{
				g_map[pos.x][pos.y] = 3;
			}
			else
				g_map[pos.x][pos.y] = 0;
		}
	}
	if (g_map[pos.x][pos.y + 1] == 7)
	{
		if (g_map[pos.x][pos.y + 2] == 0)
		{
			g_map[pos.x][pos.y + 2] = 4;	
			g_map[pos.x][pos.y + 1] = 9;		
			if (g_map[pos.x][pos.y] == 9)	
			{
				g_map[pos.x][pos.y] = 3;
			}
			else
				g_map[pos.x][pos.y] = 0;
		}
		if (g_map[pos.x][pos.y + 2] == 3)
		{
			g_map[pos.x][pos.y + 2] = 7;	
			g_map[pos.x][pos.y + 1] = 9;		
			if (g_map[pos.x][pos.y] == 9)	
			{
				g_map[pos.x][pos.y] = 3;
			}
			else
				g_map[pos.x][pos.y] = 0;
		}
	}
}
void left()
{
	POINT pos = GetGamerPostion();
	if (g_map[pos.x][pos.y - 1] == 0)
	{
		g_map[pos.x][pos.y - 1] = 6;		
		if (g_map[pos.x][pos.y] == 9)		
		{
			g_map[pos.x][pos.y] = 3;
		}
		else
			g_map[pos.x][pos.y] = 0;
	}
	if (g_map[pos.x][pos.y - 1] == 3)
	{
		g_map[pos.x][pos.y - 1] = 9;		
		if (g_map[pos.x][pos.y] == 9)	
		{
			g_map[pos.x][pos.y] = 3;
		}
		else
			g_map[pos.x][pos.y] = 0;
	}
	if (g_map[pos.x][pos.y - 1] == 4)
	{
		if (g_map[pos.x][pos.y - 2] == 0)
		{
			g_map[pos.x][pos.y - 2] = 4;		
			g_map[pos.x][pos.y - 1] = 6;		
			if (g_map[pos.x][pos.y] == 9)	
			{
				g_map[pos.x][pos.y] = 3;
			}
			else
				g_map[pos.x][pos.y] = 0;
		}
		if (g_map[pos.x][pos.y - 2] == 3)
		{
			g_map[pos.x][pos.y - 2] = 7;		
			g_map[pos.x][pos.y - 1] = 6;	
			if (g_map[pos.x][pos.y] == 9)	
			{
				g_map[pos.x][pos.y] = 3;
			}
			else
				g_map[pos.x][pos.y] = 0;
		}
	}
	if (g_map[pos.x][pos.y - 1] == 7)
	{
		if (g_map[pos.x][pos.y - 2] == 0)
		{
			g_map[pos.x][pos.y - 2] = 4;	
			g_map[pos.x][pos.y - 1] = 9;		
			if (g_map[pos.x][pos.y] == 9)		
			{
				g_map[pos.x][pos.y] = 3;
			}
			else
				g_map[pos.x][pos.y] = 0;
		}
		if (g_map[pos.x][pos.y - 2] == 3)
		{
			g_map[pos.x][pos.y - 2] = 7;		
			g_map[pos.x][pos.y - 1] = 9;	
			if (g_map[pos.x][pos.y] == 9)		
			{
				g_map[pos.x][pos.y] = 3;
			}
			else
				g_map[pos.x][pos.y] = 0;
		}
	}
}
int gameOver()
{
	int	k=0;
	if(count>=0){
		if (g_map[3][10] == 7 && g_map[4][10]==7 && g_map[5][10]==7)
		{
			printf("获得胜利");
			k=1; 
		}
	}
	if(count<0){
		printf("失败!");
	}
	return	k;
}


POINT GetGamerPostion()
{
	POINT pos = { -1, -1 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (g_map[i][j] == 6 || g_map[i][j] == 9)
			{
				pos.x = i;
				pos.y = j;
				return pos;
			}
		}
	}
	return pos;
}

