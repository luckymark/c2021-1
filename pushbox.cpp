//本项目基于控制台运行，不会交sln文件，所以复制粘贴到此cpp文件中来

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

// 0：空地 1：墙 2：目的地有箱子 3:目的地没箱子 4：箱子  5：人不在目的地 6：人在目的地
int map[8][8] = {
	{0,0,1,1,1,0,0,0},
	{0,0,1,3,1,0,0,0},
	{0,0,1,0,1,1,1,1},
	{1,1,1,4,0,4,3,1},
	{1,3,0,4,5,1,1,1},
	{1,1,1,1,4,1,0,0},
	{0,0,0,1,3,1,0,0},
	{0,0,0,1,1,1,0,0}
};
int num = 0;

void draw();
void game();
void getNum();
bool judgeWin();
int main()
{
	draw();
	getNum();
	while (judgeWin())
	{
		game();
		draw();
	}
	MessageBox(NULL, "You win!!!", "Winner!!!", MB_OK);

	getchar();

	return 0;
}

void draw()
{
	system("cls");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			switch (map[i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("■");
				break;
			case 2:
				printf("★");
				break;
			case 3:
				printf("☆");
				break;
			case 4:
				printf("◇");
				break;
			case 5:
				printf("♀");
				break;
			case 6:
				printf("♂");
				break;
			}
		}
		printf("\n");
	}
}

void game()
{
	char ch;
	int m, n;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[i][j] == 5)
			{
				m = i;
				n = j;
			}
		}
	}
	ch = _getch();
	switch (ch)
	{
	case'W':
	case'w':
	case 72:
		if (map[m - 1][n] == 0)
		{
			map[m][n] = 0;
			map[m - 1][n] = 5;
		}
		else if (map[m - 1][n] == 3)
		{
			map[m][n] = 0;
			map[m - 1][n] = 6;
		}
		else if (map[m - 1][n] = 4)
		{
			if (map[m - 2][n] == 0)
			{
				map[m][n] = 0;
				map[m - 1][n] = 5;
				map[m - 2][n] = 4;
			}
			else if (map[m - 2][n] == 3)
			{
				map[m][n] = 0;
				map[m - 1][n] = 5;
				map[m - 2][n] = 2;
			}
		}
		else if (map[m - 1][n] = 2)
		{
			if (map[m - 2][n] == 0)
			{
				map[m][n] = 0;
				map[m - 1][n] = 6;
				map[m - 2][n] = 4;
			}
			else if (map[m - 2][n] == 3)
			{
				map[m][n] = 0;
				map[m - 1][n] = 6;
				map[m - 2][n] = 2;
			}
		}
		break;
	case'S':
	case's':
	case 80:
		if (map[m + 1][n] == 0)
		{
			map[m][n] = 0;
			map[m + 1][n] = 5;
		}
		else if (map[m + 1][n] == 3)
		{
			map[m][n] = 0;
			map[m + 1][n] = 6;
		}
		else if (map[m + 1][n] = 4)
		{
			if (map[m + 2][n] == 0)
			{
				map[m][n] = 0;
				map[m + 1][n] = 5;
				map[m + 2][n] = 4;
			}
			else if (map[m + 2][n] == 3)
			{
				map[m][n] = 0;
				map[m + 1][n] = 5;
				map[m + 2][n] = 2;
			}
		}
		else if (map[m + 1][n] = 2)
		{
			if (map[m + 2][n] == 0)
			{
				map[m][n] = 0;
				map[m + 1][n] = 6;
				map[m + 2][n] = 4;
			}
			else if (map[m + 2][n] == 3)
			{
				map[m][n] = 0;
				map[m + 1][n] = 6;
				map[m + 2][n] = 2;
			}
		}
		break;
	case'A':
	case'a':
	case 75:
		if (map[m][n - 1] == 0)
		{
			map[m][n] = 0;
			map[m][n - 1] = 5;
		}
		else if (map[m][n - 1] == 3)
		{
			map[m][n] = 0;
			map[m][n - 1] = 6;
		}
		else if (map[m][n - 1] = 4)
		{
			if (map[m][n - 2] == 0)
			{
				map[m][n] = 0;
				map[m][n - 1] = 5;
				map[m][n - 2] = 4;
			}
			else if (map[m][n - 2] == 3)
			{
				map[m][n] = 0;
				map[m][n - 1] = 5;
				map[m][n - 2] = 2;
			}
		}
		else if (map[m][n - 1] = 2)
		{
			if (map[m][n - 2] == 0)
			{
				map[m][n] = 0;
				map[m][n - 1] = 6;
				map[m][n - 2] = 4;
			}
			else if (map[m][n - 2] == 3)
			{
				map[m][n] = 0;
				map[m][n - 1] = 6;
				map[m][n - 2] = 2;
			}
		}
		break;
	case'D':
	case'd':
	case 77:
		if (map[m][n + 1] == 0)
		{
			map[m][n] = 0;
			map[m][n + 1] = 5;
		}
		else if (map[m][n + 1] == 3)
		{
			map[m][n] = 0;
			map[m][n + 1] = 6;
		}
		else if (map[m][n + 1] = 4)
		{
			if (map[m][n + 2] == 0)
			{
				map[m][n] = 0;
				map[m][n + 1] = 5;
				map[m][n + 2] = 4;
			}
			else if (map[m][n + 2] == 3)
			{
				map[m][n] = 0;
				map[m][n + 1] = 5;
				map[m][n + 2] = 2;
			}
		}
		else if (map[m][n + 1] = 2)
		{
			if (map[m][n + 2] == 0)
			{
				map[m][n] = 0;
				map[m][n + 1] = 6;
				map[m][n + 2] = 4;
			}
			else if (map[m][n + 2] == 3)
			{
				map[m][n] = 0;
				map[m][n + 1] = 6;
				map[m][n + 2] = 2;
			}
		}
		break;
	}
}

void getNum()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[i][j] == 3)
			{
				num++;
			}
		}
	}
}

bool judgeWin()
{

	int win = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[i][j] == 2)
			{
				win++;
			}
		}
	}
	if (win == num)
	{
		return false;
	}
	else
	{
		return true;
	}
}