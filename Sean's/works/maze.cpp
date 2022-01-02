#include<ctime>
#include<string>
#include<vector>
#include<cstdio>
#include<conio.h>
#include<windows.h>
#include<algorithm>
using namespace std;

const int MAX = 21;

vector<pair<int, int>> node;
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };
int head,vis[MAX][MAX],maze[MAX][MAX];

void PUTS() {
	wstring A;
	wstring B = L"NOTICE";
	A = L"Congratulation!You find the way!";
	LPCWSTR a = A.c_str(), b = B.c_str();
	MessageBox(NULL, a, b, NULL);
}

void Build() {
	srand((int)time(NULL));
	int x, y, nex, ney;
	head = 0;
	node.push_back(make_pair(1, 1));	
	while (head<node.size()) {
		random_shuffle(node.begin() + head, node.end());
		x = node[head].first;
		y = node[head].second;
		++head;
		if (vis[x][y] >= 2) continue;
		maze[x][y] = 1; 
		for (int i = 1; i <= 4; ++i) {
			nex = x + dx[i], ney = y + dy[i];
			if (nex < 1 || nex >= MAX-1 || ney < 1 || ney >= MAX-1) continue;
			if (!maze[nex][ney]) {
				if (!vis[nex][ney]) node.push_back(make_pair(nex, ney));
				++vis[nex][ney];			
			}
		}
	}
	maze[x][y] = 2;
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j)
			if (!maze[i][j]) printf("$");
			else {
				if (i == 1 && j == 1) printf("U");
				else if (i == x && j == y) printf("O");
				else printf(" ");
			}
		printf("\n");
	}
	return;
}
//迷宫随机生成算法：BFS，随机选取节点拓展，不能形成闭环

bool Ending(int x, int y) {
	if (maze[x][y] == 2) {
		PUTS();
		return true;
	}		
	return false;
}

void MoveTo(int x,int y) {
	COORD position;
	position.X = x, position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
	printf("U");
}

void Eliminate(int x, int y) {
	COORD position;
	position.X = x, position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	printf(" ");
}

void Process() {
	int x,y,lx,ly;
	x = y = lx = ly = 1;
	while (1) {
		char op = _getch();		
		switch (op) {
			case 'w':--x; break;
			case 's':++x; break;
			case 'a':--y; break;
			case 'd':++y; break;
		}
		if (!maze[x][y]) {
			x = lx, y = ly;
			continue;
		}
		if (Ending(x, y)) return;
		Eliminate(ly, lx);
		MoveTo(y, x);
		lx = x, ly = y;
	}
} 

int main()
{
	Build(); 
	Process();
	system("pause");
	return 0;
}
//上下左右移动：w,a,s,d
//人的位置：U
//终点位置：O