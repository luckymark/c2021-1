#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	float a;//��������
	float b;//��������
	float c;//��������ʱ����������

	for (a = 10; a < 120; a++)
	{
		b = a / 2;
		c = a - 4;
		while (b == a - 4 - 5 - a / 7 - a / 6 - a / 12)
		{
			printf("��������ʱ�򶪷�ͼ��%f����\n", c);
			return 0;
		}
	}
	return 0;
}