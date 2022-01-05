#include "pushBoxes.h"

void load(char* path, pMap pMap)
{
	pMap->num = 0;
	FILE* fp = NULL;
	fopen_s(&fp, path, "r");
	int data = 0;
	//data = fgetc(fp) != EOF;
	int i, j, flag = 0;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			data = fgetc(fp);

			if (data == EOF) {
				pMap->map[i][j] = -2;
				flag = 1;
				break;
			}
			if (data == 10) {
				pMap->map[i][j] = -1;
				break;
			}
			if (data == 50) {
				pMap->map[i][j] = data;
				pMap->x = i;
				pMap->y = j;
				continue;
			}
			if (data == 52) {
				pMap->map[i][j] = data;
				pMap->num += 1;
				continue;
			}
			pMap->map[i][j] = data;
		}
		if (flag)break;
	}
}
void display(pMap  pMap)
{
	int i, j;
	int data, flag_0 = 0, flag_1 = 0;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			data = pMap->map[i][j];
			switch (data) {
			case 48:
				printf(" ");
				break;
			case 49:
				printf("#");
				break;
			case 50:
				printf("O");
				break;
			case 51:
				printf("*");
				break;
			case 52:
				printf("+");
				break;
			case 53:
				printf("@");
				break;
			case 54:
				printf("&");
				break;
			case -1:
				printf("\n");
				flag_1 = 1;
				break;
			default:
				flag_0 = 1;
				break;
			}
			if (flag_1) {
				flag_1 = 0;
				break;
			}
			if (flag_0)break;
		}
		if (flag_0)break;
	}
}
void move(char direction)
{

}
void play(pMap pMap)
{
	int x, y;
	while (pMap->num != 0) {
		x = pMap->x;
		y = pMap->y;
		char c = _getch();
		switch (c) {
		case W:
			if (pMap->map[x][y] == 50) {           //当前玩家位置为路
				if (pMap->map[x - 1][y] == 48) { //玩家位置上方是路
					pMap->map[x][y] = 48;
					pMap->map[x - 1][y] = 50;
					pMap->x = x - 1;
					system("cls");
					display(pMap);
					break;
				}
				if (pMap->map[x - 1][y] == 51 && pMap->map[x - 2][y] != 49) { //玩家上方位置是箱子，箱子上方不是墙
					if (pMap->map[x - 2][y] == 52) { //箱子上方是目的地
						pMap->map[x - 2][y] = 53;
						pMap->num -= 1;
						pMap->map[x - 1][y] = 50;
						pMap->map[x][y] = 48;
						pMap->x = x - 1;
						system("cls");
						display(pMap);
						break;
					}
					if (pMap->map[x - 2][y] == 48) { //箱子上方是路
						pMap->map[x - 2][y] = 51;
						pMap->map[x - 1][y] = 50;
						pMap->map[x][y] = 48;
						pMap->x = x - 1;
						system("cls");
						display(pMap);
						break;
					}
				}
				if (pMap->map[x - 1][y] == 53 && pMap->map[x - 2][y] != 49) { //玩家上方位置是已复位的箱子，箱子上方不是墙
					if (pMap->map[x - 2][y] == 52) { //箱子上方是目的地
						pMap->map[x - 2][y] = 53;
						pMap->map[x - 1][y] = 54;
						pMap->map[x][y] = 48;
						pMap->x = x - 1;
						system("cls");
						display(pMap);
						break;
					}
					if (pMap->map[x - 2][y] == 48) { //箱子上方是路
						pMap->map[x - 2][y] = 51;
						pMap->map[x - 1][y] = 54;
						pMap->map[x][y] = 48;
						pMap->x = x - 1;
						system("cls");
						display(pMap);
						break;
					}
				}
				if (pMap->map[x - 1][y] == 52) { //玩家上方位置是目的地
					pMap->map[x - 1][y] = 54;
					pMap->map[x][y] = 48;
					pMap->x = x - 1;
					system("cls");
					display(pMap);
					break;
				}
			}
			if (pMap->map[x][y] == 54) {           //当前玩家在目的地上
				if (pMap->map[x - 1][y] == 48) { //玩家位置上方是路
					pMap->map[x][y] = 52;
					pMap->map[x - 1][y] = 50;
					pMap->x = x - 1;
					system("cls");
					display(pMap);
					break;
				}
				if (pMap->map[x - 1][y] == 51 && pMap->map[x - 2][y] != 49) { //玩家上方位置是箱子，箱子上方不是墙
					if (pMap->map[x - 2][y] == 52) { //箱子上方是目的地
						pMap->map[x - 2][y] = 53;
						pMap->num -= 1;
						pMap->map[x - 1][y] = 50;
						pMap->map[x][y] = 52;
						pMap->x = x - 1;
						system("cls");
						display(pMap);
						break;
					}
					if (pMap->map[x - 2][y] == 48) { //箱子上方是路
						pMap->map[x - 2][y] = 51;
						pMap->map[x - 1][y] = 50;
						pMap->map[x][y] = 52;
						pMap->x = x - 1;
						system("cls");
						display(pMap);
						break;
					}
				}
				if (pMap->map[x - 1][y] == 53 && pMap->map[x - 2][y] != 49) { //玩家上方位置是已复位的箱子，箱子上方不是墙
					if (pMap->map[x - 2][y] == 52) { //箱子上方是目的地
						pMap->map[x - 2][y] = 53;
						pMap->map[x - 1][y] = 54;
						pMap->map[x][y] = 52;
						pMap->x = x - 1;
						system("cls");
						display(pMap);
						break;
					}
					if (pMap->map[x - 2][y] == 48) { //箱子上方是路
						pMap->map[x - 2][y] = 51;
						pMap->map[x - 1][y] = 54;
						pMap->map[x][y] = 52;
						pMap->x = x - 1;
						system("cls");
						display(pMap);
						break;
					}
				}
				if (pMap->map[x - 1][y] == 52) { //玩家上方位置是目的地
					pMap->map[x - 1][y] = 54;
					pMap->map[x][y] = 52;
					pMap->x = x - 1;
					system("cls");
					display(pMap);
					break;
				}
			}
			break;

		case S:
			if (pMap->map[x][y] == 50) {           //当前玩家位置为路
				if (pMap->map[x + 1][y] == 48) { //玩家位置上方是路
					pMap->map[x][y] = 48;
					pMap->map[x + 1][y] = 50;
					pMap->x = x + 1;
					system("cls");
					display(pMap);
					break;
				}
				if (pMap->map[x + 1][y] == 51 && pMap->map[x + 2][y] != 49) { //玩家上方位置是箱子，箱子上方不是墙
					if (pMap->map[x + 2][y] == 52) { //箱子上方是目的地
						pMap->map[x + 2][y] = 53;
						pMap->num -= 1;
						pMap->map[x + 1][y] = 50;
						pMap->map[x][y] = 48;
						pMap->x = x + 1;
						system("cls");
						display(pMap);
						break;
					}
					if (pMap->map[x + 2][y] == 48) { //箱子上方是路
						pMap->map[x + 2][y] = 51;
						pMap->map[x + 1][y] = 50;
						pMap->map[x][y] = 48;
						pMap->x = x + 1;
						system("cls");
						display(pMap);
						break;
					}
				}
				if (pMap->map[x + 1][y] == 53 && pMap->map[x + 2][y] != 49) { //玩家上方位置是已复位的箱子，箱子上方不是墙
					if (pMap->map[x + 2][y] == 52) { //箱子上方是目的地
						pMap->map[x + 2][y] = 53;
						pMap->map[x + 1][y] = 54;
						pMap->map[x][y] = 48;
						pMap->x = x + 1;
						system("cls");
						display(pMap);
						break;
					}
					if (pMap->map[x + 2][y] == 48) { //箱子上方是路
						pMap->map[x + 2][y] = 51;
						pMap->map[x + 1][y] = 54;
						pMap->map[x][y] = 48;
						pMap->x = x + 1;
						system("cls");
						display(pMap);
						break;
					}
				}
				if (pMap->map[x + 1][y] == 52) { //玩家上方位置是目的地
					pMap->map[x + 1][y] = 54;
					pMap->map[x][y] = 48;
					pMap->x = x + 1;
					system("cls");
					display(pMap);
					break;
				}
			}
			if (pMap->map[x][y] == 54) {           //当前玩家在目的地上
				if (pMap->map[x + 1][y] == 48) { //玩家位置上方是路
					pMap->map[x][y] = 52;
					pMap->map[x + 1][y] = 50;
					pMap->x = x + 1;
					system("cls");
					display(pMap);
					break;
				}
				if (pMap->map[x + 1][y] == 51 && pMap->map[x + 2][y] != 49) { //玩家上方位置是箱子，箱子上方不是墙
					if (pMap->map[x + 2][y] == 52) { //箱子上方是目的地
						pMap->map[x + 2][y] = 53;
						pMap->num -= 1;
						pMap->map[x + 1][y] = 50;
						pMap->map[x][y] = 52;
						pMap->x = x + 1;
						system("cls");
						display(pMap);
						break;
					}
					if (pMap->map[x + 2][y] == 48) { //箱子上方是路
						pMap->map[x + 2][y] = 51;
						pMap->map[x + 1][y] = 50;
						pMap->map[x][y] = 52;
						pMap->x = x + 1;
						system("cls");
						display(pMap);
						break;
					}
				}
				if (pMap->map[x + 1][y] == 53 && pMap->map[x + 2][y] != 49) { //玩家上方位置是已复位的箱子，箱子上方不是墙
					if (pMap->map[x + 2][y] == 52) { //箱子上方是目的地
						pMap->map[x + 2][y] = 53;
						pMap->map[x + 1][y] = 54;
						pMap->map[x][y] = 52;
						pMap->x = x + 1;
						system("cls");
						display(pMap);
						break;
					}
					if (pMap->map[x + 2][y] == 48) { //箱子上方是路
						pMap->map[x + 2][y] = 51;
						pMap->map[x + 1][y] = 54;
						pMap->map[x][y] = 52;
						pMap->x = x + 1;
						system("cls");
						display(pMap);
						break;
					}
				}
				if (pMap->map[x + 1][y] == 52) { //玩家上方位置是目的地
					pMap->map[x + 1][y] = 54;
					pMap->map[x][y] = 52;
					pMap->x = x + 1;
					system("cls");
					display(pMap);
					break;
				}
			}
			break;

		case A:
			if (pMap->map[x][y] == 50) {           //当前玩家位置为路
				if (pMap->map[x][y - 1] == 48) { //玩家位置上方是路
					pMap->map[x][y] = 48;
					pMap->map[x][y - 1] = 50;
					pMap->y = y - 1;
					system("cls");
					display(pMap);
					break;
				}
				if (pMap->map[x][y - 1] == 51 && pMap->map[x][y - 2] != 49) { //玩家上方位置是箱子，箱子上方不是墙
					if (pMap->map[x][y - 2] == 52) { //箱子上方是目的地
						pMap->map[x][y - 2] = 53;
						pMap->num -= 1;
						pMap->map[x][y - 1] = 50;
						pMap->map[x][y] = 48;
						pMap->y = y - 1;
						system("cls");
						display(pMap);
						break;
					}
					if (pMap->map[x][y - 2] == 48) { //箱子上方是路
						pMap->map[x][y - 2] = 51;
						pMap->map[x][y - 1] = 50;
						pMap->map[x][y] = 48;
						pMap->y = y - 1;
						system("cls");
						display(pMap);
						break;
					}
				}
				if (pMap->map[x][y - 1] == 53 && pMap->map[x][y - 2] != 49) { //玩家上方位置是已复位的箱子，箱子上方不是墙
					if (pMap->map[x][y - 2] == 52) { //箱子上方是目的地
						pMap->map[x][y - 2] = 53;
						pMap->map[x][y - 1] = 54;
						pMap->map[x][y] = 48;
						pMap->y = y - 1;
						system("cls");
						display(pMap);
						break;
					}
					if (pMap->map[x][y - 2] == 48) { //箱子上方是路
						pMap->map[x][y - 2] = 51;
						pMap->map[x][y - 1] = 54;
						pMap->map[x][y] = 48;
						pMap->y = y - 1;
						system("cls");
						display(pMap);
						break;
					}
				}
				if (pMap->map[x][y - 1] == 52) { //玩家上方位置是目的地
					pMap->map[x][y - 1] = 54;
					pMap->map[x][y] = 48;
					pMap->y = y - 1;
					system("cls");
					display(pMap);
					break;
				}
			}
			if (pMap->map[x][y] == 54) {           //当前玩家在目的地上
				if (pMap->map[x][y - 1] == 48) { //玩家位置上方是路
					pMap->map[x][y] = 52;
					pMap->map[x][y - 1] = 50;
					pMap->y = y - 1;
					system("cls");
					display(pMap);
					break;
				}
				if (pMap->map[x][y - 1] == 51 && pMap->map[x][y - 2] != 49) { //玩家上方位置是箱子，箱子上方不是墙
					if (pMap->map[x][y - 2] == 52) { //箱子上方是目的地
						pMap->map[x][y - 2] = 53;
						pMap->num -= 1;
						pMap->map[x][y - 1] = 50;
						pMap->map[x][y] = 52;
						pMap->y = y - 1;
						system("cls");
						display(pMap);
						break;
					}
					if (pMap->map[x][y - 2] == 48) { //箱子上方是路
						pMap->map[x][y - 2] = 51;
						pMap->map[x][y - 1] = 50;
						pMap->map[x][y] = 52;
						pMap->y = y - 1;
						system("cls");
						display(pMap);
						break;
					}
				}
				if (pMap->map[x][y - 1] == 53 && pMap->map[x][y - 2] != 49) { //玩家上方位置是已复位的箱子，箱子上方不是墙
					if (pMap->map[x][y - 2] == 52) { //箱子上方是目的地
						pMap->map[x][y - 2] = 53;
						pMap->map[x][y - 1] = 54;
						pMap->map[x][y] = 52;
						pMap->y = y - 1;
						system("cls");
						display(pMap);
						break;
					}
					if (pMap->map[x][y - 2] == 48) { //箱子上方是路
						pMap->map[x][y - 2] = 51;
						pMap->map[x][y - 1] = 54;
						pMap->map[x][y] = 52;
						pMap->y = y - 1;
						system("cls");
						display(pMap);
						break;
					}
				}
				if (pMap->map[x][y - 1] == 52) { //玩家上方位置是目的地
					pMap->map[x][y - 1] = 54;
					pMap->map[x][y] = 52;
					pMap->y = y - 1;
					system("cls");
					display(pMap);
					break;
				}
			}
			break;

		case D:
			if (pMap->map[x][y] == 50) {           //当前玩家位置为路
				if (pMap->map[x][y + 1] == 48) { //玩家位置上方是路
					pMap->map[x][y] = 48;
					pMap->map[x][y + 1] = 50;
					pMap->y = y + 1;
					system("cls");
					display(pMap);
					break;
				}
				if (pMap->map[x][y + 1] == 51 && pMap->map[x][y + 2] != 49) { //玩家上方位置是箱子，箱子上方不是墙
					if (pMap->map[x][y + 2] == 52) { //箱子上方是目的地
						pMap->map[x][y + 2] = 53;
						pMap->num -= 1;
						pMap->map[x][y + 1] = 50;
						pMap->map[x][y] = 48;
						pMap->y = y + 1;
						system("cls");
						display(pMap);
						break;
					}
					if (pMap->map[x][y + 2] == 48) { //箱子上方是路
						pMap->map[x][y + 2] = 51;
						pMap->map[x][y + 1] = 50;
						pMap->map[x][y] = 48;
						pMap->y = y + 1;
						system("cls");
						display(pMap);
						break;
					}
				}
				if (pMap->map[x][y + 1] == 53 && pMap->map[x][y + 2] != 49) { //玩家上方位置是已复位的箱子，箱子上方不是墙
					if (pMap->map[x][y + 2] == 52) { //箱子上方是目的地
						pMap->map[x][y + 2] = 53;
						pMap->map[x][y + 1] = 54;
						pMap->map[x][y] = 48;
						pMap->y = y + 1;
						system("cls");
						display(pMap);
						break;
					}
					if (pMap->map[x][y + 2] == 48) { //箱子上方是路
						pMap->map[x][y + 2] = 51;
						pMap->map[x][y + 1] = 54;
						pMap->map[x][y] = 48;
						pMap->y = y + 1;
						system("cls");
						display(pMap);
						break;
					}
				}
				if (pMap->map[x][y + 1] == 52) { //玩家上方位置是目的地
					pMap->map[x][y + 1] = 54;
					pMap->map[x][y] = 48;
					pMap->y = y + 1;
					system("cls");
					display(pMap);
					break;
				}
			}
			if (pMap->map[x][y] == 54) {           //当前玩家在目的地上
				if (pMap->map[x][y + 1] == 48) { //玩家位置上方是路
					pMap->map[x][y] = 52;
					pMap->map[x][y + 1] = 50;
					pMap->y = y + 1;
					system("cls");
					display(pMap);
					break;
				}
				if (pMap->map[x][y + 1] == 51 && pMap->map[x][y + 2] != 49) { //玩家上方位置是箱子，箱子上方不是墙
					if (pMap->map[x][y + 2] == 52) { //箱子上方是目的地
						pMap->map[x][y + 2] = 53;
						pMap->num -= 1;
						pMap->map[x][y + 1] = 50;
						pMap->map[x][y] = 52;
						pMap->y = y + 1;
						system("cls");
						display(pMap);
						break;
					}
					if (pMap->map[x][y + 2] == 48) { //箱子上方是路
						pMap->map[x][y + 2] = 51;
						pMap->map[x][y + 1] = 50;
						pMap->map[x][y] = 52;
						pMap->y = y + 1;
						system("cls");
						display(pMap);
						break;
					}
				}
				if (pMap->map[x][y + 1] == 53 && pMap->map[x][y - 2] != 49) { //玩家上方位置是已复位的箱子，箱子上方不是墙
					if (pMap->map[x][y + 2] == 52) { //箱子上方是目的地
						pMap->map[x][y + 2] = 53;
						pMap->map[x][y + 1] = 54;
						pMap->map[x][y] = 52;
						pMap->y = y + 1;
						system("cls");
						display(pMap);
						break;
					}
					if (pMap->map[x][y + 2] == 48) { //箱子上方是路
						pMap->map[x][y + 2] = 51;
						pMap->map[x][y + 1] = 54;
						pMap->map[x][y] = 52;
						pMap->y = y + 1;
						system("cls");
						display(pMap);
						break;
					}
				}
				if (pMap->map[x][y + 1] == 52) { //玩家上方位置是目的地
					pMap->map[x][y + 1] = 54;
					pMap->map[x][y] = 52;
					pMap->y = y + 1;
					system("cls");
					display(pMap);
					break;
				}
			}
			break;
		default:
			break;
		}
	}
}