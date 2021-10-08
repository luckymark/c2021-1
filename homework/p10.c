#include<stdio.h>
#include<stdlib.h>
const int ROAD = 0;//路
const int WALL = 1;//墙
const int PLAYER = 2;//玩家
const int BOX = 3;//箱子
const int POINT = 4;//目标点
const int PP = 5;//占据目标点的玩家
const int BP = 6;//占据目标点的箱子
int maze[12][13];
void moveplayer(int* x, int* y, int dx, int dy) {//移动角色
	maze[*x][*y] = (maze[*x][*y] == PP) ? POINT : ROAD;
	*x += dx;
	*y += dy;
	maze[*x][*y] = (maze[*x][*y] == POINT) ? PP : PLAYER;
}
void movebox(int* x, int* y, int dx, int dy) {//移动箱子
	if (maze[*x + dx * 2][*y + dy * 2] == WALL)
		return;
	if (maze[*x + dx * 2][*y + dy * 2] == BOX)
		return;
	maze[*x + dx][*y + dy] = (maze[*x + dx][*y + dy] == BOX) ? ROAD : POINT;
	maze[*x + dx * 2][*y + dy * 2] = (maze[*x + dx * 2][*y + dy * 2] == ROAD) ? BOX : BP;
	moveplayer(x, y, dx, dy);
}
void move(int* x, int* y, int dx, int dy) {//移动
	if (maze[*x + dx][*y + dy] == WALL)
		return;
	if (maze[*x + dx][*y + dy] == BOX || maze[*x + dx][*y + dy] == BP) {
		movebox(x, y, dx, dy);
		return;
	}
	moveplayer(x, y, dx, dy);
}
int main() {
	char c;
	int x, y, n = 0, scole = 0, round, point;
	FILE* map = fopen("map.txt", "r");
	while (1) {
		fscanf(map, "%d%d", &round, &point);
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 13; j++) {
				fscanf(map, "%d", &maze[i][j]);
				if (maze[i][j] == PLAYER) {
					x = i;
					y = j;
				}
			}
		}
		while (1) {
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 13; j++) {
					switch (maze[i][j]) {
					case 0:
						printf("  ");
						break;
					case 1:
						printf("※");
						break;
					case 2:
						printf("♀");
						break;
					case 3:
						printf("囗");
						break;
					case 4:
						printf("☆");
						break;
					case 5:
						printf("♀");
						break;
					case 6:
						printf("囗");
						n++;
						break;
					default:
						printf("\nERROR!!!!!!!!!");
					}
				}
				printf("\n");
			}
			if (n == point) {
				goto flag;
			}
			else
				n = 0;
			printf("Tip:请通过上下左右键来控制移动。\n");
			switch (c = getch()) {
			case -32:
				switch (c = getch()) {
				case 72://UP
					move(&x, &y, -1, 0);
					break;
				case 80://DOWN
					move(&x, &y, 1, 0);
					break;
				case 75://LEFT
					move(&x, &y, 0, -1);
					break;
				case 77://RIGHT
					move(&x, &y, 0, 1);
					break;
				default:
					printf("02_ERROR!!!!!\n");
					getchar();
					return 0;
				}
				break;
			default:
				printf("01_ERROR!!!!!\n");
				getchar();
				return 0;
			}
			scole++;
			system("cls");
		}
	flag:
		system("cls");
		printf("恭喜挑战成功！本次行走步数为%d", scole);
		FILE* mark = fopen("mark.txt", "a+");
		fprintf(mark, "%d、%d\n", round, scole);
		fclose(mark);
		getchar();
		system("cls");
	}
	fclose(map);
	return 0;
}