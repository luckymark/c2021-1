#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<stdbool.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
int Score=0;
char s[10];
int GuanQia = 0;
int NL = 0;//上限为200
int player_attact1 = 1;
int player_attact2 = 2;
int player_attact = 0;

IMAGE begin[4];//开始界面
IMAGE bk;//背景图片
IMAGE ima_player[2];//玩家图片
IMAGE ima_bull[4];//子弹图片
IMAGE ima_monster[3][2];
IMAGE boss[2];
IMAGE instruction;
IMAGE monster_attact_small[2][2];
IMAGE stone[2][2];
IMAGE hit[2];
IMAGE bk_shibai;
IMAGE bk_cg;
IMAGE NL1;
IMAGE NL2;
IMAGE NL_b;
IMAGE NL_b2;
IMAGE zidan_b[2];
IMAGE feeling;
IMAGE boss_attact[2][2];

enum My
{
	WID = 500,
	LEN = 935,
	BULL_LET_NUM = 30,
	ENEMY_NUM = 20,
	TIME_NUM = 100,
	BIG,
	SMALL,
	BOSS,
	MOD_BIG = 50,
	MOD_SMALL = 15,
	MONSTER_BULL_SAMLL = 2,
	PLAYER_HP = 150,
	BOSS_HP=1200,
	BOSS_BULL_NUM=30,
	STONE_HP=500
};
MOUSEMSG mouse;
struct Plane
{
	int x, y;
	bool live;
	int width;
	int length;
	int hp;
	int type;//敌机的类型
}player, bull[BULL_LET_NUM], monster[ENEMY_NUM], Monster_bull[ENEMY_NUM][MONSTER_BULL_SAMLL], Stone_1, Boss, Boss_bull[BOSS_BULL_NUM], Boss_attact_b;


static DWORD t1[TIME_NUM], t2[TIME_NUM];///时间静态定义

void loadImage()//获取，加载图片
{
	loadimage(&bk, "D:\\C++\\picture\\bk.jpg");//背景
	//玩家
	loadimage(&ima_player[0], "D:\\C++\\picture\\player2.jpg");//先用掩码图
	loadimage(&ima_player[1], "D:\\C++\\picture\\player1.jpg");
	//子弹
	loadimage(&ima_bull[0], "D:\\C++\\picture\\zidan2.jpg");//文件后缀名为2的都是掩码图
	loadimage(&ima_bull[1], "D:\\C++\\picture\\zidan1.jpg");
	//怪_SMALL
	loadimage(&ima_monster[0][0], "D:\\C++\\picture\\mos02.jpg");//第一种，绿的圆的,Stone_1.hp
	loadimage(&ima_monster[0][1], "D:\\C++\\picture\\mos01.jpg");
	//怪_BIG
	loadimage(&ima_monster[1][0], "D:\\C++\\picture\\mos12.jpg");//第二种，头白，细长
	loadimage(&ima_monster[1][1], "D:\\C++\\picture\\mos11.jpg");
	//BOSS
	loadimage(&boss[0], "D:\\C++\\picture\\boss1.jpg");
	loadimage(&boss[1], "D:\\C++\\picture\\boss2.jpg");
	//boss的第一种弹幕
	loadimage(&boss_attact[0][0], "D:\\C++\\picture\\boss_attact1.jpg");///////////////////////////
	loadimage(&boss_attact[0][1], "D:\\C++\\picture\\boss_attact2.jpg");
	//boss的第二种弹幕
	loadimage(&boss_attact[1][0], "D:\\C++\\picture\\boss_attact_b1.jpg");///////////////////////////
	loadimage(&boss_attact[1][1], "D:\\C++\\picture\\boss_attact_b2.jpg");
	//怪物的第一种攻击
	loadimage(&monster_attact_small[0][0], "D:\\C++\\picture\\monster_attact_small2.jpg");
	loadimage(&monster_attact_small[0][1], "D:\\C++\\picture\\monster_attact_small1.jpg");
	//攻击反馈
	loadimage(&hit[0], "D:\\C++\\picture\\hit1.jpg");
	loadimage(&hit[1], "D:\\C++\\picture\\hit2.jpg");
	//失败
	loadimage(&bk_shibai, "D:\\C++\\picture\\bk_shibai.jpg");
	//成功
	loadimage(&bk_cg, "D:\\C++\\picture\\bk_cg.jpg");
	//能量
	loadimage(&NL1, "D:\\C++\\picture\\NL1.jpg");
	loadimage(&NL2, "D:\\C++\\picture\\NL2.jpg");//掩码图
	loadimage(&NL_b, "D:\\C++\\picture\\NL_b.jpg");
	loadimage(&NL_b2, "D:\\C++\\picture\\NL_b2.jpg");//金色掩码图
	//第二种子弹
	loadimage(&zidan_b[0], "D:\\C++\\picture\\zidan_b1.jpg");
	loadimage(&zidan_b[1], "D:\\C++\\picture\\zidan_b2.jpg");
	//结尾感言
	loadimage(&feeling, "D:\\C++\\picture\\feeling.jpg");
}
void enemy_hp(int i)//设计敌人血量
{
	srand(time(NULL));
	if (rand() % 7 == 0)//大的怪
	{
		monster[i].type = BIG;
		monster[i].hp = MOD_BIG;
		monster[i].width = 116;
		monster[i].length = 200;
	}
	else//SMALL 小的怪
	{
		monster[i].type = SMALL;
		monster[i].hp = MOD_SMALL;
		monster[i].width = 80;
		monster[i].length = 61;
	}
}
void GameInit()
{
	
	loadImage();
	//玩家数据
	player.x = WID / 2 - 48;
	player.y = LEN - 82;
	player.hp = PLAYER_HP;
	player.live = true;
	player.width = 96;
	player.length = 82;
	//陨石数据
	Stone_1.hp = STONE_HP;
	Stone_1.length = 200;
	Stone_1.width = 200;
	Stone_1.live = false;
	//boss数据
	Boss.live = false;
	Boss.hp = BOSS_HP;
	Boss.length = 350;
	Boss.width = 500;
	Boss.x = 0;
	Boss.y = -400;
	Boss_attact_b.live = false;
	Boss_attact_b.x = 0;
	Boss_attact_b.y = 0;
	Boss_attact_b.length = 300;
	Boss_attact_b.width = 150;


	srand(time(NULL));
	Stone_1.x = rand()%330;
	Stone_1.y = -200;
	//
	for (int i = 0; i < BULL_LET_NUM; i++)//初始化子弹
	{
		bull[i].x = 0;
		bull[i].y = 0;
		bull[i].live = false;
	}
	for (int i = 0; i < BOSS_BULL_NUM; i++)//定义boss的子弹
	{
		Boss_bull[i].live = false;
		Boss_bull[i].x = 0;
		Boss_bull[i].y = -30;
	}
	for (int i = 0; i < ENEMY_NUM; i++)//初始化敌机
	{
		monster[i].live = false;
	}
	for (int j = 0; j < ENEMY_NUM; j++)
	{
		for (int i = 0; i < MONSTER_BULL_SAMLL; i++)//初始化敌人子弹
		{
			Monster_bull[j][i].x = 0;
			Monster_bull[j][i].y = 0;
			Monster_bull[j][i].length = 30;
			Monster_bull[j][i].width = 30;
			Monster_bull[j][i].live = false;
		}
	}
	
}
bool Timer(int i, int ms)
{
	if (t2[i] - t1[i] > ms)
	{
		t1[i] = t2[i];
		return true;
	}
	t2[i] = clock();
	return false;
}
void GameDraw()//游戏的绘制函数
{
	putimage(0, 0, &bk);
	//绘制技能图片
	
	if (NL < 400)
	{
		rectangle(50, 890, 450, 910);
		setfillcolor(GREEN);
		fillrectangle(50, 890, 50+NL, 910);
		putimage(0, 830, &NL_b2, NOTSRCERASE);
		putimage(0, 830, &NL_b, SRCINVERT);
		player_attact = player_attact1;
	}
	if (NL >= 400)
	{
		rectangle(50, 890, 450, 910);
		setfillcolor(RED);
		fillrectangle(50, 890, 450, 910);
		putimage(0, 830, &NL_b2, NOTSRCERASE);
		putimage(0, 830, &NL_b, SRCINVERT);
		player_attact = player_attact2;
	}
	
	

	putimage(player.x, player.y, &ima_player[0], NOTSRCERASE);//掩码图
	putimage(player.x, player.y, &ima_player[1], SRCINVERT);
	if (Stone_1.live && Stone_1.hp > 0)//陨石图片
	{

		putimage(Stone_1.x, Stone_1.y, &stone[0][0], NOTSRCERASE);
		putimage(Stone_1.x, Stone_1.y, &stone[0][1], SRCINVERT);
	}
	if (Boss.live && Boss.hp > 0)//BOSS图片
	{

		putimage(Boss.x, Boss.y, &boss[1], NOTSRCERASE);
		putimage(Boss.x, Boss.y, &boss[0], SRCINVERT);
	}
	//boss子弹
	for (int i = 0; i < BOSS_BULL_NUM; i++)
	{
		if (Boss_bull[i].live)
		{
			putimage(Boss_bull[i].x, Boss_bull[i].y, &boss_attact[0][1], NOTSRCERASE);
			putimage(Boss_bull[i].x, Boss_bull[i].y, &boss_attact[0][0], SRCINVERT);
		}
	}
	//boss的第二种攻击方式
	if (Boss.live==true&&Boss_attact_b.live==true)
	{
		putimage(Boss_attact_b.x, Boss_attact_b.y, &boss_attact[1][1], NOTSRCERASE);
		putimage(Boss_attact_b.x, Boss_attact_b.y, &boss_attact[1][0], SRCINVERT);
	}
	for (int i = 0; i < BULL_LET_NUM; i++)//玩家子弹
	{
		if (bull[i].live)
		{
			if (NL < 400)
			{
				putimage(bull[i].x, bull[i].y, &ima_bull[0], NOTSRCERASE);
				putimage(bull[i].x, bull[i].y, &ima_bull[1], SRCINVERT);
			}
			if (NL >= 400)
			{
				putimage(bull[i].x, bull[i].y, &zidan_b[1], NOTSRCERASE);
				putimage(bull[i].x, bull[i].y, &zidan_b[0], SRCINVERT);
			}
		}
	}
	for (int j = 0; j < ENEMY_NUM; j++)//怪物子弹
	{
		for (int i = 0; i < MONSTER_BULL_SAMLL; i++)
		{
			if (Monster_bull[j][i].live)
			{
				putimage(Monster_bull[j][i].x, Monster_bull[j][i].y, &monster_attact_small[0][0], NOTSRCERASE);
				putimage(Monster_bull[j][i].x, Monster_bull[j][i].y, &monster_attact_small[0][1], SRCINVERT);
			}
		}
	}
	//怪
	for (int i = 0; i < ENEMY_NUM; i++)
	{

		if (monster[i].live)
		{
			if (monster[i].type == BIG)
			{
				putimage(monster[i].x, monster[i].y, &ima_monster[1][0], NOTSRCERASE);
				putimage(monster[i].x, monster[i].y, &ima_monster[1][1], SRCINVERT);
			}
			else if (monster[i].type == SMALL)
			{
				putimage(monster[i].x, monster[i].y, &ima_monster[0][0], NOTSRCERASE);
				putimage(monster[i].x, monster[i].y, &ima_monster[0][1], SRCINVERT);
			}
		}
	}
}
//int Timer2(long time)
//{
//	clock_t start;
//	start = clock();
//	while (1)
//	{
//		if (clock() - start <= time)
//		{
//
//		}
//		else
//		{
//			return true;
//			break;
//		}
//	}
//}
void Create_bull()
{
	for (int i = 0; i < BULL_LET_NUM ; i++)
	{
		if (!bull[i].live)
		{
			bull[i].x = player.x + 33;
			bull[i].y = player.y;
			bull[i].live = true;
			break;
		}
	}
}
void Bull_move()
{
	for (int i = 0; i < BULL_LET_NUM; i++)
	{
		if (bull[i].live)
		{
			
			bull[i].y -= 1;
			if (bull[i].y < 0)
			{
				bull[i].live = false;
			}
		}
	}
}
void PlayerMove(int speed)
{
	//用_getch()的老旧函数
#if 0
#   /*if (_kbhit())
	{
		char k = _getch();
		switch (k)
		{
		case 'w':
		case 'W':
			player.y -= speed;
			break;
		case 's':
		case 'S':
			player.y += speed;
			break;
		case 'a':
		case 'A':
			player.x -= speed;
			break;
		case 'd':
		case 'D':
			player.x += speed;
			break;
		default:
			break;
		}
	}*/
#endif
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
	{
		if (player.y > 0 && Timer(81,1))
		{
			player.y -= speed;
		}
	}
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
	{
		if (player.y < 847 && Timer(82, 1))
		{
			player.y += speed;
		}
	}
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
	{
		if (player.x + 45 > 0 && Timer(83, 1))
		{
			player.x -= speed;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
	{
		if (player.x < 455 && Timer(84, 1))
		{
			player.x += speed;
		}
	}
	if (GetAsyncKeyState('T'))
	{
		system("pause");
	}
	
	//发射子弹
	static DWORD t1, t2;
	if (GetAsyncKeyState(VK_SPACE) && t2 - t1 > 50)
	{
		Create_bull();
		t1 = t2;
	}
	t2 = GetTickCount();
}
void Create_monster()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (!monster[i].live)
		{
			monster[i].live = true;
			
			monster[i].x = rand() % 450;
			monster[i].y = -200;
			enemy_hp(i);
			break;
		}
	}
}
void MonsterMove()//怪移动
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (monster[i].live)
		{
			if (monster[i].type == SMALL)
			{
				if (Timer(i, 12))
				{
					monster[i].y += 1;
					if (monster[i].y > LEN)
					{
						monster[i].live = false;
						Score -= 100;
					}
				}
			}
			else if(monster[i].type == BIG)
			{
				 if (Timer(i, 12))
				 {
					 monster[i].y += 1;
					 if (monster[i].y > LEN)
					 {
						monster[i].live = false;
						Score -= 200;
					 }
				 }
			}
		}
	}
}

void PlayGame()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (!monster[i].live)
		{
			continue;
		}
		for (int j = 0; j < BULL_LET_NUM; j++)
		{
			if (!bull[j].live)
			{
				continue;
			}
			if (monster->type == SMALL)//玩家攻击第一种小怪（小
			{
				if (bull[j].x > monster[i].x - 30 && bull[j].x < monster[i].x + monster[i].width && bull[j].y<monster[i].y + monster[i].length
					&& bull[j].y>monster[i].y)
				{
					NL++;
					bull[j].live = false;
					putimage(bull[j].x, bull[j].hp - 40, &hit[1], NOTSRCERASE);
					putimage(bull[j].x, bull[j].hp - 40, &hit[0], SRCINVERT);
					monster[i].hp -= player_attact;
					if (player.hp < PLAYER_HP / 2)
					{
						player.hp++;
					}
					if (monster[i].hp <= 0)
					{
						monster[i].live = false;
						mciSendString("close boom", 0, 0, 0);//爆炸声
						mciSendString("open D:/C++/picture/v/boom.mp3 alias boom", 0, 0, 0);//爆炸声
						mciSendString("play boom ", 0, 0, 0);//爆炸声
						Score += (77+2*i);
					}
				}

			}
			if (monster->type == BIG)//玩家攻击第二种小怪（da
			{
				if (bull[j].x > monster[i].x - 30 && bull[j].x < monster[i].x + monster[i].width && bull[j].y<monster[i].y + monster[i].length
					&& bull[j].y>monster[i].y)
				{
					NL += 2;
					bull[j].live = false;
					monster[i].hp -= player_attact;
					if (player.hp < PLAYER_HP / 2)
					{
						player.hp++;
					}
					if (monster[i].hp <= 0)
					{
						monster[i].live = false;
						mciSendString("close boom", 0, 0, 0);//爆炸声
						mciSendString("open D:/C++/picture/v/boom.mp3 alias boom", 0, 0, 0);//爆炸声
						mciSendString("play boom ", 0, 0, 0);//爆炸声
						Score += (155+3*i);
					}
				}
			}
			//玩家攻击陨石
			if (Stone_1.live==true && Stone_1.hp > 0)
			{
				if (bull[j].x > Stone_1.x - 30 && bull[j].x < Stone_1.x + Stone_1.width - 30 && bull[j].y<Stone_1.y + Stone_1.length - 70
					&& bull[j].y>Stone_1.y)
				{
					bull[j].live = false;
					Stone_1.hp -= player_attact;
					if (player.hp < PLAYER_HP / 2)
					{
						player.hp++;
					}
					if (Stone_1.hp <= 0)
					{
						Stone_1.live = false;
						mciSendString("close boom", 0, 0, 0);//爆炸声
						mciSendString("open D:/C++/picture/v/boom.mp3 alias boom", 0, 0, 0);//爆炸声
						mciSendString("play boom ", 0, 0, 0);//爆炸声
						Stone_1.y = -1000;
						Score += 3000;

					}
				}
			}
			//玩家攻击boss
			if (Boss.live==true && Boss.hp > 0)
			{
				if (bull[j].x > Boss.x - 30 && bull[j].x < Boss.x + Boss.width - 30 && bull[j].y<Boss.y + Boss.length - 70
					&& bull[j].y>Boss.y)
				{
					bull[j].live = false;
					Boss.hp -= player_attact;
					if (player.hp < PLAYER_HP / 2)
					{
						player.hp++;
					}
					if (Boss.hp <= 0)
					{
						Boss.live = false;
						mciSendString("close boom", 0, 0, 0);//爆炸声
						mciSendString("open D:/C++/picture/v/boom.mp3 alias boom", 0, 0, 0);//爆炸声
						mciSendString("play boom ", 0, 0, 0);//爆炸声
						Score += 10000;
					}
				}
			}
		}
	}
}
void Monster_small_bull_move()
{
	for (int j = 0; j < ENEMY_NUM; j++)
	{
		for (int i = 0; i < MONSTER_BULL_SAMLL; i++)
		{
			if (Monster_bull[j][i].live)
			{
				Monster_bull[j][i].y += 1;
				if (Monster_bull[j][i].y > 935)
				{
					Monster_bull[j][i].live = false;
				}
				//玩家被第一种子弹攻击
				if (Monster_bull[j][i].x+ Monster_bull[j][i].width-player.x-40>0&& Monster_bull[j][i].x-player.x<56
					&& Monster_bull[j][i].y+ Monster_bull[j][i].length-player.y-25>0&& Monster_bull[j][i].y + Monster_bull[j][i].length-player.y<56)
				{
					Monster_bull[j][i].live = false;
					if (player.hp > 0)
					{
						player.hp = player.hp - 8;
					}
					
				}
			}
		}
	}
}
void Monster_attact_small()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		for (int j = 0; j < MONSTER_BULL_SAMLL; j++)
		{
			if (monster[i].live)
			{
				if ((monster[i].y) == 200+10*i || monster[i].y == 500-8*i || monster[i].y==100+30*i)
				{
					if (!Monster_bull[i][j].live)
					{
						Monster_bull[i][j].live = true;
						Monster_bull[i][j].x = monster[i].x + 24;
						Monster_bull[i][j].y = monster[i].y + 60;
						break;
					}
				}
			}
		}
	}
}
void Stone()
{
	
	if (Stone_1.live==true&&Stone_1.hp>0)
	{
		if (Timer(13, 100))
		{
			Stone_1.y += 1;/////////////////////////////////////////////////////////////////
		}
		if (Stone_1.y > 935)
		{
			Stone_1.live = false;
		}
	}
}
void Boss_move()
{
	if (Boss.live == true)
	{
		if (Timer(17, 40) && Boss.y != 0)
		{
			Boss.y++;
		}
	}
}
void Boss_1()
{
	if (GuanQia == 3)
	{
		if (Score > 10)
		{
			Stone_1.live = true;
		}
		if (Stone_1.y == 20)
		{
			Boss.live = true;
		}
		
		Boss_move();
	}
}
void Boss_bull_creat()
{
	if (Boss.live == true)
	{
		for (int i = 0; i < BOSS_BULL_NUM; i++)
		{
			if (Boss_bull[i].live==false)
			{
				Boss_bull[i].live = true;
				Boss_bull[i].x = rand() % 450;
				Boss_bull[i].y = -40;
				break;
			}
		}
	}
}
void Boss_attact_b_move()
{
	if (Boss.live)
	{
		if (Boss_attact_b.live == false)
		{
			Boss_attact_b.live = true;
		}
		if (Boss_attact_b.live == true)
		{
			if (Timer(85, 1))
			{
				Boss_attact_b.y++;
			}
			
			if (Boss_attact_b.x + 120 > player.x && Boss_attact_b.x<player.x + player.width
				&& Boss_attact_b.y + Boss_attact_b.length>player.y+40 && Boss_attact_b.y < player.y + player.length)
			{
				Boss_attact_b.live = false;
				player.hp -= 70;
				Boss_attact_b.x = player.x - 25;
				Boss_attact_b.y = -300;
			}
			if (Boss_attact_b.y > 1200)
			{
				Boss_attact_b.live = false;
				Boss_attact_b.x = player.x - 25;
				Boss_attact_b.y = -300;
			}
		}
		
	}
}

void Boss_bull_move()
{
	for (int i = 0; i < BOSS_BULL_NUM; i++)
	{
		if (Boss_bull[i].live==true)
		{
			if (Timer(i+40, 10))
			{
				Boss_bull[i].y++;
				
			}
		}
		if (Boss_bull[i].live)
		{
			if (Boss_bull[i].y > 935)
			{
				Boss_bull[i].live = false;
			}
			if (Boss_bull[i].x > player.x - 30 && Boss_bull[i].x<player.x + player.width &&
				Boss_bull[i].y>player.y - 30 && Boss_bull[i].y < player.y + player.length)
			{
				Boss_bull[i].live = false;
				if (player.hp > 0)
				{
					player.hp = player.hp - 30;
				}
			}
		}
	}
}

int main()
{
	//创建窗口
Repeat_begin:
	system("cls");
	initgraph(WID, LEN);//如果要打印，是不能输出printf里面的东西的，要加上SHOWCONSOLE
	
	
	setbkmode(TRANSPARENT);//字的背景透明
	setlinecolor(WHITE);
	
	settextstyle(25, 0, "楷体");
	loadimage(&begin[0], "D:\\C++\\picture\\begin_0.jpg");//开始菜单，背景500,935
	loadimage(&begin[1], "D:\\C++\\picture\\begin_1.jpg");//开始游戏
	loadimage(&begin[2], "D:\\C++\\picture\\begin_2.jpg");//帮助
	loadimage(&begin[3], "D:\\C++\\picture\\begin_3.jpg");//退出
	loadimage(&instruction, "D:\\C++\\picture\\instruction.jpg");//说明图片
	loadimage(&stone[0][0], "D:\\C++\\picture\\stone12.jpg");//陨石
	loadimage(&stone[0][1], "D:\\C++\\picture\\stone11.jpg");
	loadimage(&bk_shibai, "D:\\C++\\picture\\bk_shibai.jpg");//失败界面
	loadimage(&bk_shibai, "D:\\C++\\picture\\bk_cg.jpg");//成功界面
	//测试boss子弹
	loadimage(&monster_attact_small[0][0], "D:\\C++\\picture\\monster_attact_small2.jpg");
	loadimage(&monster_attact_small[0][1], "D:\\C++\\picture\\monster_attact_small1.jpg");
	//第二种子弹
	loadimage(&zidan_b[0], "D:\\C++\\picture\\zidan_b1.jpg");
	loadimage(&zidan_b[1], "D:\\C++\\picture\\zidan_b2.jpg");
	//加载声音文件
	mciSendString("open D:/C++/picture/v/boom.mp3 alias boom", 0, 0, 0);//爆炸声
	mciSendString("open D:/C++/picture/v/game_begin.mp3 alias game_begin", 0, 0, 0);//开始界面
	mciSendString("open D:/C++/picture/v/battle.mp3 alias battle", 0, 0, 0);//普通战斗
	mciSendString("open D:/C++/picture/v/boss.mp3 alias boss", 0, 0, 0);//boss
	mciSendString("open D:/C++/picture/v/select.mp3 alias select", 0, 0, 0);//触发的音效
	mciSendString("open D:/C++/picture/v/ED.mp3 alias ED", 0, 0, 0);//ed
	


	mciSendString("play game_begin repeat", 0, 0, 0);
	
	
	putimage(0, 0, &begin[0]);
	/*putimage(0, 0, &zidan_b[1], NOTSRCERASE);
	putimage(0, 0, &zidan_b[0], SRCINVERT);*/
	/*putimage(50, 50, &monster_attact_small[0][0], NOTSRCERASE);
	putimage(50, 50, &monster_attact_small[0][1], SRCINVERT);*/
	//system("pause");

	loadimage(&boss[0], "D:\\C++\\picture\\boss1.jpg");
	loadimage(&boss[1], "D:\\C++\\picture\\boss2.jpg");
	

	int While_end1 = 0;
	while (While_end1!=5)
	{
		mouse = GetMouseMsg();
		switch (mouse.uMsg)
		{
		case WM_MOUSEMOVE://鼠标移动到
			if (mouse.x > 150 && mouse.x < 350 && mouse.y>300 && mouse.y < 350)
			{
				putimage(0, 0, &begin[1]);//开始游戏
				
			}
			else if (mouse.x > 150 && mouse.x < 350 && mouse.y>400 && mouse.y < 450)
			{
				putimage(0, 0, &begin[2]);//帮助
			}
			else if (mouse.x > 150 && mouse.x < 350 && mouse.y>500 && mouse.y < 550)
			{
				putimage(0, 0, &begin[3]);//退出
			}
			else
			{
				putimage(0, 0, &begin[0]);
			}
			break;
		case WM_LBUTTONDOWN://按下鼠标
			if (mouse.x > 150 && mouse.x < 350 && mouse.y>300 && mouse.y < 350)//点击开始游戏
			{
				system("cls");
				While_end1 = 5;
				mciSendString("close game_begin", 0, 0, 0);
				
			}
			else if (mouse.x > 150 && mouse.x < 350 && mouse.y>400 && mouse.y < 450)//点击帮助
			{
				system("cls");
				putimage(0, 0, &instruction);//帮助
				system("pause");
			}
			else if (mouse.x > 150 && mouse.x < 350 && mouse.y>500 && mouse.y < 550)//点击退出游戏
			{
				system("cls");
				initgraph(300, 200);//退出
				outtextxy(100, 50, "是否退出游戏？");
				outtextxy(80, 150, "是");
				rectangle(70, 140, 105, 175);
				outtextxy(200, 150, "否");
				rectangle(190, 140, 225, 175);
				int EndAnswer = 0;
				while (EndAnswer!=1)
				{
					mouse = GetMouseMsg();
					switch (mouse.uMsg)
					{
					case WM_LBUTTONDOWN:
						if (mouse.x > 70 && mouse.x < 105 && mouse.y>140 && mouse.y < 175)//是
						{
							return 0;
						}
						else if (mouse.x > 190 && mouse.x < 225 && mouse.y>140 && mouse.y < 175)//否
						{
							EndAnswer = 1;
						}
						break;
					default:
						break;
					}
				}
				goto Repeat_begin;//退出游戏  点击否之后重新运行游戏
			}
			break;
		default:
			break;
		}
	}

	
Repeat_game:
	NL = 0;
	Score = 0;
	player.hp = PLAYER_HP;
	int out_of = 0;
	
	GameInit();//初始化游戏数据
	//双缓冲绘图
	mciSendString("open D:/C++/picture/v/battle.mp3 alias battle", 0, 0, 0);//普通战斗
	mciSendString("play battle repeat", 0, 0, 0);
	BeginBatchDraw();

	
	while (out_of ==0)
	{
		//GuanQia = 3;//调试用的
		//判断关卡，来设置怪物
		if (GuanQia == 2&&player.hp>0)
		{
			Stone_1.live = true;
		}
		//if(GuanQia==1)
		GameDraw();
		setfillcolor(GREEN);
		/*if (_kbhit())
		{
			char zanting = _getch();
			switch(zanting)
			{
			case 'T':
			case 't':

				putimage(0, 0, &boss[1], NOTSRCERASE);
				putimage(0, 0, &boss[0], SRCINVERT);
				outtextxy(0, 150, "游   戏   暂   停，  按   T   键   继   续");
				outtextxy(250, 200, "玩家基础攻击力为：1");
				outtextxy(250, 300, "玩家攻击力升级后为：2");
				outtextxy(250, 400, "普通怪物攻击力为：8");
				outtextxy(250, 500, "BOSS的普通弹幕伤害为：30");
				outtextxy(250, 600, "BOSS的特殊攻击伤害为：70");
				outtextxy(250, 700, "玩家总血量为：150");
				outtextxy(250, 800, "按任意键继续");

				system("pause");
				system("cls");
			default:
				break;
			}
		}*/
		outtextxy(0, 150, "分数：");
		outtextxy(0, 180, "生命值：");
		rectangle(100, 190, 250, 200);
		fillrectangle(100, 190, 100+player.hp, 200);

		sprintf(s, "%d", Score);
		outtextxy(100, 150, s);

		
		if (Boss.live)
		{
			if (Boss.hp > 0 && Boss.hp <= 400)
			{
				rectangle(50, 50, 450, 65);
				setfillcolor(RED);
				fillrectangle(50, 50, 50 + Boss.hp, 65);
			}
			if (Boss.hp > 400 && Boss.hp <= 800)
			{
				rectangle(50, 50, 450, 65);
				setfillcolor(RED);
				fillrectangle(50, 50, 450, 65);
				setfillcolor(YELLOW);
				fillrectangle(50, 50, 50 + Boss.hp - 400, 65);
			}
			if (Boss.hp > 800)
			{
				rectangle(50, 50, 450, 65);
				setfillcolor(YELLOW);
				fillrectangle(50, 50, 450, 65);
				setfillcolor(GREEN);
				fillrectangle(50, 50, 50 + Boss.hp - 800, 65);
			}
		}
		

		FlushBatchDraw();

		/*printf("1\n");
		if (Stone_1.live)
		{
			printf("活过来了  \n");
			system("pause");
		}*/

		PlayerMove(2);
		/*printf("2\n");
		if (Stone_1.live)
		{
			printf("活过来了  \n");
			system("pause");
		}*/

		Bull_move();
		/*printf("3\n");
		if (Stone_1.live)
		{
			printf("活过来了  \n");
			system("pause");
		}*/


		//boss专场的函数集////////////////////////////////////////////////////////////////////
		Boss_1();
		if (Timer(35, 1500))
		{
			Boss_bull_creat();
		}
		
		Boss_bull_move();
		Boss_attact_b_move();
		/*if (Boss_attact_b.live)
		{
			printf("1\n");
		}*/



		Stone();
		/*printf("4\n");
		if (Stone_1.live)
		{
			printf("活过来了  \n");
			system("pause");
		}*/

		Monster_attact_small();
		/*printf("5\n");
		if (Stone_1.live)
		{
			printf("活过来了  \n");
			system("pause");
		}*/

		Monster_small_bull_move();
		/*printf("6\n");
		if (Stone_1.live)
		{
			printf("活过来了  \n");
			system("pause");
		}*/

		static DWORD t1, t2;
		if (Timer(10, 1500))
		{
			Create_monster();
		}
		/*printf("7\n");
		if (Stone_1.live)
		{
			printf("活过来了  \n");
			system("pause");
		}*/

		MonsterMove();
		/*printf("8\n");
		if (Stone_1.live)
		{
			printf("活过来了  \n");
			system("pause");
		}*/
		/*for (int i = 0; i < BOSS_BULL_NUM; i++)
		{
			if (Boss_bull[i].live)
			{
				printf("子弹%d活着\n", i);
			}
			
				
		}*/
		
		PlayGame();
		/*printf("9\n");
		if (Stone_1.live)
		{
			printf("活过来了  \n");
			system("pause");
		}*/
		if (Stone_1.y == 20&&GuanQia==3)
		{
			mciSendString("close battle", 0, 0, 0);
			mciSendString("open D:/C++/picture/v/boss.mp3 alias boss", 0, 0, 0);//boss
			mciSendString("play boss repeat", 0, 0, 0);
		}
		if (player.hp <= 0)//失败
		{
			out_of = 1;
		}
		if (GuanQia == 0 && Score > 1500)//通过第一关,进入第二关
		{
			out_of = 2;
		}
		if ( GuanQia==2 && Score > 5000)//通过第二关，进入最后一关
		{
			out_of = 3;
		}
		if (GuanQia == 3 && Score > 15000)//通关本游戏
		{
			out_of = 4;
		}
	}
	printf("%d", out_of);
	EndBatchDraw();
	printf("%d", out_of);
	system("cls");
	while(out_of==1)//out_of为1的时候是进入失败
	{
		mciSendString("close battle", 0, 0, 0);
		mciSendString("close boss", 0, 0, 0);
		mciSendString("open D:/C++/picture/v/die.mp3 alias die", 0, 0, 0);
		mciSendString("play die", 0, 0, 0);
		putimage(0, 0, &bk_shibai);
		mouse = GetMouseMsg();
		switch (mouse.uMsg)
		{
		case WM_LBUTTONDOWN://鼠标左键按下
			if (mouse.x > 100 && mouse.x < 400 && mouse.y>400 && mouse.y < 450)
			{
				mciSendString("close die", 0, 0, 0);
				goto Repeat_game;
			}
			if (mouse.x > 100 && mouse.x < 400 && mouse.y>600 && mouse.y < 650)
			{
				return 0;
			}
			break;
		default:
			break;
		}
	}
	while (out_of == 2)//out_of为2的时候是进入成功,通过第一关,准备进入第二关
	{

		putimage(0, 0, &bk_cg);
		mouse = GetMouseMsg();
		switch (mouse.uMsg)
		{
		case WM_LBUTTONDOWN://鼠标左键按下
			if (mouse.x > 100 && mouse.x < 400 && mouse.y>400 && mouse.y < 450)//下一关，进入第二关
			{
				GuanQia = 2;
				goto Repeat_game;
			}
			if (mouse.x > 100 && mouse.x < 400 && mouse.y>600 && mouse.y < 650)//退出游戏
			{
				return 0;
			}
			break;
		default:
			break;
		}
	}
	while (out_of == 3)//out_of为3的时候是进入成功,通过第二关,准备进入第三关
	{
		putimage(0, 0, &bk_cg);
		mouse = GetMouseMsg();
		switch (mouse.uMsg)
		{
		case WM_LBUTTONDOWN://鼠标左键按下
			if (mouse.x > 100 && mouse.x < 400 && mouse.y>400 && mouse.y < 450)//下一关，进入第三关
			{
				GuanQia += 1;
				goto Repeat_game;
			}
			if (mouse.x > 100 && mouse.x < 400 && mouse.y>600 && mouse.y < 650)//退出游戏
			{
				return 0;
			}
			break;
		default:
			break;
		}
	}
	while (out_of == 4)//结束
	{
		system("cls");
		mciSendString("close boss", 0, 0, 0);//ed
		mciSendString("open D:/C++/picture/v/ED.mp3 alias ED", 0, 0, 0);//ed
		mciSendString("play ED", 0, 0, 0);//ed
		putimage(0, 0, &feeling);
		system("pause");
		return 0;
	}
	return 0;
}

