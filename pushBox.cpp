#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<graphics.h>
#define N 15
#define M 3  //�ؿ���

//ȫ�ֱ���
int level = 0;
int x, y;
int step = 0;
int map[M][N][N] = {
	{		   //
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,0,1,1,1,1,1,4,0,0,0},
	{1,1,1,1,1,0,1,5,1,0,0,0,0,0,0},
	{1,1,1,1,1,0,1,1,3,0,0,0,0,0,0},
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
},
{
    {1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,0,1,1,1,1,1,1,1,0,0},
	{1,1,1,1,1,0,1,1,1,5,1,1,1,0,0},
	{1,1,1,1,1,0,1,1,1,4,1,1,1,0,0},
	{1,1,1,1,1,0,1,1,1,1,1,1,1,0,0},
	{1,1,1,1,1,0,1,1,1,3,1,1,1,0,0},
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
},
	{
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,0,1,1,1,1,1,1,1,0,0},
	{1,1,1,1,1,0,1,1,0,0,0,1,1,0,0},
	{1,1,1,1,1,0,1,1,0,4,1,5,1,0,0},
	{1,1,1,1,1,0,1,1,0,0,0,1,1,0,0},
	{1,1,1,1,1,0,1,1,1,3,1,1,1,0,0},
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
}
};


//��������
void print(int step);
void menu();
void find();
int move();
int Up();
int Down();
int Right();
int Left();


int main(void)
{
	int flag = 0;
	system("color 0A");
	menu();
	while (1)
	{

		flag = move();
		if (flag == 1 || flag == -1)
			return 0;
	}
	return 0;
}
//�ҵ��Լ���λ��
void find()
{

	int i = 0, j = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (map[level][i][j] == 3)
			{
				x = i;
				y = j;
				break;
			}
		}
	}
}
int move()
{
	int flag = 0;
	while (1)
	{
		ExMessage key;
		flag = 0;
		find();
		
		char c;
		if (_kbhit()) {
			c = _getch();
			switch (c)//���հ�������
			{
			case 'w':flag = Up(); break;
			case 'a':flag = Left(); break;
			case 's':flag = Down(); break;
			case 'd':flag = Right(); break;
			case 27:return -1;
			}
			print(step);
			if (flag == 1)
			{
				step = 0;
				//ͨ����
				if (level == M - 1)
				{
					MessageBox(0, TEXT("��ϲ����������йؿ�"), TEXT("��ϲ"), NULL);
					
					return 1;
				}
				else
				{
					MessageBox(0, TEXT("��ϲ��ͨ������һ��,ȷ�Ϻ�س�������һ��"), TEXT("��ϲ"), NULL);
					level++;
				}
			}
		}
	}
}
int Up()
{
	if (x != 0)
	{
		step++;
		if (map[level][x - 1][y] == 1)//����
		{
			map[level][x - 1][y] = 3;
			map[level][x][y] = 1;
		}
		else if (map[level][x - 1][y] == 5&& map[level][x - 2][y] == 1) {
			map[level][x - 2][y] = 5;
			map[level][x - 1][y] = 3;
			map[level][x][y] = 1;
		}
		else if (map[level][x - 2][y] == 4&& map[level][x - 1][y] == 5)
		{
			map[level][x - 2][y] = 5;
			map[level][x - 1][y] = 3;
			map[level][x][y] = 1;
			return 1;
		}
	}
	return 0;
}
int Down()
{
	if (x != N - 1)
	{
		step++;
		if (map[level][x + 1][y] == 1)//����
		{
			map[level][x + 1][y] = 3;
			map[level][x][y] = 1;
		}
		else if (map[level][x + 1][y] == 5 && map[level][x + 2][y] == 1) {
			map[level][x + 2][y] = 5;
			map[level][x + 1][y] = 3;
			map[level][x][y] = 1;
		}
		else if (map[level][x + 2][y] == 4&&map[level][x + 1][y] == 5)
		{
			map[level][x + 2][y] = 5;
			map[level][x + 1][y] = 3;
			map[level][x][y] = 1;
			return 1;
		}
	}
	return 0;
}
int Right()
{
	if (y != N - 1)
	{
		step++;
		if (map[level][x][y + 1] == 1)//����
		{
			map[level][x][y + 1] = 3;
			map[level][x][y] = 1;
		}
		else if (map[level][x][y + 1] == 5 && map[level][x][y + 2] == 1) {
			map[level][x][y + 2] = 5;
			map[level][x][y + 1] = 3;
			map[level][x][y] = 1;
		}
		else if (map[level][x][y + 2] == 4&&map[level][x][y + 1] == 5)
		{
			map[level][x][y + 2] = 5;
			map[level][x][y + 1] = 3;
			map[level][x][y] = 1;
			return 1;
		}
	}
	return 0;
}
int Left()
{
	if (y != 0)
	{
		step++;
		if (map[level][x][y - 1] == 1)//����
		{
			map[level][x][y - 1] = 3;
			map[level][x][y] = 1;
		}
		else if (map[level][x][y - 1] == 5&& map[level][x][y - 2] == 1) {
			map[level][x][y - 2] = 5;
			map[level][x][y - 1] = 3;
			map[level][x][y] = 1;
		}
		else if (map[level][x][y - 2] == 4&&map[level][x][y - 1] == 5)
		{
			map[level][x][y - 2] = 5;
			map[level][x][y - 1] = 3;
			map[level][x][y] = 1;
			return 1;
		}
	}
	return 0;
}
void menu()
{
	char select[10];
	printf("�ֱ���wasd���������ƶ�����Esc�˳���Ϸ,�����ǡ���ע��ʶ��\n");
	printf("��������Ϸ�ؿ�(1��2��3):");
	while (1)
	{
		scanf_s("%s", select,2);
		if (strlen(select) > 1)
		{
			printf("�������룬���������룺");
		}
		else
		{
			if ('1' == select[0])
			{
				level = 0;
				break;
			}
			else if ('2' == select[0])
			{
				level = 1;
				break;
			}
			else if ('3' == select[0])
			{
				level = 2;
				break;
			}
			else
			{
				printf("�������룬���������룺");
			}
		}
	}
	printf("�ٴλس�ȷ�ϣ�ע�����뷨\n");
}
//��ӡ����
void print(int num)
{
	int i = 0, j = 0;
	system("cls");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (map[level][i][j] == 0)
				printf("��");
			else if (map[level][i][j] == 1)
				printf("  ");
			else if (map[level][i][j] == 3)
				printf("��");
			else if (map[level][i][j] == 4)
				printf("��");
			else if (map[level][i][j] == 5)
				printf("��");
		}
		printf("\n");
	}
	printf("����%d", num);
}