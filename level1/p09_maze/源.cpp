#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<math.h>

//��ͼ�߳�L�������Թ�����20�����İ�Χ��ǽ��2��������Χ·��2��֮�����ͣ�
//�ɸ�����Ҫ�޸ģ�������
#define L 24

#define WALL  0 //ǽ
#define ROUTE 1 //·��
#define PLAYER 2//���

//�����Թ��ĸ��Ӷȣ���ֵԽ���Ӷ�Խ�ͣ���СֵΪ0
//Ĭ��Ϊ���Ѷȣ��ɸ�����Ҫ��degree�����������ͬ�Ѷȵĸ��Ӷ�
int Rank = 6;

void menu();   //���˵�����
void start();  //��ʼ��Ϸ
void degree(); //��Ϸ�Ѷ�
void explain();//��Ϸ˵��
int init(int** Maze);  //��ʼ���Թ�
void print(int** Maze);//���Թ�
void CreateMaze(int **maze, int x, int y);    //�����Թ�
void move(int** Maze, char t, int *x, int *y);//�ƶ���ɫ

int main() {
	menu();
	return 0;
}

void menu() { //���˵�
	while (1) {
		system("cls"); //����
		char t;
		printf("*******(���Թ�)*******");
		printf("\n======================\n");
		printf("\n||   1. ��ʼ ��Ϸ   ||\n");
		printf("\n||   2. ��Ϸ ˵��   ||\n");
		printf("\n||   3. ��Ϸ �Ѷ�   ||\n");
		printf("\n||   4. �ر� ��Ϸ   ||\n");
		printf("======================\n");
		t = _getch();    //�����Ժ���
		switch (t) {
		case '1':
			start();
			break;  //��ʼһ����Ϸ
		case '2':
			explain();
			break;  //������Ϸ˵������
		case '3':
			degree();
			break;  //������Ϸ�Ѷ�
		case '4':
			printf("\n��ӭ�´����棬�ټ�����������J");
			Sleep(1500);
			exit(0);
			break;  //��������
		default:
			break;
		}
	}
}

void CreateMaze(int **maze, int x, int y) {//�����Թ�
	maze[x][y] = ROUTE;
	//ȷ���ĸ�����������������ǹ̶�������������������
	int direction[4][2] = { { 1,0 },{ -1,0 },{ 0,-1 },{ 0,1 } };
	int i, j;
	for (i = 0; i < 4; i++) {
		int r = rand() % 4;
		int temp = direction[0][0];
		direction[0][0] = direction[r][0];
		direction[r][0] = temp;
		temp = direction[0][1];
		direction[0][1] = direction[r][1];
		direction[r][1] = temp;
	}
	//���ĸ�������
	for (i = 0; i < 4; i++) {
		int dx = x;
		int dy = y;
		//�����ڵľ��룬��Rank��������С
		int range = 1 + (Rank == 0 ? 0 : rand() % Rank);
		while (range > 0) {
			//�������Ҫ���ʵ�������
			dx += direction[i][0];
			dy += direction[i][1];
			//�ų�����ͷ·
			if (maze[dx][dy] == ROUTE) {
				break;
			}
			//�ж��Ƿ��ڴ�·��
			int count = 0, k;
			for (j = dx - 1; j < dx + 2; j++) {
				for (k = dy - 1; k < dy + 2; k++) {
					//abs(j - dx) + abs(k - dy) == 1 ȷ��ֻ�жϾŹ�����ĸ��ض�λ��
					if (abs(j - dx) + abs(k - dy) == 1 && maze[j][k] == ROUTE) {
						count++;
					}
				}
			}
			//count����1����ǽ��ᱻ�ڴ���ֹͣ
			if (count > 1)
				break;
			//ȷ�������ڴ�ʱ��ǰ��
			range -= 1;
			maze[dx][dy] = ROUTE;
		}
		//û���ڴ�Σ�գ��Դ�Ϊ�ڵ�ݹ�
		if (range <= 0) {
			CreateMaze(maze, dx, dy);
		}
	}
}

int init(int** Maze) {//��ʼ���Թ�
	int i;
	//����Χ����Ϊ·����ԭ��Ϊ�˷�ֹ��·ʱ�ڳ��߽磬ͬʱΪ�˱����Թ��������һȦǽ�屻�ڴ�
	for (i = 0; i < L; i++) {
		Maze[i][0] = ROUTE;
		Maze[0][i] = ROUTE;
		Maze[i][L - 1] = ROUTE;
		Maze[L - 1][i] = ROUTE;
	}
	//�����Թ�����2��2��Ϊ���
	CreateMaze(Maze, 2, 2);
	//���Թ�����ںͳ��ڣ�������ҳ�ʼλ��
	Maze[2][1] = PLAYER;
	//�����㷨����ԣ�������һ�����ʲ��ڣ�L-3,L-2��������ʱ��ҪѰ�ҳ���
	for (i = L - 3; i >= 0; i--) {
		if (Maze[i][L - 3] == ROUTE) {
			Maze[i][L - 2] = ROUTE;
			//���س������ڵ�������
			return i;
		}
	}
}

void print(int** Maze) {//���Թ�
	int i, j;
	for (i = 0; i < L; i++) {
		for (j = 0; j < L; j++) {
			if (Maze[i][j] == ROUTE)
				printf("  ");//��ʾ��·
			else if (Maze[i][j] == WALL)
				printf("��");//��ʾǽ��
			else
				printf("ʮ");//��ʾ���
		}
		printf("\n");
	}
}
//��ԭ�ȵ�����int &x������Ϊ���ڵ�ָ��ָ��int *x
void move(int** Maze, char t, int *x, int *y) {//�ƶ���ɫ
	int i = *x, j = *y;//��¼ԭʼλ��
	switch (t) {
	case 'w':    //�����ƶ�
		*x -= 1;
		break;
	case 's':    //�����ƶ�
		*x += 1;
		break;
	case 'a':    //�����ƶ�
		*y -= 1;
		break;
	case 'd':    //�����ƶ�
		*y += 1;
		break;
	default:
		break;
	}
	if (*x >= 0 && *x < L - 1 && *y >= 0 && *y < L - 1 && Maze[*x][*y] != WALL) {//�����������ƶ�
		Maze[i][j] = 1;
		Maze[*x][*y] = 2;
	}
	else {//����λ�ò���
		*x = i;
		*y = j;
	}
}

void start() { //��ʼһ����Ϸ
	char t;
	//y,x��ʾ��ɫ��������, out��ʾ���ڵ�������
	int *p, *q;
	int x = 2, y = 1, out = 0, i = 0;
	p = &x;
	q = &y;
	//�������������ʼ������
	srand((unsigned)time(NULL));
	//��������ռ�
	int **Maze = (int**)malloc(L * sizeof(int *));
	for (i = 0; i < L; i++) {
		Maze[i] = (int*)calloc(L, sizeof(int));
	}
	//�õ�����������
	out = init(Maze);
	//��Ϸ��ʼ
	system("cls");
	print(Maze);
	while (t = _getch()) {
		if (t == 27)   //�������ΪESC����������Ϸ�ص����˵�
			break;
		system("cls");//����
		move(Maze, t, p, q);//��������t�����ƶ�
		print(Maze);//���»����Թ�
		if (x == out && y == L - 2) {//�Ѿ������ڣ���Ϸ����
			system("cls");
			printf("=============\n");
			printf("�� Ϸ ʤ ����\n");
			printf("=============\n");
			printf("�����󷵻����˵�����");
			Sleep(1500);//ִ�й���һ��ʱ�䣬��ͣ1.5����ӡ
			break;
		}
	}
	//һ����Ϸ�������ͷ��ڴ�
	for (i = 0; i < L; i++) free(Maze[i]);
	free(Maze);
}

void explain() { //����˵��
	while (1) {
		char t;
		system("cls");
		printf("=================================================\n");
		printf("��л�����鱾��Ϸ����Ϸ�Ĳ������£�\n");
		printf("\n1.�����뷨����ΪӢ�ģ�Сд��\n");
		printf("\n2.ͨ��w,s,a,d�ĸ������ƽ�ɫ���������ƶ�\n");
		printf("\n3.�����������ɰ���ESC�������ص����˵�\n");
		printf("\nʤ���������ƶ���ɫ�����ڴ������͸�λ(������)\"!\n");
		printf("=================================================\n");
		t = _getch();  //�����Ժ���
		switch (t) {
			//ESC����ASCII��ֵ
		case 27:
			//�������˵�
			menu();
			break;
		default:
			break;
		}
	}
}

void degree() { //������Ϸ�Ѷ�
	while (1) {
		char t;
		system("cls");
		printf("=======================\n");
		printf("����1,2,3�����Ѷȵ�����\n");
		printf("\n||    1.��  ��    ||\n");
		printf("\n||    2.��  ��    ||\n");
		printf("\n||    3.��  ��    ||\n");
		printf("=======================\n");
		t = _getch();  //�����Ժ���
		switch (t) {
		case '1':
			Rank = 6;
			printf("\n��ǰ�Ѷȣ��򵥣������������˵�����");
			Sleep(1500);
			menu();//�������˵�
			break;
		case '2':
			Rank = 3;
			printf("\n��ǰ�Ѷȣ��еȣ������������˵�����");
			Sleep(1500);
			menu();//�������˵�
			break;
		case '3':
			Rank = 0;
			printf("\n��ǰ�Ѷȣ����ѣ������������˵�����");
			Sleep(1500);
			menu();//�������˵�
			break;
		case 27:
			menu();
			break;
		default:
			break;
		}
	}
}