#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include "ChessBoard.h"
using namespace std;
const int Side = 28, Len = 42, R = 20;
//���Ӽ�������1000000000
//���ģ�100000000
//���ģ�100000
//������100000
//������1000
//�����1000
//���;100
//��һ��10
const long long Data[11] = { 0,10,10,100,1000,1000,100000,100000,100000000,1000000000,100000000 };
int f(int p) {//��p�������
	return Len * (p - 1) + Side;
}
int find(int p) {//λ��p���ĸ����Ӹ���
	p -= Side;
	for (int i = 1; i <= 15; i++) {
		double now = f(i);
		if (now - 9 <= p && p <= now + 9) return i;
	}
}
void board::initboard() {//��ʼ�����̣�
	for (int i = 0; i <= 14; i++) {
		for (int j = 0; j <= 14; j++) {
			pre[i][j] = 0;
		}
	}
}
int board::Checkover() {
	for (int color = 1; color <= 2; color++) {
		for (int i = 0; i <= 14; i++) {
			if (cal_line(i, color) >= 1000000000)			return color;
			if (cal_colume(i, color) >= 1000000000)			return color;
			if (cal_diagonal(i, color) >= 1000000000)		return color;
			if (cal_backdiagonal(i, color) >= 1000000000)   return color;
		}
	}
	return 0;
}

void board::draw(int x, int y, int color) {//��x�У���y��
	//���ݲ��֣�
	pre[x][y] = color;

	//ͼ�β���
	if (color == 1) {//����,����
		setlinecolor(RGB(255, 255, 255));
		setfillcolor(RGB(255, 255, 255));
	}
	if (color == 2) {//���,����
		setlinecolor(RGB(0, 0, 0));
		setfillcolor(RGB(0, 0, 0));
	}
	int xp = f(x + 1), yp = f(y + 1);
	fillcircle(yp, xp, R);
	system("pause");
}

int board::readboard(int x, int y) {
	return pre[x][y];
}
void board::readplayer() {
	FlushMouseMsgBuffer();
	while (true) {
		while (MouseHit()) {
			MOUSEMSG msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN) {
				//cout << msg.x << " " << msg.y;
				int y = find(msg.x), x = find(msg.y);
				draw(x, y, 2);
				pre[x - 1][y - 1] = 2;
			}
		}
	}
}
bool board::close(int x, int y) {
	int count = 0;
	for (int i = max(0, x - 2); i <= min(14, x + 2); i++) {
		for (int j = max(0, y - 2); j <= min(14, y + 2); j++) {
			if (pre[i][j]) count++;
		}
	}
	if (count < 2) return false;
	return true;
}

long long board::cal_line(int line, int color) {
	long long result = 0;
	for (int i = 0; i <= 14; i += 1) {
		if (pre[line][i] == color) {
			int right = i;
			while (pre[line][right] == color && right <= 14) {
				right += 1;
			}
			//right��ֵΪ�ұߵ�һ���з����ӵ�λ��
			int length = right - i;
			int flag = 0;
			if (i == 0 || pre[line][i - 1] == 3 - color) flag++;
			if (right == 15 || pre[line][right] == 3 - color) flag++;
			if (flag == 0)   result += Data[length * 2];
			if (flag == 1)   result += Data[length * 2 - 1];
			if (flag == 2)   result += 0;
			i = right;
		}
	}
	return result;
}
long long board::cal_colume(int colume, int color) {
	long long result = 0;
	for (int i = 0; i <= 14; i += 1) {
		if (pre[i][colume] == color) {
			int down = i;
			while (pre[i][down] == color && down <= 14) {
				down += 1;
			}
			//down��ֵΪ�±ߵ�һ���з����ӵ�λ�ã������½�
			int length = down - i;
			int flag = 0;
			if (i == 0 || pre[i - 1][colume] == 3 - color) flag++;
			if (down == 15 || pre[down][colume] == 3 - color) flag++;
			if (flag == 0)   result += Data[length * 2];
			if (flag == 1)   result += Data[length * 2 - 1];
			if (flag == 2)   result += 0;
			i = down;
		}
	}
	return result;
}
long long board::cal_diagonal(int dis, int color) {
	int END = 14 - dis, x1, y1, x2, y2;
	long long result = 0;

	x1 = 0, y1 = dis;
	for (int i = 0; i <= END; i++) {
		if (pre[x1 + i][y1 + i] == color) {
			int down = i;
			while (pre[x1 + down][y1 + down] == color && down <= END) {
				down += 1;
			}
			int length = down - i;
			int flag = 0;
			if (i == 0 || pre[x1 + i - 1][y1 + i - 1] == 3 - color) flag++;
			if (down == 15 || pre[x1 + down][y1 + down] == 3 - color) flag++;
			if (flag == 0)   result += Data[length * 2];
			if (flag == 1)   result += Data[length * 2 - 1];
			if (flag == 2)   result += 0;
			i = down;
		}
	}
	if (dis) {
		x2 = dis, y2 = 0;
		for (int i = 0; i <= END; i++) {
			if (pre[x2 + i][y2 + i] == color) {
				int down = i;
				while (pre[x2 + down][y2 + down] == color && down <= END) {
					down += 1;
				}
				int length = down - i;
				int flag = 0;
				if (i == 0 || pre[x2 + i - 1][y2 + i - 1] == 3 - color) flag++;
				if (down == END + 1 || pre[x2 + down][y2 + down] == 3 - color) flag++;
				if (flag == 0)   result += Data[length * 2];
				if (flag == 1)   result += Data[length * 2 - 1];
				if (flag == 2)   result += 0;
				i = down;
			}
		}
	}
	return result;
}
long long board::cal_backdiagonal(int dis, int color) {
	int END = 14 - dis, x1, y1, x2, y2;
	long long result = 0;
	x1 = 0, y1 = 14 - dis;
	for (int i = 0; i <= END; i++) {
		if (pre[x1 + i][y1 - i] == color) {
			int down = i;
			while (pre[x1 + down][y1 - down] == color && down <= END) {
				down++;
			}
			int length = down - i;
			int flag = 0;
			if (i == 0 || pre[x1 + i - 1][y1 - (i - 1)] == 3 - color) flag++;
			if (down == END + 1 || pre[x1 + down][y1 - down] == 3 - color) flag++;
			if (flag == 0)   result += Data[length * 2];
			if (flag == 1)   result += Data[length * 2 - 1];
			if (flag == 2)   result += 0;
			i = down;
		}
	}
	if (dis) {
		x2 = dis, y2 = 0;
		for (int i = 0; i <= END; i++) {
			if (pre[x2 + i][y2 - i] == color) {
				int down = i;
				while (pre[x2 + down][y2 - down] == color && down <= END) {
					down++;
				}
				int length = down - i;
				int flag = 0;
				if (i == 0 || pre[x2 + i - 1][y2 - (i - 1)] == 3 - color) flag++;
				if (down == END + 1 || pre[x2 + down][y2 - down] == 3 - color) flag++;
				if (flag == 0)   result += Data[length * 2];
				if (flag == 1)   result += Data[length * 2 - 1];
				if (flag == 2)   result += 0;
				i = down;
			}
		}
	}
	return result;
}
long long board::calculate() {//��ֵ����
	long long marks[3] = { 0 };
	for (int color = 1; color <= 2; color++) {
		for (int i = 0; i <= 14; i++) {
			marks[color] += cal_line(i, color);
			marks[color] += cal_colume(i, color);
			marks[color] += cal_diagonal(i, color);
			marks[color] += cal_backdiagonal(i, color);
		}
	}
	return marks[1] - marks[2];//AI�÷ּ�ȥ����÷�
}
long long board::max_min_dfs(int depth, long long alpha, long long beta) {
	int color;
	long long num, if_score;
	int now_x, now_y;
	//������˵����㣬��Ϊ������壬ȡ��Сֵ
	if (depth == 6) {
		color = 2;
		num = 9223372036854775807;
		for (int i = 0; i <= 14; i++) {
			for (int j = 0; j <= 14; j++) {
				if (pre[i][j] == 0 && close(i, j)) {
					pre[i][j] = color;
					if_score = calculate();
					if (num > if_score) {
						now_x = i, now_y = j;
						num = if_score;
					}
					pre[i][j] = 0;
				}
			}
		}
		//pre[now_x][now_y] = 2;
		return num;
	}
	if (depth % 2 == 1) {//��������Ϊmax�㣬AI����
		color = 1;
		num = -9223372036854775807;
		for (int i = 0; i <= 14; i++) {
			for (int j = 0; j <= 14; j++) {
				if (pre[i][j] == 0 && close(i, j)) {
					pre[i][j] = color;
					if_score = max_min_dfs(depth + 1, alpha, beta);
					if (if_score > alpha) alpha = if_score;
					if (alpha >= beta) {
						pre[i][j] = 0;
						return beta;
					}

					if (if_score > num) {
						now_x = i, now_y = j;
						num = if_score;
					}
					pre[i][j] = 0;
				}
			}
		}
		if (depth == 1) {
			//pre[now_x][now_y] = 1;
			draw(now_x + 1, now_y, 1);
		}
		return num;
	}
	else {
		color = 2;
		num = 9223372036854775807;
		for (int i = 0; i <= 14; i++) {
			for (int j = 0; j <= 14; j++) {
				if (pre[i][j] == 0 && close(i, j)) {
					pre[i][j] = color;
					if_score = max_min_dfs(depth + 1, alpha, beta);
					if (if_score < beta) {
						beta = if_score;
						now_x = i, now_y = j;
						num = if_score;
					}
					if (beta <= alpha) {
						pre[i][j] = 0;
						return alpha;
					}
					pre[i][j] = 0;
				}
			}
		}
		//pre[now_x][now_y] = 2;
		return num;
	}
}
void board::aigo() {
	long long answer = max_min_dfs(1, -9223372036854775807, 9223372036854775807);
	int answer_x, answer_y;
	for (int i = 0; i <= 14; i++) {
		for (int j = 0; j <= 14; j++) {
			pre[i][j] = 1;
			if (calculate() == answer) {
				answer_x = i;
				answer_y = j;
			}
			pre[i][j] = 1;
		}
	}
	draw(answer_x, answer_y, 1);
}

