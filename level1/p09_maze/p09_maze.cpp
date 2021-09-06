#include <cstdio>
#include <windows.h>
#define isPressed(x) (GetKeyState(x) < 0)
using namespace std;
const int N = 9, M = 9;
const char maze[N][M + 1] = {
	"*********",
	"* * *   *",
	"* * * ***",
	"*       *",
	"** **** *",
	"*  *    *",
	"* ** ****",
	"* *    @*",
	"*********",
};
const char dir[4] = {VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT};
const int sftx[4] = {-1, 1, 0, 0};
const int sfty[4] = {0, 0, -1, 1};

int x = 1, y = 1;

void print(){
	system("cls");
	puts("*£ºÍæ¼Ò @£º³ö¿Ú");
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(i == x && j == y) putchar('*');
			else if(maze[i][j] == '*') printf("¨„");
			else putchar(maze[i][j]);
		}
		putchar('\n');
	}
}

int main(){
	print();
	while(x != N - 2 || y != M - 2) if(GetForegroundWindow() == GetConsoleWindow()){
		int state = 0;
		for(int i = 0; i < 4; i++)
			state |= ((int) isPressed(dir[i])) << i;
		if(__builtin_popcount(state) == 1){
			int d = __builtin_ctz(state);
			int nx = x + sftx[d], ny = y + sfty[d];
			if(maze[nx][ny] != '*'){
				x = nx, y = ny;
				print();
			}
		}
	}
	puts("You Win!");
	system("pause");
	return 0;
}
