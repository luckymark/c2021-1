#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int count = 0;
	char ming[128] = { '\0' };
	char an[128] = { '\0' };
	printf("����1������һ���ַ�������\n ����2������һ���ַ��������㷨����\n����3���˳�ϵͳ\n");
	int input = 0;
	scanf("%d", &input);
	switch (input)
	{
	case 1:
			printf("����Ҫ���ܵ����ģ�\n");
			scanf("%s", &ming);
			count = strlen(ming);
			for (b = 0; b < count; b++)
			{
				an[b] = ming[b] + b + 5;
			}
			an[b] = '\0';
			printf("���ܺ�������ǣ�%s\n", an);
			system("pause");
			return 0;
	case 2:
	{
		printf("������Ҫ���ܵ����ģ�\n");
		scanf("%s", &an);
		count = strlen(an);
		for (a = 0; a < count; a++)
		{
			ming[a] = an[a] - a - 5;
		}
		ming[a] = '\0';
		printf("���ܺ�������ǣ�%s\n", ming);
		system("pause");
		return 0;
	}
	case 3:
	{
		printf("�˳�ϵͳ");
		return 0;
	}
	default:
	{
		printf("�������������Ҫ���˳�ϵͳ");
		return 0;
	}
	}
	return 0;
}