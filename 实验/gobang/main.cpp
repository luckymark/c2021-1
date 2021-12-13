#include <graphics.h>
#include <conio.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include"ChessBoard.h"
using namespace std;
board Board;
void init() {//初始化棋盘
	//数据部分
	Board.initboard();
	//视觉部分
	IMAGE img;
	loadimage(&img, "E:\\Practice\\easyx-gobang\\Board.jpg");
	initgraph(646, 646);
	putimage(0, 0, &img);
	system("pause");
}

int main() {
	init();
	//Board.readplayer();
	Board.initboard();
	int consequence;
	while (1) {
		Board.readplayer();
		Board.aigo();
		consequence =Board.Checkover();
		if (consequence == 1) {
			printf("Sorry! You lose!!!");
			return 0;
		}
		if (consequence == 2) {
			printf("Nice job! You win!!!");
			return 0;
		}
	}
	

	return 0;
}








/*MOUSEMSG msg;
	while (1) {
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {
			player_gobang();
			if (checkover()) {
				init();//下一局
				continue;
			}
			AI_gobang();
			if (checkover()) {
				init();//下一局
				continue;
			}
		}
	}
	closegraph();*/