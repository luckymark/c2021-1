#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>

#define WALL 0
#define BOX 2
#define CHARA 3
#define CHARA_END 6
#define ROUTE 1
#define SIZE 8
#define END 4
#define W 5
FILE *map1;
FILE *map2;
FILE *map3;
FILE *score;

void CREATEMAZE(int *x, int *y);//创建地图
void menu();   //主菜单界面
void start();  //开始游戏
char degree(); //游戏难度
void move(int maze[SIZE][SIZE], char t, int *x, int *y);//移动角色
int win(int maze[SIZE][SIZE]);
int anciiToInt(int);
char *guanp;
int maze[SIZE][SIZE] =
{
{0},
{0,0,0,4},
{0,0,0,1},
{0,0,0,2,1,2,4,0},
{0,4,1,2,3,0,0,0},
{0,0,0,0,2},
{0,0,0,0,4},
{0}
};
int main()
{
    degree();
	menu();
	return 0;
}
void CREATEMAZE(int *x,int *y)
{
	
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			switch (maze[i][j])
			{
			case WALL:printf("回");
				break;//表示墙体
			case ROUTE:printf("  ");
				break;//表示道路
			case CHARA:
			case CHARA_END:printf("十");
				*x = i;
				*y = j;
				break;//表示玩家
			case BOX:printf("箱");
				break;
			case END:printf("**");
				break;
			case W:printf("￥");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
}
void menu() { //主菜单
	while (1) {
		system("cls"); //清屏
		char t;
		printf("*******(推箱子)*******");
		printf("\n======================\n");
		printf("\n||   1. 开始游戏   ||\n");
		printf("\n||   2. 调整难度   ||\n");
		printf("\n||   3. 关闭游戏   ||\n");
		printf("======================\n");
		t = _getch();    //不回显函数
		switch (t) {
		case '1':
			start();
			break;  //开始一局游戏

		case '2':
			degree();
			break;  //调整游戏难度
		case '3':
			printf("\n欢迎下次再玩，再见（￣︶￣）↗");
			Sleep(1500);
			exit(0);
			break;  //结束程序
		default:
			break;
		}
	}
}
char degree() { //调整游戏难度
	while (1) {
		char guan;
		int i = 0;
		int j = 0;
		system("cls");
		printf("=======================\n");
		printf("输入1,2,3进行难度调整：\n");
		printf("\n||    1.简  单    ||\n");
		printf("\n||    2.中  等    ||\n");
		printf("\n||    3.困  难    ||\n");
		printf("=======================\n");
		guan = _getch();
		guanp = &guan;
		switch (guan) {
		case '1':
			fopen_s(&map1, "map1.txt", "r");
			for (; i < SIZE; i++)
			{
				j = 0;
				for (; j < SIZE; j++)
				{
					maze[i][j] = anciiToInt(fgetc(map1));
				}
			}
			printf("\n当前难度：简单，即将返回主菜单……");
			Sleep(1500);
			fclose(map1);
			menu();//返回主菜单
			break;
		case '2':
			fopen_s(&map2, "map2.txt", "r");
			for (; i < SIZE; i++)
			{
				j = 0;
				for (; j < SIZE; j++)
				{
					maze[i][j] = anciiToInt(fgetc(map2));
				}
			}
				printf("\n当前难度：中等，即将返回主菜单……");
				Sleep(1500);
				fclose(map2);
				menu();//返回主菜单
				break;
		case '3':
			fopen_s(&map3, "map3.txt", "r");
			for (; i < SIZE; i++)
			{
				j = 0;
				for (; j < SIZE; j++)
				{
					maze[i][j] = anciiToInt(fgetc(map3));
				}
			}
			printf("\n当前难度：困难，即将返回主菜单……");
			fclose(map3);
			Sleep(1500);
			menu();//返回主菜单
			break;
		case 27:
			menu();
			break;
		default:
			break;
			}
	}
}
void start() { //开始一局游戏
	char t;
	int x=1,y=2,count=0;//count计分
	int *p=&x, *q=&y;
	system("cls");
	CREATEMAZE(p,q);
	while (t = _getch()) {
		if (t == 27)   //如果输入为ESC键，结束游戏回到主菜单
			break;
		system("cls");//清屏
		move(maze, t, p, q);//根据输入t进行移动
		count++;
		CREATEMAZE(p, q);//重新绘制迷宫
		int k =win(maze);
		if (k==0) {//
			system("cls");
			printf("=============\n");
			printf("游 戏 胜 利！\n");
			printf("第%d关您一共使用%d步\n",*guanp-48,count);
			fopen_s(&score, "score.txt", "a+");
			fprintf(score, "%s%d%s%d%s", "第",*guanp-48,"关您一共使用",count,"步\n");
			fclose(score);
			printf("即将后返回主菜单……");
			Sleep(1500);//执行挂起一段时间，暂停1.5秒后打印
			break;
		}
	}
}
void move(int maze[SIZE][SIZE], char t, int *x, int *y)
{
	int i = *x, j = *y;//记录原始位置
	switch (t) {
	case 'w':    //向上移动
		*x -= 1;
		break;
	case 's':    //向下移动
		*x += 1;
		break;
	case 'a':    //向左移动
		*y -= 1;
		break;
	case 'd':    //向右移动
		*y += 1;
		break;
	default:
		break;
	}
	if (maze[i][j] != CHARA_END)
	{
		if (maze[*x][*y] == ROUTE)
		{
			maze[*x][*y] = CHARA;
			maze[i][j] = ROUTE;
		}
		else if (maze[*x][*y] == BOX)
		{
			int a = *x;
			int b = *y;
			switch (t) {
			case 'w':    //向上移动
				*x -= 1;
				break;
			case 's':    //向下移动
				*x += 1;
				break;
			case 'a':    //向左移动
				*y -= 1;
				break;
			case 'd':    //向右移动
				*y += 1;
				break;
			default:
				break;
			}
			if (maze[*x][*y] == ROUTE)
			{
				maze[*x][*y] = BOX;
				maze[a][b] = CHARA;
				maze[i][j] = ROUTE;
			}
			else if (maze[*x][*y] == END)
			{
				maze[*x][*y] = W;
				maze[a][b] = CHARA;
				maze[i][j] = ROUTE;
			}
			else
			{
				*x = i;
				*y = j;
			}
		}
		else if (maze[*x][*y] == W)
		{
			int a = *x;
			int b = *y;
			switch (t) {
			case 'w':    //向上移动
				*x -= 1;
				break;
			case 's':    //向下移动
				*x += 1;
				break;
			case 'a':    //向左移动
				*y -= 1;
				break;
			case 'd':    //向右移动
				*y += 1;
				break;
			default:
				break;
			}
			if (maze[*x][*y] == ROUTE)
			{
				maze[*x][*y] = BOX;
				maze[a][b] = CHARA_END;
				maze[i][j] = ROUTE;
			}
			else if (maze[*x][*y] == END)
			{
				maze[*x][*y] = W;
				maze[a][b] = CHARA_END;
				maze[i][j] = ROUTE;
			}
			else
			{
				*x = i;
				*y = j;
			}
		}
		else if (maze[*x][*y] == END)
		{
			maze[*x][*y] = CHARA_END;
			maze[i][j] = ROUTE;
		}
		else
		{
			*x = i;
			*y = j;
		}
	}
	else 
	{
		if (maze[*x][*y] == ROUTE)
		{
			maze[*x][*y] = CHARA;
			maze[i][j] = END;
		}
		else if (maze[*x][*y] == BOX)
		{
			int a = *x;
			int b = *y;
			switch (t) {
			case 'w':    //向上移动
				*x -= 1;
				break;
			case 's':    //向下移动
				*x += 1;
				break;
			case 'a':    //向左移动
				*y -= 1;
				break;
			case 'd':    //向右移动
				*y += 1;
				break;
			default:
				break;
			}
			if (maze[*x][*y] == ROUTE)
			{
				maze[*x][*y] = BOX;
				maze[a][b] = CHARA;
				maze[i][j] = END;
			}
			else if (maze[*x][*y] == END)
			{
				maze[*x][*y] = W;
				maze[a][b] = CHARA;
				maze[i][j] = END;
			}
			else
			{
				*x = i;
				*y = j;
			}
		}
		else if (maze[*x][*y] == W)
		{
			int a = *x;
			int b = *y;
			switch (t) {
			case 'w':    //向上移动
				*x -= 1;
				break;
			case 's':    //向下移动
				*x += 1;
				break;
			case 'a':    //向左移动
				*y -= 1;
				break;
			case 'd':    //向右移动
				*y += 1;
				break;
			default:
				break;
			}
			if (maze[*x][*y] == ROUTE)
			{
				maze[*x][*y] = BOX;
				maze[a][b] = CHARA_END;
				maze[i][j] = END;
			}
			else if (maze[*x][*y] == END)
			{
				maze[*x][*y] = W;
				maze[a][b] = CHARA_END;
				maze[i][j] = END;
			}
			else
			{
				*x = i;
				*y = j;
			}
		}
		else if (maze[*x][*y] == END)
		{
			maze[*x][*y] = CHARA_END;
			maze[i][j] = END;
		}
		else
		{
			*x = i;
			*y = j;
		}
	}

}
int win(int maze[SIZE][SIZE])
{
	int k = 0;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (maze[i][j] == END|| maze[i][j] == CHARA_END)
					k++;
			}
		}
	return k;
}

int anciiToInt(int ascii) {
	switch (ascii)
	{
	case 48:
		return 0;
	case 49:
		return 1;
	case 50:
		return 2;
	case 51:
		return 3;
	case 52:
		return 4;
	case 53:
		return 5;
	case 54:
		return 6;
	case 10:
		return 0;
	default:
		return 0;
		break;
	}
}