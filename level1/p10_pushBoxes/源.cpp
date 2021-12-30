#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h> //����  ����  �����˺ܶࣨ����
//ǽ����0 �յ�Ϊ1�����Ϊ7������Ϊ5���յ�Ϊ3
int k=0;//��Ϊ���ά�ȵı�ʾ
int answer;
int step;//���������ڼ�����ҵ÷�
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
			//���￪ʼ�������
			if (map[k][i][j] == 1)
			{
				printf("  ");//�յ�
			}
			else if(map[k][i][j]==0)
			{
				printf("ǽ");
			}
			else if (map[k][i][j] == 7)
			{
				printf("��");//���

			}
			else if (map[k][i][j] == 3)
			{
				printf("X ");//�յ�
			}
			else if (map[k][i][j] == 5)
			{
				printf("��");//����
			}
		}
		printf("\n");
	}
}
void playGame()
{
	int i, j;
	for (i = 0; i < 8; i++)//����
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
	char ch = ' ';//�û�����
	ch = _getch();
	//��������
	switch(ch)//ǽ����0 �յ�Ϊ1�����Ϊ7������Ϊ5���յ�Ϊ3
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
			printf("��ϲ��ͨ���˵�%d�أ�\n", (k + 1));
			system("pause");
			if (k == 2)
			{
				printf("��ϲ��ȫ��ͨ�أ�\n");
				answer = 'n';
				break;
			}
			printf("�Ƿ������һ�أ�(y/n)\n");
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
			printf("��ϲ��ͨ���˵�%d�أ�\n", (k + 1));
			system("pause");

			if (k == 2)
			{
				printf("��ϲ��ȫ��ͨ�أ�\n");
				answer = 'n';
				break;
			}
			printf("�Ƿ������һ�أ�(y/n)\n");
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
			printf("��ϲ��ͨ���˵�%d�أ�\n", (k + 1));
			system("pause");
			if (k == 2)
			{
				printf("��ϲ��ȫ��ͨ�أ�\n");
				answer = 'n';
				break;
			}
			printf("�Ƿ������һ�أ�(y/n)\n");
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
			printf("��ϲ��ͨ���˵�%d�أ�\n",(k+1));
			system("pause");
			//ͨ��
			if (k == 2)
			{
				printf("��ϲ��ȫ��ͨ�أ�\n");
				answer = 'n';
				break;
			}
			printf("�Ƿ������һ�أ�(y/n)\n");
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
	printf("���������������������������������ӡ���������������������������\n");
	printf("��1��ʼ��Ϸ����2�򿪰�������3�˳���Ϸ\n");
	int h;//��ҵ�ѡ��
	h = _getch();
	switch (h)
	{
	case '1':
		break;
	case '2':
		printf("w a s d �����ƶ���x���յ㣬һ����3�أ�������������ף�������죡\n");
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
	printf("��ķ���Ϊ��%d\n", fen);
	system("pause");
	return 0;
}