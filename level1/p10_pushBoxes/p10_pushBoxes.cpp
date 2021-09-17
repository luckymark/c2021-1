#include <cstdio>
#include <windows.h>
#define isPressed(x) (GetKeyState(x) < 0)
using namespace std;
const int N = 128, M = 128, B = 128;
const char dir[4] = {VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT};
const int sftx[4] = {-1, 1, 0, 0};
const int sfty[4] = {0, 0, -1, 1};

char file[129], maze[N][M + 1], cover[N][M + 1];
int n, m, x, y;

void print(){
	system("cls");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i == x && j == y) printf("●");
			else if(cover[i][j]) switch(cover[i][j]){
				case '#':
					printf("■");
				default:
					break;
			}else switch(maze[i][j]){
				case ' ':
					printf("　");
					break;
				case '*':
					printf("▋▋");
					break;
				case '@':
					printf("□");
				default:
					break;
			}
		}
		putchar('\n');
	}
}

bool win(){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if((cover[i][j] == '#') ^ (maze[i][j] == '@')) return false;
	return true;
}

int main(){
	printf("请输入关卡文件名（sample.txt）：");
	gets(file);
	while(!freopen(file, "r", stdin)){
		freopen("CON", "r", stdin);
		system("cls");
		printf("文件无法读取！请重新输入关卡文件名！\n请输入关卡文件名（sample.txt）：");
		gets(file);
	}
	scanf("%d%d", &n, &m);
	char c = getchar();
	while(c != '\n') c = getchar();
	for(int i = 0; i < n; i++){
		gets(maze[i]);
		for(int j = 0; j < m; j++) switch(maze[i][j]){
			case '&':
				maze[i][j] = ' ';
				x = i, y = j;
				break;
			case '#':
				cover[i][j] = '#';
				maze[i][j] = ' ';
			default:
				break;
		}
	}
	freopen("CON", "r", stdin);
	print();
	while(!win()) if(GetForegroundWindow() == GetConsoleWindow()){
		int state = 0;
		for(int i = 0; i < 4; i++)
			state |= ((int) isPressed(dir[i])) << i;
		if(__builtin_popcount(state) != 1) continue;
		int d = __builtin_ctz(state);
		int nx = x + sftx[d], ny = y + sfty[d];
		if(cover[nx][ny] == '#'){
			int px = nx + sftx[d], py = ny + sfty[d];
			if(cover[px][py] != '#' && maze[px][py] != '*'){
				cover[px][py] = '#', cover[nx][ny] = 0;
				x = nx, y = ny;
				print();
			}
		}else if(maze[nx][ny] != '*'){
			x = nx, y = ny;
			print();
		}
	}
	puts("You Win!");
	getchar();
	return 0;
}
