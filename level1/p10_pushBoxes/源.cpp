#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>

#define WALL 0
#define BOX 2
#define CHARA 3
#define CHARA_END 6
#define ROUTE 1
#define SIZE 8
#define END 4
#define W 5
FILE *map1;
FILE *map2;
FILE *map3;
FILE *score;

void CREATEMAZE(int *x, int *y);//������ͼ
void menu();   //���˵�����
void start();  //��ʼ��Ϸ
char degree(); //��Ϸ�Ѷ�
void move(int maze[SIZE][SIZE], char t, int *x, int *y);//�ƶ���ɫ
int win(int maze[SIZE][SIZE]);
int anciiToInt(int);
char *guanp;
int maze[SIZE][SIZE] =
{
{0},
{0,0,0,4},
{0,0,0,1},
{0,0,0,2,1,2,4,0},
{0,4,1,2,3,0,0,0},
{0,0,0,0,2},
{0,0,0,0,4},
{0}
};
int main()
{
    degree();
	menu();
	return 0;
}
void CREATEMAZE(int *x,int *y)
{
	
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			switch (maze[i][j])
			{
			case WALL:printf("��");
				break;//��ʾǽ��
			case ROUTE:printf("  ");
				break;//��ʾ��·
			case CHARA:
			case CHARA_END:printf("ʮ");
				*x = i;
				*y = j;
				break;//��ʾ���
			case BOX:printf("��");
				break;
			case END:printf("**");
				break;
			case W:printf("��");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
}
void menu() { //���˵�
	while (1) {
		system("cls"); //����
		char t;
		printf("*******(������)*******");
		printf("\n======================\n");
		printf("\n||   1. ��ʼ��Ϸ   ||\n");
		printf("\n||   2. �����Ѷ�   ||\n");
		printf("\n||   3. �ر���Ϸ   ||\n");
		printf("======================\n");
		t = _getch();    //�����Ժ���
		switch (t) {
		case '1':
			start();
			break;  //��ʼһ����Ϸ

		case '2':
			degree();
			break;  //������Ϸ�Ѷ�
		case '3':
			printf("\n��ӭ�´����棬�ټ�����������J");
			Sleep(1500);
			exit(0);
			break;  //��������
		default:
			break;
		}
	}
}
char degree() { //������Ϸ�Ѷ�
	while (1) {
		char guan;
		int i = 0;
		int j = 0;
		system("cls");
		printf("=======================\n");
		printf("����1,2,3�����Ѷȵ�����\n");
		printf("\n||    1.��  ��    ||\n");
		printf("\n||    2.��  ��    ||\n");
		printf("\n||    3.��  ��    ||\n");
		printf("=======================\n");
		guan = _getch();
		guanp = &guan;
		switch (guan) {
		case '1':
			fopen_s(&map1, "map1.txt", "r");
			for (; i < SIZE; i++)
			{
				j = 0;
				for (; j < SIZE; j++)
				{
					maze[i][j] = anciiToInt(fgetc(map1));
				}
			}
			printf("\n��ǰ�Ѷȣ��򵥣������������˵�����");
			Sleep(1500);
			fclose(map1);
			menu();//�������˵�
			break;
		case '2':
			fopen_s(&map2, "map2.txt", "r");
			for (; i < SIZE; i++)
			{
				j = 0;
				for (; j < SIZE; j++)
				{
					maze[i][j] = anciiToInt(fgetc(map2));
				}
			}
				printf("\n��ǰ�Ѷȣ��еȣ������������˵�����");
				Sleep(1500);
				fclose(map2);
				menu();//�������˵�
				break;
		case '3':
			fopen_s(&map3, "map3.txt", "r");
			for (; i < SIZE; i++)
			{
				j = 0;
				for (; j < SIZE; j++)
				{
					maze[i][j] = anciiToInt(fgetc(map3));
				}
			}
			printf("\n��ǰ�Ѷȣ����ѣ������������˵�����");
			fclose(map3);
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
void start() { //��ʼһ����Ϸ
	char t;
	int x=1,y=2,count=0;//count�Ʒ�
	int *p=&x, *q=&y;
	system("cls");
	CREATEMAZE(p,q);
	while (t = _getch()) {
		if (t == 27)   //�������ΪESC����������Ϸ�ص����˵�
			break;
		system("cls");//����
		move(maze, t, p, q);//��������t�����ƶ�
		count++;
		CREATEMAZE(p, q);//���»����Թ�
		int k =win(maze);
		if (k==0) {//
			system("cls");
			printf("=============\n");
			printf("�� Ϸ ʤ ����\n");
			printf("��%d����һ��ʹ��%d��\n",*guanp-48,count);
			fopen_s(&score, "score.txt", "a+");
			fprintf(score, "%s%d%s%d%s", "��",*guanp-48,"����һ��ʹ��",count,"��\n");
			fclose(score);
			printf("�����󷵻����˵�����");
			Sleep(1500);//ִ�й���һ��ʱ�䣬��ͣ1.5����ӡ
			break;
		}
	}
}
void move(int maze[SIZE][SIZE], char t, int *x, int *y)
{
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
	if (maze[i][j] != CHARA_END)
	{
		if (maze[*x][*y] == ROUTE)
		{
			maze[*x][*y] = CHARA;
			maze[i][j] = ROUTE;
		}
		else if (maze[*x][*y] == BOX)
		{
			int a = *x;
			int b = *y;
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
			if (maze[*x][*y] == ROUTE)
			{
				maze[*x][*y] = BOX;
				maze[a][b] = CHARA;
				maze[i][j] = ROUTE;
			}
			else if (maze[*x][*y] == END)
			{
				maze[*x][*y] = W;
				maze[a][b] = CHARA;
				maze[i][j] = ROUTE;
			}
			else
			{
				*x = i;
				*y = j;
			}
		}
		else if (maze[*x][*y] == W)
		{
			int a = *x;
			int b = *y;
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
			if (maze[*x][*y] == ROUTE)
			{
				maze[*x][*y] = BOX;
				maze[a][b] = CHARA_END;
				maze[i][j] = ROUTE;
			}
			else if (maze[*x][*y] == END)
			{
				maze[*x][*y] = W;
				maze[a][b] = CHARA_END;
				maze[i][j] = ROUTE;
			}
			else
			{
				*x = i;
				*y = j;
			}
		}
		else if (maze[*x][*y] == END)
		{
			maze[*x][*y] = CHARA_END;
			maze[i][j] = ROUTE;
		}
		else
		{
			*x = i;
			*y = j;
		}
	}
	else 
	{
		if (maze[*x][*y] == ROUTE)
		{
			maze[*x][*y] = CHARA;
			maze[i][j] = END;
		}
		else if (maze[*x][*y] == BOX)
		{
			int a = *x;
			int b = *y;
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
			if (maze[*x][*y] == ROUTE)
			{
				maze[*x][*y] = BOX;
				maze[a][b] = CHARA;
				maze[i][j] = END;
			}
			else if (maze[*x][*y] == END)
			{
				maze[*x][*y] = W;
				maze[a][b] = CHARA;
				maze[i][j] = END;
			}
			else
			{
				*x = i;
				*y = j;
			}
		}
		else if (maze[*x][*y] == W)
		{
			int a = *x;
			int b = *y;
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
			if (maze[*x][*y] == ROUTE)
			{
				maze[*x][*y] = BOX;
				maze[a][b] = CHARA_END;
				maze[i][j] = END;
			}
			else if (maze[*x][*y] == END)
			{
				maze[*x][*y] = W;
				maze[a][b] = CHARA_END;
				maze[i][j] = END;
			}
			else
			{
				*x = i;
				*y = j;
			}
		}
		else if (maze[*x][*y] == END)
		{
			maze[*x][*y] = CHARA_END;
			maze[i][j] = END;
		}
		else
		{
			*x = i;
			*y = j;
		}
	}

}
int win(int maze[SIZE][SIZE])
{
	int k = 0;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (maze[i][j] == END|| maze[i][j] == CHARA_END)
					k++;
			}
		}
	return k;
}

int anciiToInt(int ascii) {
	switch (ascii)
	{
	case 48:
		return 0;
	case 49:
		return 1;
	case 50:
		return 2;
	case 51:
		return 3;
	case 52:
		return 4;
	case 53:
		return 5;
	case 54:
		return 6;
	case 10:
		return 0;
	default:
		return 0;
		break;
	}
}