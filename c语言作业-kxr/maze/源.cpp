#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>

int main() {
	int ch,x=3,y=8,x_=0;
	char map[50][50] = {
		"       *****#***",
		"       ** **   *",
		"       ** **** *",
		"       *o ***  *",
		"       **   * **",
		"       **** * **",
		"       ***    **",
		"       *********",
	};
	printf("**************************************************\n");
	printf("*********   欢迎来到全班最菜的迷宫   *************\n");
	printf("*******  靠wasd移动‘o’，到#处即可通关  *********\n");
	printf("**************************************************\n");
	Sleep(2000);
	system("cls");
	printf("**************************************************\n");
	printf("*********      按下任意键即可开始游戏    *********\n");
	printf("**************************************************\n");
	system("pause");
	system("cls");
	for (int i = 0; i < 17; i++)
		puts(map[i]);
	while(x!=0||y!=12) {
		ch = _getch();
		if (ch == 's') {
			x_ = x + 1;
			if (map[x_][y] != '*') {
				map[x][y] = ' ';
				x = x_;
				map[x][y] = 'o';
				system("cls");
				for (int i = 0; i < 17; i++)
					puts(map[i]);
			}
		}
		else if (ch == 'a') {
			x_ = y - 1;
			if (map[x][x_] != '*') {
				map[x][y] = ' ';
				y = x_;
				map[x][y] = 'o';
				system("cls");
				for (int i = 0; i < 17; i++)
					puts(map[i]);
			}
		}
		else if (ch == 'w') {
			x_ = x - 1;
			if (map[x_][y] != '*') {
				map[x][y] = ' ';
				x = x_;
				map[x][y] = 'o';
				system("cls");
				for (int i = 0; i < 17; i++)
					puts(map[i]);
			}
		}
		else if (ch == 'd') {
			x_ = y + 1;
			if (map[x][x_] != '*') {
				map[x][y] = ' ';
				y = x_;
				map[x][y] = 'o';
				system("cls");
				for (int i = 0; i < 17; i++)
					puts(map[i]);
			}
		}
	}
	system("cls");
	printf("**************************************************\n");
	printf("****               恭喜你通关了！             ****\n");
	printf("**************************************************\n");
	system("pause");
	return 0;
}