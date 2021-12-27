#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>

int main() {
	int ch, x = 2, y = 10,X=2,Y=11,k,m;
	char map[20][20] = {
		"         **********",
		"         **  ***+**",
		"         *o# *** **",
		"         *** *** **",
		"         **   ** **",
		"         **   ** **",
		"         *   *   **",
		"         *        *",
		"         ******  **",
		"         **********",
	};//初始化地图
	printf("*********************************************\n");
	printf("*******  欢迎来到全班最菜的推箱子游戏  ******\n");
	printf("*******      靠“wasd”来控制‘o'      ******\n");
	printf("*******    将‘#’移动到‘+’处获胜    ******\n");
	printf("*********************************************\n");
	Sleep(2000);
	system("cls");
	printf("*********************************************\n");
	printf("*******        按任意键开始游戏        ******\n");
	printf("*********************************************\n");
	system("pause");//开始游戏
	system("cls");
	for (int i = 0; i < 10; i++)
		puts(map[i]);
	while (map[1][16] != '#') {
		ch = _getch();
		if (ch == 'w') {
			k = x - 1;
			m = X - 1;
			if (map[k][y] == '#') {
				if (map[m][Y] != '*') {
					map[x][y] = ' ';
					x = X;
					y = Y;
					map[x][y] = 'o';
					X = m;
					map[X][Y] = '#';
					system("cls");
					for (int i = 0; i < 10; i++)
						puts(map[i]);
				}
			}
			else if (map[k][y] == ' ') {
				map[x][y] = ' ';
				x = k;
				map[x][y] = 'o';
				system("cls");
				for (int i = 0; i < 10; i++)
					puts(map[i]);
			}
		}
		else if (ch == 'a') {
			k = y - 1;
			m = Y - 1;
			if (map[x][k] == '#') {
				if (map[X][m] != '*') {
					map[x][y] = ' ';
					x = X;
					y = Y;
					map[x][y] = 'o';
					Y = m;
					map[X][Y] = '#';
					system("cls");
					for (int i = 0; i < 10; i++)
						puts(map[i]);
				}
			}
			else if (map[x][k] == ' ') {
				map[x][y] = ' ';
				y = k;
				map[x][y] = 'o';
				system("cls");
				for (int i = 0; i < 10; i++)
					puts(map[i]);
			}
		}
		else if (ch == 's') {
			k = x + 1;
			m = X + 1;
			if (map[k][y] == '#') {
				if (map[m][Y] != '*') {
					map[x][y] = ' ';
					x = X;
					y = Y;
					map[x][y] = 'o';
					X = m;
					map[X][Y] = '#';
					system("cls");
					for (int i = 0; i < 10; i++)
						puts(map[i]);
				}
			}
			else if (map[k][y] == ' ') {
				map[x][y] = ' ';
				x = k;
				map[x][y] = 'o';
				system("cls");
				for (int i = 0; i < 10; i++)
					puts(map[i]);
			}
		}
		else if (ch == 'd') {
			k = y + 1;
			m = Y + 1;
			if (map[x][k] == '#') {
				if (map[X][m] != '*') {
					map[x][y] = ' ';
					x = X;
					y = Y;
					map[x][y] = 'o';
					Y = m;
					map[X][Y] = '#';
					system("cls");
					for (int i = 0; i < 10; i++)
						puts(map[i]);
				}
			}
			else if (map[x][k] == ' ') {
				map[x][y] = ' ';
				y = k;
				map[x][y] = 'o';
				system("cls");
				for (int i = 0; i < 10; i++)
					puts(map[i]);
			}
		}
	}//操作方式
	system("cls");
	printf("*********************************************\n");
	printf("************ 恭喜你通关了！！！！************\n");
	printf("*********************************************\n");
	system("pause");//通关判断
	return 0;
}