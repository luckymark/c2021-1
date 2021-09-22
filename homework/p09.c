#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#define L 50
const int WALL = 0;
const int ROAD = 1;
const int PLAYER = 2;
int difficulty = 3;
int maze[L][L];
void Generatemaze(int x, int y) {
	int direction[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	for (int i = 0; i < 4; i++) {
		int r = rand() % 4;
		int temp = direction[0][0];
		direction[0][0] = direction[r][0];
		direction[r][0] = temp;
		temp = direction[0][1];
		direction[0][1] = direction[r][1];
		direction[r][1] = temp;
	}
	for (int i = 0; i < 4; i++) {
		int l = 1 + (difficulty == 0 ? 0 : rand() % difficulty);
		int dx = x, dy = y;
		for (; l > 0; l--) {
			dx += direction[i][0];
			dy += direction[i][1];
			if (maze[dx][dy]) break;
			int count = 0;
			if (maze[dx - 1][dy]) count++;
			if (maze[dx + 1][dy]) count++;
			if (maze[dx][dy - 1]) count++;
			if (maze[dx][dy + 1]) count++;
			if (count > 1) break;
			maze[dx][dy] = ROAD;
		}
		if (l <= 0) Generatemaze(dx, dy);
	}
}
int main() {
	srand((unsigned)time(NULL));
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			maze[i][j] = WALL;
		}
	}
	for (int i = 0; i < L; i += L-1) {
		for (int j = 0; j < L; j++) {
			maze[i][j] = ROAD;
			maze[j][i] = ROAD;
		}
	}
	int x, y = 1;
	Generatemaze(25, 25);
	for (int i = 2; i <= L - 3; i++) {
		if (maze[i][2]) {
			maze[i][1] = 1;
			x = i;
			break;
		}
	}
	for (int i = L - 3; i >= 3; i--) {
		if (maze[i][L - 3]) {
			maze[i][L - 2] = 1;
			break;
		}
	}
	char c;
	maze[x][y] = PLAYER;
	while(1) {
		for (int i = 1; i < L - 1; i++) {
			for (int j = 1; j < L - 1; j++) {
				if (maze[i][j] == 1) printf("  ");
				else if (!maze[i][j]) printf("国");
				else printf("十");
			}
			printf("\n");
		}
		printf("Tip:请通过上下左右键来控制移动。\n");
		switch (c = _getch()) {
		case -32:
			switch (c = _getch()) {
			case 72://UP
				if (!maze[x - 1][y]) {
					printf("您的穿墙能力等级为lv0，穿墙失败！\n");
					system("pause");
					break;
				}
				maze[x--][y] = ROAD;
				maze[x][y] = PLAYER;
				break;
			case 80://DOWN
				if (!maze[x + 1][y]) {
					printf("您的穿墙能力等级为lv0，穿墙失败！\n");
					system("pause");
					break;
				}
				maze[x++][y] = ROAD;
				maze[x][y] = PLAYER;
				break;
			case 75://LEFT
				if (!maze[x][y - 1]) {
					printf("您的穿墙能力等级为lv0，穿墙失败！\n");
					system("pause");
					break;
				}
				maze[x][y--] = ROAD;
				maze[x][y] = PLAYER;
				break;
			case 77://RIGHT
				if (!maze[x][y + 1]) {
					printf("您的穿墙能力等级为lv0，穿墙失败！\n");
					system("pause");
					break;
				}
				maze[x][y++] = ROAD;
				maze[x][y] = PLAYER;
				break;
			default:
				printf("02_ERROR!!!!!\n");
				return 0;
				break;
			}
			break;
		default:
			printf("01_ERROR!!!!!\n");
			return 0;
			break;
		}
		if (!y) {
			printf("你走反了哦！\n");
			system("pause");
			maze[x][y++] = ROAD;
			maze[x][y] = PLAYER;
		}
		if (y == L-2) {
			system("cls");
			for (int i = 0; i < L - 2; i++) {
				for (int j = 0; j < L - 8; j++) {
					printf("*");
				}
				printf("恭喜闯关成功！");
				for (int j = 0; j < L - 8; j++) {
					printf("*");
				}
				printf("\n");
			}
			break;
		}
		system("cls");
	}
	return 0;
}