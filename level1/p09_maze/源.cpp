#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int result;
int map[8][8] =//墙是0，玩家是1，终点是3 空地是2
{
		{0,0,0,0,0,0,0,0},
		{0,2,2,1,0,0,0,0},
		{0,2,0,0,2,2,2,0},
		{0,2,0,0,2,0,2,0},
		{0,2,2,2,2,0,3,0},
		{0,0,2,0,0,0,0,0},
		{0,2,2,2,2,2,2,0},
		{0,0,0,0,0,0,0,0}
};
void show()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (map[i][j] == 0)
			{
				printf("墙");
			}
			else if (map[i][j] == 1)
			{
				printf("人");
			}
			else if (map[i][j] == 2)
			{
				printf("  ");
			}
			else if (map[i][j] == 3)
			{
				printf(" @");
			}
		}
		printf("\n");
	}

};
void move()
{
	int i, j;
	char ch;
	for (i = 0; i < 8; i++)//找人
	{
		for (j = 0; j < 8; j++)
		{
			if (map[i][j] == 1 )
			{
				break;
			}
		}
		if (map[i][j] == 1 )//wenti
		{
			break;
		}
	}
	ch = _getch();
	switch (ch)//墙是0，玩家是1，终点是3 空地是2
	{
	case 'a':
		if (map[i][j - 1] != 0 && map[i][j - 1] != 3)
		{
			map[i][j] = 2;
			map[i][j - 1] = 1;
			system("cls");
			show();
		}
		if (map[i][j - 1] == 3)
		{
			system("cls");
			printf("过关了\n");
			system("pause");
			result = 9;
			break;
		}
		break;
	case 'd':
		if (map[i][j + 1] != 0 && map[i][j + 1] != 3)
		{
			map[i][j] = 2;
			map[i][j + 1] = 1;
			system("cls");
			show();
		}
		if (map[i][j + 1] == 3)
		{
			system("cls");
			printf("过关了\n");
			system("pause");
			result = 9;
			break;
		}
		break;
	case 'w':
		if (map[i - 1][j] != 0 && map[i - 1][j] != 3)
		{
			map[i][j] = 2;
			map[i-1][j] = 1;
			system("cls");
			show();
		}
		if (map[i-1][j ] == 3)
		{
			system("cls");
			printf("过关了\n");
			system("pause");
			result = 9;
			break;
		}
		break;
	case 's':
		if (map[i + 1][j] != 0 && map[i + 1][j] != 3)
		{
			map[i][j] = 2;
			map[i + 1][j] = 1;
			system("cls");
			show();
		}
		if (map[i+1][j ] == 3)
		{
			system("cls");
			printf("过关了\n");
			system("pause");
			result = 9;
			break;
		}
	default:
		break;
	}
};

int main()
{
	while (1)
	{
		show();
		move();
		if (result == 9)
		{
			return 0;
		}
		system("cls");
	}
	return 0;
}