#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define LEN 10//��ͼy�᳤
#define WID 120//��ͼx�᳤
#define CAPACITY 10//������¼����

void Point() {
	system("cls");
	char buf[CAPACITY] = { NULL };
	FILE* fp = NULL;
	if (fp = (fopen( "D:\\vs\\Project1\\point\\first", "r") != NULL)) {
		fgets(buf, 10, fp);
		puts("���µ��ɵĳɼ�Ϊ��");
		for (int i = 0; i < CAPACITY; i++) {
			printf("%d", buf[i]);
		}
	}
	puts("��������뿪");
	_getch();

}

void eatline(void) {
	while (getchar() != '\n') {
		continue;
	}
}

void main(){
	int step = 0;//����ƶ�����
	char Map[LEN][WID] = { NULL };
	char index;
RE:
	puts("n)��ʼ����Ϸ    c)������Ϸ\n"
		"q)�˳���Ϸ    s)�鿴����\n"
		"�����뵥����ĸ��");
	
	//��ȡ�˵�����

	while (1) {
		char ch=NULL;
		ch=_getch();
		ch = tolower(ch);//ת��ΪСд��ĸ
		eatline();

		//�������
		if (strchr("ncqs", ch)) {
			switch (ch) {
			case 'c':index = 'c'; break;
			case 'n':index = 'n'; break;
			case 'q':exit(1);
			case 's':Point(); break;
			}
			//����ɹ��뿪ѭ��
			break;
		}
		else {
			puts("������������뵥��"
				"��ĸn��c��q��s");
		}
	}

	int mode = 0;

	//�ж��Ƿ�ʼ����Ϸ

	if (index == 'c') {//������Ϸ
		mode++;

	}
	else {//����Ϸ
		(step) = 0;//������Ҳ���
	}

	//��������ƶ������߼�
	
	int x, y;//�������
	int Xx, Xy;//X���꣬������Ŀ�ĵ�����
	int Ox, Oy;//��������
	int cpx,cpy,cpox,cpoy;//���긱�� 
		
		

	while (1) {
		system("cls");
		
		//����Ϸ
		if (mode == 0) {//����Ϸ
			puts("��ѡ��ؿ�1���߹ؿ�2��"
				"�������֣�");
			int level;
			FILE* fp;
			//char* map = NULL;
			
			int flag=1;

			while (flag) {
				scanf("%d",&level);
				eatline();
				if (level == 1 || level == 2) {
					switch (level) {
						case 1:if ((fp=fopen("D:\\vs\\Project2\\map\\map1.txt","r"))!= NULL) {
								//���桢��ʼ����ͼ
									for (int i = 0; i < LEN; i++) {
										for (int j = 0; j < WID; j++) {
											Map[i][j] = getc(fp);
										}
									}
									flag=0;
								}
								else {
									puts("�����޷��򿪵�ͼ");
									puts("��������뿪��Ϸ");
									_getch();
									exit(0);
								} 
								break;
						case 2:if ((fp=fopen("D:\\vs\\Project2\\map\\map2.txt","r") )!= NULL) {
								//���桢��ʼ����ͼ
									for (int i = 0; i < LEN; i++) {
										for (int j = 0; j < WID; j++) {
											Map[i][j] = getc(fp);
										}
									}
									flag=0;
								}
								else {
									puts("�����޷��򿪵�ͼ");
									puts("��������뿪��Ϸ");
									_getch();
									exit(0);
								} 
								break;
					}
				}
				else {
					puts("�������");
					puts("��ѡ��ؿ�1���߹ؿ�2��"
						"�������֣�");
				}
			}
		}
		//�����ͼ

		for (int i = 0; i < LEN; i++) {
			for (int j = 0; j < WID; j++) {
				if (Map[i][j] == 'p') {
					printf("\n");
				}
				else {
					printf("%c", Map[i][j]);
				}
			}
		}
		puts("\"+\"����߽磬\"*\"�����㣬\"O\"��������");
		puts("\"X\"���������ӵ�Ŀ�ĵأ�\"w\"\"s\"\"a\"\"d\"�ֱ�������������ƶ�");
		puts("����\"m\"���ز˵�");
		printf("��ķ�����%d\n", 100 - step);

		int goon = 0;//����ͼ����X��־
		for (int i = 0; i < LEN; i++) {//��Ϸ����
			for (int j = 0; j < WID; j++) {
				if (Map[i][j] == 'X') {
					goon++;
				}
			}
		}
		if (goon==0) {//����ȫ����λ
			printf("You Win!\n");
			FILE* p;
			
			if ((p = fopen( "D:\\vs\\Project1\\point\\first", "a") )!= NULL) {
				fputs(step,p);
			}
			else {
				printf("error,can't open this file\n");
				exit(1);
			}
			break;
		}

		char input;
		input = _getch();
		//���ز˵�
		if (input == 'm') {
			goto RE;
		}

		//�ƶ�

		/*int x, y;//�������
		int Xx, Xy;//X���꣬������Ŀ�ĵ�����
		int Ox, Oy;//��������
		*/
		
		//�ڵ�ͼ�в�����������������
		for (int i = 0; i < LEN; i++) {
			for (int j = 0; j < WID; j++) {
				switch (Map[i][j]) {
				case '*':x = i; y = j; break;
				case 'X':Xx = i; Xy = j; break;
				case 'O':Ox = i; Oy = j; break;
				}
			}
		}

		cpx = x, cpy = y, cpox = Ox, cpoy = Oy;//����λ������
		switch (input) {
		case 'a':cpy--; break;
		case 'd':cpy++; break;
		case 'w':cpx--; break;
		case 's':cpx++; break;
		}
		if (Map[cpx][cpy] == '+') {//ײǽ
			cpx = x; cpy = y;
		}
		else if (Map[cpx][cpy] == 'O') {//������
			int chax, chay;//��������������ֵ
			chax = x - Ox;
			chay = y - Oy;

			//�Ʋ���������
			if (chax < 0) {
				cpox++;
			}
			else if (chax > 0) {
				cpox--;
			}

			if (chay < 0) {
				cpoy++;
			}
			else if (chay > 0) {
				cpoy--;
			}

			//Ԥ�����ӵ�λ���Ƿ����
			if (Map[cpox][cpoy] == '+') {
				cpox = Ox;
				cpoy = Oy;
				cpx=x;
				cpy=y;
			}

		}

		//����ƶ�
		//��������ӡ������ͼ��X����ʾ��Ϸ����
		Map[x][y]=' ';//���֮ǰ�������
		Map[Ox][Oy]=' ';//����������� 
		Map[cpx][cpy] = '*';
		Map[Xx][Xy] = 'X';
		Map[cpox][cpoy] = 'O';

		(step)++;
		mode++;//������Ϸ 
	}

}


