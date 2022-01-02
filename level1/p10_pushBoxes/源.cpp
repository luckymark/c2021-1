#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<graphics.h>
#include <fstream>

#define N 12
using namespace std;

struct pos {
	int x, y;
};
pos people, boxes[10],entrance[10];

int map[N][N];
int num, numm, restart,step;
char Move;
void initialize();
void printmap(int[N][N]);
int control();
bool iswin();
int main() {
	int choice,flag=1;
	fstream file;
	ofstream out("record.txt");
	while (flag) {
		printf("请输入你想要玩的地图：1.轻松；2.简单；3.中等；4.困难\n");
		scanf_s("%d", &choice);
		switch (choice) {
			case 1:
				file.open("map1.in", ios::in, 0);
				flag = 0;
				break;
			case 2:
				file.open("map2.in", ios::in, 0);
				flag = 0;
				break;
			case 3:
				file.open("map3.in", ios::in, 0);
				flag = 0;
				break;
			case 4:
				file.open("map4.in", ios::in, 0);
				flag = 0;
				break;
			default:
				printf("请输入正确的数字！\n");
				Sleep(1000);
				break;
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			file >> map[i][j];
		}
	initialize();
	restart = 1, step = 0;
	int samemap[N][N];
	memcpy(samemap, map, sizeof(map));
	while (!iswin()) {
		if (restart) {
			memcpy(map, samemap, sizeof(map));
			initialize();
			restart = 0;
			step = 0;
		}
		if(control())
			printmap(map);
	}
	out << choice << ":" << step << endl;
	out.close();
	file.close();
	return 0;
}
void initialize() {
	initgraph(600, 400);
	num = numm = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (map[i][j] == 1) {
				setcolor(DARKGRAY);
				outtextxy((i + 2) * 20, (j + 2) * 20, _T("▓"));
			}
			else if (map[i][j] == 2) {
				setcolor(RGB(0, 255, 255));
				outtextxy((i + 2) * 20, (j + 2) * 20, _T("□"));
				boxes[++num].x = i;
				boxes[num].y = j;

			}
			else if (map[i][j] == 3) {
				setcolor(GREEN);
				outtextxy((i + 2) * 20, (j + 2) * 20, _T("◎"));
				entrance[++numm].x = i;
				entrance[numm].y = j;
			}
			else if (map[i][j] == 4) {
				setcolor(YELLOW);
				outtextxy((i + 2) * 20, (j + 2) * 20, _T("♂"));
				people.x = i, people.y = j;
			}
		}
	}
	setcolor(WHITE);
	outtextxy(20, 300, _T("W,A,S,D控制移动，R重开"));
	TCHAR str[20];
	swprintf_s(str, _TEXT("你已经走了%d步"), step);
	outtextxy(20, 320, str);
}
void printmap(int map[N][N]) {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (map[i][j] == 1) {
				setcolor(DARKGRAY);
				outtextxy((i + 2) * 20, (j + 2) * 20, _T("▓"));
			}
		}
	}
	for (int i = 1; i <= numm; i++) {
		setcolor(GREEN);
		outtextxy((entrance[i].x + 2) * 20, (entrance[i].y + 2) * 20, _T("◎"));
	}
	for (int i = 1; i <= num; i++) {
		setcolor(RGB(0, 255, 255));
		outtextxy((boxes[i].x + 2) * 20, (boxes[i].y + 2) * 20, _T("□"));
	}
	setcolor(YELLOW);
	outtextxy((people.x + 2) * 20, (people.y + 2) * 20, _T("♂"));
	setcolor(WHITE);
	outtextxy(20, 300, _T("W,A,S,D控制移动，R重开"));
}
int control() {
	int p, q, flag = 0;
	if (_kbhit())
	{
		Move = _getch();
		switch (Move)
		{
		case 'a':
			flag = 1;
			p = 0, q = 0;
			if (map[people.x - 1][people.y] == 2) {
				for (int i = 1; i <= num; i++) {
					if (boxes[i].x == people.x - 1 && boxes[i].y == people.y) {
						p = i;
					}
					if (entrance[i].x == people.x - 2 && entrance[i].y == people.y) {
						q = i;
					}
				}
				if (map[people.x - 2][people.y] == 0 || map[people.x - 2][people.y] == 3) {
					cleardevice();
					map[people.x][people.y] = 0;
					map[people.x - 1][people.y] = 4;
					map[people.x - 2][people.y] = 2;
					boxes[p].x--;
					people.x--;
				}
				step++;
			}
			else if (map[people.x - 1][people.y] == 0) {
				cleardevice();
				map[people.x][people.y] = 0;
				map[people.x - 1][people.y] = 4;
				people.x--;
				step++;
			}
			map[entrance[q].x][entrance[q].y] = 3;
			break;
		case 'd':
			flag = 1;
			p = 0, q = 0;
			if (map[people.x + 1][people.y] == 2) {
				for (int i = 1; i <= num; i++) {
					if (boxes[i].x == people.x + 1 && boxes[i].y == people.y) {
						p = i;
					}
					if (entrance[i].x == people.x + 2 && entrance[i].y == people.y) {
						q = i;
					}
				}
				if (map[people.x + 2][people.y] == 0 || map[people.x + 2][people.y] == 3) {
					cleardevice();
					map[people.x][people.y] = 0;
					map[people.x + 1][people.y] = 4;
					map[people.x + 2][people.y] = 2;
					boxes[p].x++;
					people.x++;
				}
				step++;
			}
			else if (map[people.x + 1][people.y] == 0) {
				cleardevice();
				map[people.x][people.y] = 0;
				map[people.x + 1][people.y] = 4;
				people.x++;
				step++;
			}
			map[entrance[q].x][entrance[q].y] = 3;
			break;
		case 'w':
			flag = 1;
			p = 0, q = 0;
			if (map[people.x][people.y - 1] == 2) {
				for (int i = 1; i <= num; i++) {
					if (boxes[i].x == people.x && boxes[i].y == people.y - 1) {
						p = i;
					}
					if (entrance[i].x == people.x && entrance[i].y == people.y - 1) {
						q = i;
					}
				}
				if (map[people.x][people.y - 2] == 0 || map[people.x][people.y - 2] == 3) {
					cleardevice();
					map[people.x][people.y] = 0;
					map[people.x][people.y - 1] = 4;
					map[people.x][people.y - 2] = 2;
					boxes[p].y--;
					people.y--;
				}
				step++;
			}
			else if (map[people.x][people.y - 1] == 0) {
				cleardevice();
				map[people.x][people.y] = 0;
				map[people.x][people.y - 1] = 4;
				people.y--;
				step++;
			}
			map[entrance[q].x][entrance[q].y] = 3;
			break;
		case 's':
			flag = 1;
			p = 0, q = 0;
			if (map[people.x][people.y + 1] == 2) {
				for (int i = 1; i <= num; i++) {
					if (boxes[i].x == people.x && boxes[i].y == people.y + 1) {
						p = i;
					}
					if (entrance[i].x == people.x && entrance[i].y == people.y + 2) {
						q = i;
					}
				}
				if (map[people.x][people.y + 2] == 0 || map[people.x][people.y + 2] == 3) {
					cleardevice();
					map[people.x][people.y] = 0;
					map[people.x][people.y + 1] = 4;
					map[people.x][people.y + 2] = 2;
					boxes[p].y++;
					people.y++;
				}
				step++;
			}
			else if (map[people.x][people.y + 1] == 0) {
				cleardevice();
				map[people.x][people.y] = 0;
				map[people.x][people.y + 1] = 4;
				people.y++;
				step++;
			}
			map[entrance[q].x][entrance[q].y] = 3;
			break;
		case 'r':
			restart = 1;
			break;
		default:
			break;
		}
		return flag;
	}
}
bool iswin() {
	int count = 0;
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= numm; j++) {
			if (boxes[i].x == entrance[j].x && boxes[i].y == entrance[j].y) {
				count++;
			}
		}
	if (count == numm) return true;
	else return false;
}