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
	};//��ʼ����ͼ
	printf("*********************************************\n");
	printf("*******  ��ӭ����ȫ����˵���������Ϸ  ******\n");
	printf("*******      ����wasd�������ơ�o'      ******\n");
	printf("*******    ����#���ƶ�����+������ʤ    ******\n");
	printf("*********************************************\n");
	Sleep(2000);
	system("cls");
	printf("*********************************************\n");
	printf("*******        ���������ʼ��Ϸ        ******\n");
	printf("*********************************************\n");
	system("pause");//��ʼ��Ϸ
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
	}//������ʽ
	system("cls");
	printf("*********************************************\n");
	printf("************ ��ϲ��ͨ���ˣ�������************\n");
	printf("*********************************************\n");
	system("pause");//ͨ���ж�
	return 0;
}