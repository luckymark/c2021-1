#include<stdio.h>
#include<fstream>
#include<iostream>
#include<windows.h>
#include<graphics.h>
using namespace std;

fstream f;
int exist;

void initialize() {
	initgraph(500, 500);
	outtextxy(100, 50, _TEXT("������Խ��в���"));
	setfillcolor(DARKGRAY);
	fillrectangle(25, 150, 125, 200);
	fillrectangle(175, 150, 225, 200);
	fillrectangle(275, 150, 325, 200);
	fillrectangle(375, 150, 445, 200);
	setcolor(WHITE);
	setbkcolor(DARKGRAY);
	outtextxy(29, 167, _TEXT("��ʾ����б�"));
	outtextxy(185, 167, _TEXT("���"));
	outtextxy(285, 167, _TEXT("����"));
	outtextxy(380, 167, _TEXT("�˳�����"));
}
void show() {
	closegraph();
	f.open("List.txt", ios::out);
	string type;
	int num;
	while (f >> type >> num) {
		cout << type << "ʣ��������" << num << endl;
	}
	printf("����b(back)�ص��˵�\n");
	f.close();
	char c;
	while (1) {
		c = getchar();
		if (c == 'b') break;
	}
	initialize();
}
void instorage() {
	closegraph();
	f.open("List.txt", ios::in|ios::out);
	string type;
	int num;
	scanf_s("%s%d", type, &num);
	bool isexist=false;
	string temp;
	int t;
	while (f >> temp >> t) {
		if (temp == type) {
			t += num;
			isexist = true;
			break;
		}
	}
	if (isexist) f << t;
	else f << type << num;
	printf("����b(back)�ص��˵�\n");
	f.close();
	char c;
	while (1) {
		c = getchar();
		if (c == 'b') break;
	}
	initialize();
}
void outstorage() {
	closegraph();
	f.open("List.txt", ios::in | ios::out);
	string type;
	int num;
	scanf_s("%s%d", type, &num);
	bool isexist = false, isenough = false;
	string temp;
	int t;
	while (f >> temp >> t) {
		if (temp == type) {
			t -= num;
			isexist = true;
			if (t >= 0) isenough = true;
			else isenough = false;
			break;
		}
	}
	if (isexist) {
		if (isenough) {
			f << t;
		}
		else printf("�û����治�㣡\n");
	}
	else printf("�û��ﲻ�����ڲֿ���\n");
	printf("����b(back)�ص��˵�\n");
	f.close();
	char c;
	while (1) {
		c = getchar();
		if (c == 'b') break;
	}
	initialize();
}
void choose() {
	MOUSEMSG m;
	int x=0, y=0;
	if (MouseHit()) {
		m = GetMouseMsg();
		switch (m.uMsg) {
		case    WM_LBUTTONDOWN:
			x = m.x;
			y = m.y;
			break;
		default:
			break;
		}
		if (x >= 25 && x <= 125 && y >= 150 && y <= 200) show();
		else if (x >= 175 && x <= 225 && y >= 150 && y <= 200) instorage();
		else if (x >= 275 && x <= 320 && y >= 150 && y <= 200) outstorage();
		else if (x >= 375 && x <= 445 && y >= 150 && y <= 200) exist = 1;
	}
}
int main() {
	initialize();
	exist = 0;
	while (!exist) {
		choose();
	}
	closegraph();
	system("pause");
	return 0;
}