#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

#define WALL 0
#define ROUTE 1

#define N 20+4

void initmaze(int**);

void dig(int** , int , int);

void digmaze(int**);

void operatemaze(int**,int,int);

void swap(int*, int*);

void printmaze(int**);

int main(void) 
{
	srand((unsigned)time(NULL));

	int** maze;
	maze = (int**)calloc(N, N * sizeof(int));
	for (int i = 0; i < N; i++)
	{
		maze[i] = (int*)calloc(N, sizeof(int));
	}
	
	initmaze(maze);
	digmaze(maze);
	operatemaze(maze, 2, 2);
	return 0;
}

void dig(int** maze, int x, int y) 
{
	if (maze[x][y] == WALL)
	{
		if (maze[x + 1][y] + maze[x - 1][y] + maze[x][y + 1] + maze[x][y - 1] <= ROUTE) 
		{
			maze[x][y] = ROUTE;

			int direction[4] = { 0,1,2,3 };
			for (int i = 4; i > 0; --i)
			{
				int r = rand() % i;
				swap(&direction[r], &direction[i - 1]);

				switch (direction[i - 1])
				{
				case 0:
					dig(maze, x - 1, y);
					//break;
				case 1:
					dig(maze, x + 1, y);
					//break;
				case 2:
					dig(maze, x, y - 1);
					//break;
				case 3:
					dig(maze, x, y + 1);
					//break;
				default:
					break;
				}
			}
		}
	}
}

void digmaze(int** maze)
{
	while (maze[N - 3][N - 3] != 1)
	{
		initmaze(maze);
		dig(maze, 2, 2);
	}
	maze[2][2] = 2;
}

void printmaze(int** maze)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (maze[i][j] == ROUTE)
			{
				printf("  ");
			}
			else if (maze[i][j]==WALL)
			{
				printf("Ç½");
			}
			else
			{
				printf("ÎÒ");
			}
			if (j == N - 1)
			{
				printf("\n");
			}
		}
	}
}

void operatemaze(int**maze,int i, int j)
{
	Sleep(150);

	system("cls");
	printmaze(maze);
	if (maze[N - 3][N - 3] == 2)
	{
		printf("you succeed");
		return ;
	}

	switch (_getch())
	{
	case 'w':
		if (maze[i - 1][j] != 0) 
		{
			swap(&maze[i][j], &maze[i - 1][j]);
			operatemaze(maze, i - 1, j);
		}
		else {
			operatemaze(maze, i, j);
		}
		break;
	case 'a':
		if (maze[i][j - 1] != 0)
		{
			swap(&maze[i][j], &maze[i][j - 1]);
			operatemaze(maze, i , j - 1);
		}
		else {
			operatemaze(maze, i, j);
		}
		break;
	case 's':
		if (maze[i + 1][j] != 0)
		{
			swap(&maze[i][j], &maze[i + 1][j]);
			operatemaze(maze, i + 1 , j);
		}
		else {
			operatemaze(maze, i, j);
		}
		break;
	case 'd':
		if (maze[i][j + 1] != 0)
		{
			swap(&maze[i][j], &maze[i][j + 1]);
			operatemaze(maze, i, j + 1);
		}
		else {
			operatemaze(maze, i, j);
		}
		break;
	default:
		operatemaze(maze, i , j);
		break;
	}
}

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void initmaze(int** maze)
{
	for (int i = 0; i < N; ++i)
	{
		maze[i][N - 1] = ROUTE;
		maze[N - 1][i] = ROUTE;
		maze[i][0] = ROUTE;
		maze[0][i] = ROUTE;
	}
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < N - 1; j++)
		{
			maze[i][j] = WALL;
		}
	}
}



