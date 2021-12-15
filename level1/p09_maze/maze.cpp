#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h> 
#define Height 25 
#define Width 25 
#define Wall 1
#define Road 0
#define Start 2
#define End 3
#define Esc 5
#define Up 1
#define Down 2
#define Left 3
#define Right 4
#define Auto  6
int map[Height + 2][Width + 2];
int mask[Height + 2][Width + 2];
int RecordX[(Height + 2) * (Width + 2) + 10];
int RecordY[(Height + 2) * (Width + 2) + 10];
int RecordFX[(Height + 2) * (Width + 2) + 10];
int StepX[4];
int StepY[4];
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hidden()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = 0;
	SetConsoleCursorInfo(hOut, &cci);
}
void create(int x, int y)
{
	int c[4][2] = { 0,1,1,0,0,-1,-1,0 };
	int i, j, t;
	for (i = 0; i < 4; i++)
	{
		j = rand() % 4;
		t = c[i][0]; c[i][0] = c[j][0]; c[j][0] = t;
		t = c[i][1]; c[i][1] = c[j][1]; c[j][1] = t;
	}
	map[x][y] = Road;
	for (i = 0; i < 4; i++)
		if (map[x + 2 * c[i][0]][y + 2 * c[i][1]] == Wall)
		{
			map[x + c[i][0]][y + c[i][1]] = Road;
			create(x + 2 * c[i][0], y + 2 * c[i][1]);
		}
}
int get_key()
{
	char c;
	while (c = _getch())
	{
		if (c == ' ') return Auto;
		if (c == 27) return Esc;
		if (c != -32)continue;
		c = _getch();
		if (c == 72) return Up;
		if (c == 80) return Down;
		if (c == 75) return Left;
		if (c == 77) return Right;
	}
	return 0;
}
void paint(int x, int y)
{
	gotoxy(2 * y - 2, x - 1);
	switch (map[x][y])
	{
	case Start:
		printf("入"); break;
	case End:
		printf("出"); break;
	case Wall:
		printf("▇"); break;
	case Road:
		printf("  "); break;
	}
}
void game()
{
	int x = 2, y = 1;
	int c;
	int  curr_step = 0;
	int failflag = 0;
	StepX[0] = 0;
	StepY[0] = 1;
	StepX[2] = 0;
	StepY[2] = -1;
	StepX[1] = -1;
	StepY[1] = 0;
	StepX[3] = 1;
	StepY[3] = 0;
	for (int i = 0; i < Height + 2; i++)
		for (int j = 0; j < Width + 2; j++)
			mask[i][j] = 0;
	for (int i = 0; i < (Height + 2) * (Width + 2) + 10; i++)
	{
		RecordX[i] = 0;
		RecordY[i] = 0;
		RecordFX[i] = 0;
	}
	RecordX[0] = x;
	RecordY[0] = y;
	RecordFX[0] = 0;
	mask[x][y] = 1;
	c = 0;
	while (failflag == 0)
	{
		gotoxy(2 * y - 2, x - 1);
		printf("●");
		if (map[x][y] == End)
		{
			gotoxy(30, 25);
			printf("恭喜通关");
			break;
		}
		if (c != Auto)
			c = get_key();
		else Sleep(100);
		if (c == Esc)
		{
			gotoxy(0, 24);
			break;
		}
		switch (c)
		{
		case Up:
			if (map[x - 1][y] != Wall)
			{
				paint(x, y);
				x--;
				curr_step++;
				RecordX[curr_step] = x;
				RecordY[curr_step] = y;
				RecordFX[curr_step] = 0;
			}
			break;
		case Down:
			if (map[x + 1][y] != Wall)
			{
				paint(x, y);
				x++;
				curr_step++;
				RecordX[curr_step] = x;
				RecordY[curr_step] = y;
				RecordFX[curr_step] = 0;
			}
			break;
		case Left:
			if (map[x][y - 1] != Wall)
			{
				paint(x, y);
				y--;
				curr_step++;
				RecordX[curr_step] = x;
				RecordY[curr_step] = y;
				RecordFX[curr_step] = 0;
			}
			break;
		case Right:
			if (map[x][y + 1] != Wall)
			{
				paint(x, y);
				y++;
				curr_step++;
				RecordX[curr_step] = x;
				RecordY[curr_step] = y;
				RecordFX[curr_step] = 0;
			}
			break;
		case Auto:
			if (1)
			{
				int mflag = 0;
				for (int m = RecordFX[curr_step]; m < 4; m++)
				{
					int x1, y1;
					x1 = x + StepX[m];
					y1 = y + StepY[m];
					if (map[x1][y1] != Wall && mask[x1][y1] == 0)
					{
						paint(x, y);
						x = x1;
						y = y1;
						RecordFX[curr_step] = m;
						curr_step++;
						RecordX[curr_step] = x;
						RecordY[curr_step] = y;
						mask[x][y] = 1;
						RecordFX[curr_step] = 0;
						mflag = 1;
						break;
					}
					else RecordFX[curr_step] = m;
				}
				if (mflag == 0)
				{
					while (curr_step >= 0 && RecordFX[curr_step] == 3)
					{
						paint(x, y);
						mask[x][y] = 0;
						curr_step = curr_step - 1;
						x = RecordX[curr_step];
						y = RecordY[curr_step];
					}
					if (curr_step >= 0)
					{
						paint(x, y);
						mask[x][y] = 0;
						curr_step = curr_step - 1;
						x = RecordX[curr_step];
						y = RecordY[curr_step];

						RecordFX[curr_step] = RecordFX[curr_step] + 1;
					}


				}
			}
			break;
		}
	}
}
int main()
{
	int i, j;
	srand(time(NULL));
	hidden();
	for (i = 0; i <= Height + 1; i++)
		for (j = 0; j <= Width + 1; j++)
			if (i == 0 || i == Height + 1 || j == 0 || j == Width + 1)
				map[i][j] = Road;
			else map[i][j] = Wall;

	create(2 * (rand() % (Height / 2) + 1), 2 * (rand() % (Width / 2) + 1));
	for (i = 0; i <= Height + 1; i++)
	{
		map[i][0] = Wall;
		map[i][Width + 1] = Wall;
	}
	for (j = 0; j <= Width + 1; j++)
	{
		map[0][j] = Wall;
		map[Height + 1][j] = Wall;
	}
	map[2][1] = Start;
	map[Height - 1][Width] = End;
	for (i = 1; i <= Height; i++)
		for (j = 1; j <= Width; j++)
			paint(i, j);
	game();
	return 0;
}