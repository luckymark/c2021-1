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
	puts("�ͺ�  �������");
	for (int i = 1; i < N; ++i)
		printf("%3d%8d\n", i, goods[i].num);
}

void putin() {
	int tot, num, type;
	puts("������˴β�����Ҫ����������:");
	scanf_s("%d", &tot);
	for (int i = 1; i <= tot; ++i) {
		printf("��%d�����ͺţ�", i);
		scanf_s("%d", &type);
		printf("��%d�������������", i);
		scanf_s("%d", &num);
		goods[type].num += num;
		puts("");
	}
}

void putout() {
	int tot, num, type;
	puts("������˴β�����Ҫ�����������:");
	scanf_s("%d", &tot);
	for (int i = 1; i <= tot; ++i) {
		printf("��%d�����ͺţ�", i);
		scanf_s("%d", &type);
		printf("��%d��������������������������ͺŲ�Ʒ������-1����", i);
		scanf_s("%d", &num);
		while (num > goods[type].num) {
			printf("�������󣬸��ͺŲ�Ʒ�����Ϊ%d��\n", goods[type].num);
			printf("������������ͺŲ�Ʒ��Ҫ������������������������ͺŲ�Ʒ������-1����");
			scanf_s("%d", &num);
		}
		if (num == -1) continue;
		goods[type].num -= num;
		puts("");
	}
}

void Continue() {
	puts("�����ɹ����밴�س������ز˵�");
	while (1) {
		char op = _getch();
		if (op == '\r') Menu();
	}
}

void Menu() {
	system("cls");
	printf("��ӭ�������������ĵ�Warehouse!\n\n\n");
	puts("�밴�¶�Ӧ���ּ���������Ҫ�Ĳ�����");
	puts("1.��ʾ����б�");
	puts("2.���");
	puts("3.����");
	puts("4.�˳�����");
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