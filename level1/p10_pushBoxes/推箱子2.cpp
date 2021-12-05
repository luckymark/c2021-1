#include<stdio.h>
#include<conio.h> 
#include<windows.h>
int k = 0;//判断还剩多少箱子
int map[9][11] = {
	{0,1,1,1,1,1,1,1,1,1,0},
	{0,1,0,0,0,1,0,0,0,1,0},
	{0,1,0,0,3,0,0,0,0,1,0},
	{0,1,0,3,0,3,3,3,0,1,1},
	{0,1,0,0,0,2,0,0,0,0,1},
	{1,1,0,0,1,1,1,0,3,0,1},
	{1,0,4,4,0,4,0,0,0,0,1},
	{1,0,4,4,0,4,4,3,0,1,1},
	{1,1,1,1,1,1,1,1,1,1,0}
};//原始的图表，五行六列，其中 0 代表着空白的地方； 1 代表着墙；2 代表着人；
			  //3 代表着箱子；4 代表着箱子的终点位置。 
void drawmain();
void tuidong();
int winshu();

int main()//主函数 
{
	int score = 0;
	while (1)
	{
		system("cls");//对其进行清屏 
		drawmain();
		tuidong();
		score++;
		if (0 == k) 
		{
			break;
		}
	}
	printf("你一共走了%d步",score);
	return 0;
}
//把图形刻画出来

void drawmain()
{
	int i, j;
	winshu();//调用输赢的函数 
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 11; j++)
		{
			switch (map[i][j])
			{
			case 0:
				printf("  "); //空白的地方
				break;
			case 1:
				printf("■"); //墙 
				break;
			case 2:
				printf("♀"); //人 
				break;
			case 3:
				printf("☆"); //箱子 
				break;
			case 4:
				printf("◎"); //终点地方 
				break;
			case 6:
				printf("♂");//人加终点位置 
				break;
			case 7:
				printf("★");//箱子加终点位置
				break;
			}
		}
		printf("\n");
	}
}

//进行小人的移动，整个移动的过程就是数组变化的过程 
void tuidong()
{
	int count, caw = 0;//行和列 
	int i, j, tui;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 11; j++)
		{
			if (map[i][j] == 2 || map[i][j] == 6)
			{
				count = i;
				caw = j;
			}
		}
	}

	tui = getch();
	switch (tui)
	{//上
	case 'W':
	case 'w':
	case 72:
		// 1.人的前面是空地；
		// 2.人的前面是终点位置；
		// 3.人的前面是箱子
		//3.1.箱子的前面是空地；
		//3.2.箱子的前面是终点位置。
		if (map[count - 1][caw] == 0 || map[count - 1][caw] == 4)
		{
			map[count][caw] -= 2;
			map[count - 1][caw] += 2;
		}
		else if (map[count - 1][caw] == 3 || map[count - 1][caw] == 7)
		{
			if (map[count - 2][caw] == 0 || map[count - 2][caw] == 4)
			{
				map[count][caw] -= 2;
				map[count - 1][caw] -= 1;
				map[count - 2][caw] += 3;
			}
		}
		break;

		//下 
	case 'S':
	case 's':
	case 80://键值 
		if (map[count + 1][caw] == 0 || map[count + 1][caw] == 4)
		{
			map[count][caw] -= 2;
			map[count + 1][caw] += 2;
		}

		else if (map[count + 2][caw] == 0 || map[count + 2][caw] == 4)
		{
			if (map[count + 1][caw] == 3 || map[count + 1][caw] == 7)
			{
				map[count][caw] -= 2;
				map[count + 1][caw] -= 1;
				map[count + 2][caw] += 3;
			}
		}
		break;
		//左 
	case 'A':
	case 'a':
	case 75:
		if (map[count][caw - 1] == 0 || map[count][caw - 1] == 4)
		{
			map[count][caw] -= 2;
			map[count][caw - 1] += 2;
		}

		else if (map[count][caw - 2] == 0 || map[count][caw - 2] == 4)
		{
			if (map[count][caw - 1] == 3 || map[count][caw - 1] == 7)
			{
				map[count][caw] -= 2;
				map[count][caw - 1] -= 1;
				map[count][caw - 2] += 3;
			}
		}
		break;
		//右 
	case 'D':
	case'd':
	case 77:
		if (map[count][caw + 1] == 0 || map[count][caw + 1] == 4)
		{
			map[count][caw] -= 2;
			map[count][caw + 1] += 2;
		}

		else if (map[count][caw + 2] == 0 || map[count][caw + 2] == 4)
		{
			if (map[count][caw + 1] == 3 || map[count][caw + 1] == 7)
			{
				map[count][caw] -= 2;
				map[count][caw + 1] -= 1;
				map[count][caw + 2] += 3;
			}
		}
		break;
	}
}

int  winshu()
{
	k = 0;
	int j, i;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 11; j++)
		{
			if (map[i][j] == 3)
				k++;
		}
	}
	if (k == 0)
		printf("恭喜你，你赢了！\n");
	return 0;
}

