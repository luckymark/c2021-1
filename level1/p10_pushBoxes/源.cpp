#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h> //按键  控制  包含了很多（常用
//墙壁是0 空地为1，玩家为7，箱子为5，终点为3
int k=0;//作为最高维度的表示
int answer;
int step;//步数，用于计算玩家得分
int map[3][8][8] =
{
	0,0,0,0,0,0,0,0,
	0,1,1,1,1,5,7,0,
	0,1,1,5,1,1,1,0,
	0,1,5,5,1,1,1,0,
	0,1,1,1,5,5,1,0,
	0,1,1,1,1,5,5,0,
	0,1,1,1,1,1,3,0,
	0,0,0,0,0,0,0,0,

	0,0,0,0,0,0,0,0,
	0,0,1,1,1,5,7,0,
	0,1,1,0,1,1,1,0,
	0,1,5,5,1,1,1,0,
	0,1,1,1,5,0,1,0,
	0,1,1,1,1,0,0,0,
	0,1,1,1,1,1,3,0,
	0,0,0,0,0,0,0,0,

	0,0,0,0,0,0,0,0,
	0,1,1,1,1,5,7,0,
	0,1,1,5,5,5,1,0,
	0,1,5,5,1,1,5,0,
	0,1,1,1,5,5,5,0,
	0,5,1,1,1,5,5,0,
	0,1,1,1,1,1,3,0,
	0,0,0,0,0,0,0,0
};
void show()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//这里开始区别绘制
			if (map[k][i][j] == 1)
			{
				printf("  ");//空地
			}
			else if(map[k][i][j]==0)
			{
				printf("墙");
			}
			else if (map[k][i][j] == 7)
			{
				printf("人");//玩家

			}
			else if (map[k][i][j] == 3)
			{
				printf("X ");//终点
			}
			else if (map[k][i][j] == 5)
			{
				printf("箱");//箱子
			}
		}
		printf("\n");
	}
}
void playGame()
{
	int i, j;
	for (i = 0; i < 8; i++)//找人
	{
		for (j = 0; j < 8; j++)
		{
			if (map[k][i][j] == 7 || map[k][i][j] == 3)
			{
				break;
			}
		}
		if (map[k][i][j] == 7 || map[k][i][j] == 3)
		{
			break;
		}
	}
	char ch = ' ';//用户输入
	ch = _getch();
	//按键处理
	switch(ch)//墙壁是0 空地为1，玩家为7，箱子为5，终点为3
	{
	case 'A':
	case 'a':
		if (map[k][i][j-1] == 1 )
		{
			step++;
			map[k][i][j] = 1;
			map[k][i][j - 1] = 7;
			system("cls");
			show();
		}
		else if (map[k][i][j-1] == 3)
		{
			step++;
			map[k][i][j] = 1;
			map[k][i][j - 1] = 7;
			show();
			system("cls");
			printf("恭喜你通过了第%d关！\n", (k + 1));
			system("pause");
			if (k == 2)
			{
				printf("恭喜你全部通关！\n");
				answer = 'n';
				break;
			}
			printf("是否进入下一关？(y/n)\n");
			answer= _getch();
			if (answer == 'y')
			{
				k++;
			}
			else
			{
				answer = 'n';
				break;
			}
		}
		else if (map[k][i][j - 1] == 5&& map[k][i][j - 2]==1)
		{
			step++;
			map[k][i][j - 1] = 1;
			map[k][i][j - 2] = 5;
			map[k][i][j] = 1;
			map[k][i][j - 1] = 7;
		}
		break;
	case 'W':
	case 'w':
		if (map[k][i-1][j ] == 1)
		{
			step++;
			map[k][i][j] = 1;
			map[k][i-1][j ] = 7;
			system("cls");
			show();
		}
		else if (map[k][i-1][j] == 3)
		{
			step++;
			map[k][i][j] = 1;
			map[k][i-1][j] = 7;
			show();
			system("cls");
			printf("恭喜你通过了第%d关！\n", (k + 1));
			system("pause");

			if (k == 2)
			{
				printf("恭喜你全部通关！\n");
				answer = 'n';
				break;
			}
			printf("是否进入下一关？(y/n)\n");
			answer = _getch();
			if (answer == 'y')
			{
				k++;
			}
			else
			{
				answer = 'n';
				break;
			}
		}
		else if (map[k][i-1][j ] == 5 && map[k][i-2][j ] == 1)
		{
			step++;
			map[k][i-1][j ] = 1;
			map[k][i-2][j ] = 5;
			map[k][i][j] = 1;
			map[k][i-1][j] = 7;
		}
		break;
	case 'S':
	case 's':
		if (map[k][i + 1][j] == 1)
		{
			step++;
			map[k][i][j] = 1;
			map[k][i + 1][j] = 7;
			system("cls");
			show();
		}
		else if (map[k][i + 1][j] == 3)
		{
			step++;
			map[k][i][j] = 1;
			map[k][i + 1][j] = 7;
			show();
			system("cls");
			printf("恭喜你通过了第%d关！\n", (k + 1));
			system("pause");
			if (k == 2)
			{
				printf("恭喜你全部通关！\n");
				answer = 'n';
				break;
			}
			printf("是否进入下一关？(y/n)\n");
			answer = _getch();
			if (answer == 'y')
			{
				k++;
			}
			else
			{
				answer = 'n';
				break;
			}
		}
		else if (map[k][i+1][j ] == 5 && map[k][i+2][j] == 1)
		{
			step++;
			map[k][i+1][j ] = 1;
			map[k][i+2][j ] = 5;
			map[k][i][j] = 1;
			map[k][i+1][j ] = 7;
		}
		break;
	case 'D':
	case 'd':
		if (map[k][i][j + 1] == 1)
		{
			map[k][i][j] = 1;
			map[k][i][j + 1] = 7;
			system("cls");
			show();
			step++;
		}
		else if (map[k][i][j + 1] == 3)
		{
			step++;
			map[k][i][j] = 1;
			map[k][i][j + 1] = 7;
			show();
			system("cls");
			printf("恭喜你通过了第%d关！\n",(k+1));
			system("pause");
			//通关
			if (k == 2)
			{
				printf("恭喜你全部通关！\n");
				answer = 'n';
				break;
			}
			printf("是否进入下一关？(y/n)\n");
			answer = _getch();
			if (answer == 'y')
			{
				k++;
			}
			else
			{
				answer = 'n';
				break;
			}
		}
		else if (map[k][i][j + 1] == 5 && map[k][i][j + 2] == 1)
		{
			step++;
			map[k][i][j + 1] = 1;
			map[k][i][j + 2] = 5;
			map[k][i][j] = 1;
			map[k][i][j + 1] = 7;
		}
		break;
	default:
		break;
	}
}
int score()
{
	int i;
	i = 10000 - step * step+(k+1)^2*976;
	return i;
}
int main()
{
	int fen;
	printf("——————————————推箱子——————————————\n");
	printf("按1开始游戏，按2打开帮助，按3退出游戏\n");
	int h;//玩家的选择
	h = _getch();
	switch (h)
	{
	case '1':
		break;
	case '2':
		printf("w a s d 控制移动，x是终点，一共有3关，最后会结算分数，祝你玩的愉快！\n");
		break;
	case '3':
		return 0;
		break;
	default:
		return 0;
		break;
	}
	system("pause");
	system("cls");
	while (1)
	{
		show();
		playGame();
		if (answer == 'n')
		{
			fen = score();
			goto exit;
		}
		system("cls");
	}
	
	return 0;

exit:
	printf("你的分数为：%d\n", fen);
	system("pause");
	return 0;
}