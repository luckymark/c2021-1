#include<cstdio>
#include<fstream>
#include<conio.h>
#include<windows.h>
using namespace std;

const int N = 11;

struct Prod {
	int num;
}goods[N];

int trsf(char* ch);
void Dataread();
void Datawrite();
void display();
void putin();
void putout();
void Continue();
void Menu();

int main() 
{
	Dataread();
	Menu();
	Datawrite();
	return 0;
}

int trsf(char* ch) {
	int dir = 0,ans=0;
	while (ch[dir]>='0'&&ch[dir]<='9') {
		ans = (ans << 3) + (ans << 1) + (ch[dir] ^ 48);
		++dir;
	}
	return ans;
}

void Dataread() {
	ifstream fin;
	fin.open("warehouse.txt",ios::in);
	int cnt = 0;
	char buf[101] = { 0 };
	while (fin >> buf) 
		goods[++cnt].num = trsf(buf);
}

void Datawrite() {
	FILE* stream;
	freopen_s(&stream,"warehouse.txt", "w", stdout);
	for (int i = 1; i < N; ++i) 
		printf("%d\n", goods[i].num);
}

void display() {
	puts("型号  库存余量");
	for (int i = 1; i < N; ++i)
		printf("%3d%8d\n", i, goods[i].num);
}

void putin() {
	int tot, num, type;
	puts("请输入此次操作需要入库多少批货:");
	scanf_s("%d", &tot);
	for (int i = 1; i <= tot; ++i) {
		printf("第%d批货型号：", i);
		scanf_s("%d", &type);
		printf("第%d批货入库数量：", i);
		scanf_s("%d", &num);
		goods[type].num += num;
		puts("");
	}
}

void putout() {
	int tot, num, type;
	puts("请输入此次操作需要出库多少批货:");
	scanf_s("%d", &tot);
	for (int i = 1; i <= tot; ++i) {
		printf("第%d批货型号：", i);
		scanf_s("%d", &type);
		printf("第%d批货出库数量（若放弃出库该型号产品请输入-1）：", i);
		scanf_s("%d", &num);
		while (num > goods[type].num) {
			printf("操作错误，该型号产品库存量为%d。\n", goods[type].num);
			printf("请重新输入该型号产品需要出货的数量（若放弃出库该型号产品请输入-1）：");
			scanf_s("%d", &num);
		}
		if (num == -1) continue;
		goods[type].num -= num;
		puts("");
	}
}

void Continue() {
	puts("操作成功！请按回车键返回菜单");
	while (1) {
		char op = _getch();
		if (op == '\r') Menu();
	}
}

void Menu() {
	system("cls");
	printf("欢迎来到薄荷凉了夏的Warehouse!\n\n\n");
	puts("请按下对应数字键进行您想要的操作：");
	puts("1.显示存货列表");
	puts("2.入库");
	puts("3.出库");
	puts("4.退出程序");
	while (1) {
		char op = _getch();
		if (op == '1') {
			system("cls");
			display();
			Continue();
		}
		else if (op == '2') {
			system("cls");
			putin();
			Continue();
		}
		else if (op == '3') {
			system("cls");
			putout();
			Continue();
		}
		else if (op == '4') {
			Datawrite();
			exit(0);
		}
	}
}