//Created by Mignon,2021,09,29.
#include<stdio.h>
#include<conio.h>
#define WIDETH 9
#define LENGTH 9
int map[WIDETH][LENGTH] =
{
	{1,1,1,1,1,1,1,1,1},
	{2,0,0,0,0,0,0,0,1},
	{1,1,0,1,1,1,0,0,1},
	{1,1,0,1,1,0,0,1,1},
	{1,0,0,1,0,0,0,0,1},
	{1,0,1,1,0,1,0,1,1},
	{1,0,0,1,0,1,0,0,1},
	{1,1,1,0,0,0,1,0,3},
	{1,1,1,1,1,1,1,1,1}

};
int x = 0, y = 0;
void createmap()
{
	for (int i = 0; i < WIDETH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			if (map[i][j] == 0)
			{
				printf("  ");
			}
			else if (map[i][j] == 1)
			{
				printf("墙");
			}
			else if (map[i][j] == 2)
			{
				printf("あ");
			}
			else if (map[i][j] == 3)
			{
				printf("终");
			}
		}
		printf("\n");
	}
}
void left()
{
	if (map[x][y - 1] == 1)
	{}
	else if (map[x][y - 1] == 0)
	{
		y--;
		map[x][y] = 2;
		map[x][y+1] = 0;
	}
}
void right()
{
	if(map[x][y+1]==1)
	{
		
	}
	else if (map[x][y + 1] == 0||map[x][y+1]==3)
	{
		y++;
		map[x][y] = 2;
		map[x][y-1] = 0;
	}
}
void up()
{
	if (map[x - 1][y] == 1)
	{ }
	else if (map[x - 1][y] == 0)
	{
		x--;
		map[x][y] = 2;
		map[x+1][y] = 0;
	}
}
void down()
{
	if(map[x+1][y]==1)
	{ }
	else if (map[x + 1][y]==0)
	{
		x++;
		map[x][y] = 2;
		map[x-1][y] = 0;
	}
}
int main()
{
	printf("请通过上下左右键控制“あ”，走到“终”即获得胜利\n");
	printf("按回车开始游戏：\n");
	getchar();
	x = 1;
	y = 0;
	while (map[WIDETH - 2][LENGTH - 1] != 2)
	{
		system("cls");
		createmap();
		int move;
		move = _getch();
		switch(move)
		{
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
		default:
			printf("请用上下左右控制");
			break;
		}
	}
	printf("恭喜你成功通关");
}
