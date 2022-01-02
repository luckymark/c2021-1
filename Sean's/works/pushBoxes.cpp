#include<cstdio>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<graphics.h>
using namespace std;

const int M = 20;
const int N = 101;

ifstream fin;
ofstream fout;
char mp[N][N];
int n,Sx,Sy,step,End[N][N];
int dx[5] = { 0,-1,1,0,0 }, dy[5] = { 0,0,0,-1,1 };


int levelchoose();
void Mapin();
void Play();
void Clear(int x, int y,int op);
void Moveto(int x,int y);
void Push(int lx,int ly,int x,int y,int tx,int ty);
int judge();
void Output(int step);
void Record();

int main()
{
	
	Mapin();
	Play();
	fin.close();fout.close();
	system("pause");
	return 0;
}

int levelchoose() {
	SetConsoleTitle((LPCSTR)"推箱子");
	initgraph(800,640);
	setbkcolor(LIGHTGRAY);
	cleardevice();
	settextstyle(30,0,_T("楷体"));
	outtextxy(160,200,_T("请按键选择您想进入的关卡："));
	outtextxy(260, 240, _T("1、简单"));
	outtextxy(260, 280, _T("2、一般"));
	outtextxy(260, 320, _T("3、困难"));
	outtextxy(260, 360, _T("4、地狱"));
	char op;
	while (1) {
		op = _getch();
		if (op >= '1' && op <= '4') break;
	}
	return op^48;
}

void Mapin() {
	int level = levelchoose();
	switch (level) {
	case 1:
		fin.open("map1.txt", ios::in);
		fout.open("record1.txt", ios::out|ios::app);
		break;
	case 2:
		fin.open("map2.txt", ios::in);
		fout.open("record2.txt", ios::out|ios::app);
		break;
	case 3:
		fin.open("map3.txt", ios::in);
		fout.open("record3.txt", ios::out|ios::app);
		break;
	case 4:
		fin.open("map4.txt", ios::in);
		fout.open("record4.txt", ios::out|ios::app);
		break;
	}
	setfillcolor(YELLOW);
	cleardevice();
	while (fin.getline(mp[++n],sizeof(mp[0]))) {
		for (int j = 0; mp[n][j] != '\0'; ++j)
			if (mp[n][j] == '$') {
				setfillcolor(YELLOW);
				fillrectangle(j * M, n * M, (j + 1) * M, (n + 1) * M);
			}
			else if (mp[n][j] == '@') {
				Sx = n, Sy = j;
				setfillcolor(LIGHTGREEN);
				solidcircle(j * M + (M >> 1), n * M + (M >> 1), M >> 2);
			}

			else if (mp[n][j] == '#') {
				setfillcolor(LIGHTRED);
				fillrectangle(j * M, n * M, (j + 1) * M, (n + 1) * M);
			}
			else if (mp[n][j] == '.') {
				End[n][j] = 1;
				rectangle(j * M, n * M, (j + 1) * M, (n + 1) * M);
				circle(j * M + (M >> 1), n * M + (M >> 1), M >> 1);
			}
			else  rectangle(j * M, n * M, (j + 1) * M, (n + 1) * M);
			
	}
}

void Play() {
	int x, y, lx, ly,dir;
	x =  Sx, y = Sy;
	outtextxy(50, 350, _T("当前步数为："));
	while (1) {
		lx = x, ly = y;
		char op = _getch();
		switch (op) {
		case 'w':--x; dir = 1; ++step; break;
		case 's':++x; dir = 2; ++step; break;
		case 'a':--y; dir = 3; ++step; break;
		case 'd':++y; dir = 4; ++step; break;
		}
		if (mp[x][y] == '-' || mp[x][y] == '.') {
			mp[x][y] = '@';
			mp[lx][ly] = '-';
			Clear(lx, ly, 1);
			Moveto(x, y);
		}
		else if (mp[x][y] == '#') {
			x = lx, y = ly;
			continue;
		}
		else if (mp[x][y] == '$') {
			int nex = x + dx[dir], ney = y + dy[dir];
			if (mp[nex][ney] == '#' || mp[nex][ney] == '$') {
				x = lx, y = ly;
				continue;
			}
			mp[lx][ly] = '-';
			mp[x][y] = '@';
			mp[nex][ney] = '$';
			Push(lx, ly, x, y, nex, ney);
		}
		Output(step);
		if (judge()) Record();
	}
}

void Clear(int x, int y,int op) {
	if (op == 1) clearcircle(y * M + (M >> 1), x * M + (M >> 1), M >> 2);
	else {
		clearrectangle(y * M, x * M, (y + 1) * M, (x + 1) * M);
		rectangle(y * M, x * M, (y + 1) * M, (x + 1) * M);
		if(End[x][y]) circle(y * M + (M >> 1), x * M + (M >> 1), M >> 1);	
	}
}


void Moveto(int x, int y) {
	setfillcolor(LIGHTGREEN);
	solidcircle(y * M + (M >> 1), x * M + (M >> 1), M >> 2);
}

void Push(int lx, int ly, int x, int y, int nex, int ney) {
	Clear(lx, ly,1);
	Clear(x, y, 2);
	Moveto(x,y);
	setfillcolor(YELLOW);
	fillrectangle(ney * M, nex * M, (ney + 1) * M, (nex + 1) * M);
}

int judge() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; mp[i][j] != '\0'; ++j)
			if (mp[i][j] == '$') 
				if (!End[i][j]) return 0;
	return 1;
}

void Output(int step) {
	char num[33] = { 0 };
	sprintf(num, "%d", step);
	outtextxy(300, 350, num);
}

void Record() {
	fout << step << endl;
	exit(0);
}