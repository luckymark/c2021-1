#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define LEN 10//地图y轴长
#define WID 120//地图x轴长
#define CAPACITY 10//分数记录条数

void Point() {
	system("cls");
	char buf[CAPACITY] = { NULL };
	FILE* fp = NULL;
	if (fp = (fopen( "D:\\vs\\Project1\\point\\first", "r") != NULL)) {
		fgets(buf, 10, fp);
		puts("由新到旧的成绩为：");
		for (int i = 0; i < CAPACITY; i++) {
			printf("%d", buf[i]);
		}
	}
	puts("按任意键离开");
	_getch();

}

void eatline(void) {
	while (getchar() != '\n') {
		continue;
	}
}

void main(){
	int step = 0;//玩家移动步数
	char Map[LEN][WID] = { NULL };
	char index;
RE:
	puts("n)开始新游戏    c)继续游戏\n"
		"q)退出游戏    s)查看分数\n"
		"请输入单个字母：");
	
	//读取菜单输入

	while (1) {
		char ch=NULL;
		ch=_getch();
		ch = tolower(ch);//转换为小写字母
		eatline();

		//检查输入
		if (strchr("ncqs", ch)) {
			switch (ch) {
			case 'c':index = 'c'; break;
			case 'n':index = 'n'; break;
			case 'q':exit(1);
			case 's':Point(); break;
			}
			//输入成功离开循环
			break;
		}
		else {
			puts("输入错误。请输入单个"
				"字母n、c、q、s");
		}
	}

	int mode = 0;

	//判断是否开始新游戏

	if (index == 'c') {//继续游戏
		mode++;

	}
	else {//新游戏
		(step) = 0;//重置玩家步数
	}

	//控制玩家移动及其逻辑
	
	int x, y;//玩家坐标
	int Xx, Xy;//X坐标，即箱子目的地坐标
	int Ox, Oy;//箱子坐标
	int cpx,cpy,cpox,cpoy;//坐标副本 
		
		

	while (1) {
		system("cls");
		
		//新游戏
		if (mode == 0) {//新游戏
			puts("请选择关卡1或者关卡2，"
				"输入数字：");
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
								//保存、初始化地图
									for (int i = 0; i < LEN; i++) {
										for (int j = 0; j < WID; j++) {
											Map[i][j] = getc(fp);
										}
									}
									flag=0;
								}
								else {
									puts("错误：无法打开地图");
									puts("按任意键离开游戏");
									_getch();
									exit(0);
								} 
								break;
						case 2:if ((fp=fopen("D:\\vs\\Project2\\map\\map2.txt","r") )!= NULL) {
								//保存、初始化地图
									for (int i = 0; i < LEN; i++) {
										for (int j = 0; j < WID; j++) {
											Map[i][j] = getc(fp);
										}
									}
									flag=0;
								}
								else {
									puts("错误：无法打开地图");
									puts("按任意键离开游戏");
									_getch();
									exit(0);
								} 
								break;
					}
				}
				else {
					puts("输入错误");
					puts("请选择关卡1或者关卡2，"
						"输入数字：");
				}
			}
		}
		//输出地图

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
		puts("\"+\"代表边界，\"*\"代表你，\"O\"代表箱子");
		puts("\"X\"代表推箱子的目的地，\"w\"\"s\"\"a\"\"d\"分别控制上下左右移动");
		puts("输入\"m\"返回菜单");
		printf("你的分数是%d\n", 100 - step);

		int goon = 0;//若地图上无X标志
		for (int i = 0; i < LEN; i++) {//游戏结束
			for (int j = 0; j < WID; j++) {
				if (Map[i][j] == 'X') {
					goon++;
				}
			}
		}
		if (goon==0) {//箱子全部归位
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
		//返回菜单
		if (input == 'm') {
			goto RE;
		}

		//移动

		/*int x, y;//玩家坐标
		int Xx, Xy;//X坐标，即箱子目的地坐标
		int Ox, Oy;//箱子坐标
		*/
		
		//在地图中查找上面三个的坐标
		for (int i = 0; i < LEN; i++) {
			for (int j = 0; j < WID; j++) {
				switch (Map[i][j]) {
				case '*':x = i; y = j; break;
				case 'X':Xx = i; Xy = j; break;
				case 'O':Ox = i; Oy = j; break;
				}
			}
		}

		cpx = x, cpy = y, cpox = Ox, cpoy = Oy;//复制位置坐标
		switch (input) {
		case 'a':cpy--; break;
		case 'd':cpy++; break;
		case 'w':cpx--; break;
		case 's':cpx++; break;
		}
		if (Map[cpx][cpy] == '+') {//撞墙
			cpx = x; cpy = y;
		}
		else if (Map[cpx][cpy] == 'O') {//推箱子
			int chax, chay;//箱子与玩家坐标差值
			chax = x - Ox;
			chay = y - Oy;

			//推测箱子坐标
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

			//预判箱子的位置是否合理
			if (Map[cpox][cpoy] == '+') {
				cpox = Ox;
				cpoy = Oy;
				cpx=x;
				cpy=y;
			}

		}

		//输出移动
		//箱子最后打印，若地图无X，表示游戏结束
		Map[x][y]=' ';//玩家之前坐标清空
		Map[Ox][Oy]=' ';//清空箱子坐标 
		Map[cpx][cpy] = '*';
		Map[Xx][Xy] = 'X';
		Map[cpox][cpoy] = 'O';

		(step)++;
		mode++;//继续游戏 
	}

}


