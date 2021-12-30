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
	printf("输入1：输入一段字符并加密\n 输入2：输入一段字符并按本算法解密\n输入3：退出系统\n");
	int input = 0;
	scanf("%d", &input);
	switch (input)
	{
	case 1:
			printf("输入要加密的明文：\n");
			scanf("%s", &ming);
			count = strlen(ming);
			for (b = 0; b < count; b++)
			{
				an[b] = ming[b] + b + 5;
			}
			an[b] = '\0';
			printf("加密后的密文是：%s\n", an);
			system("pause");
			return 0;
	case 2:
	{
		printf("输入需要解密的密文：\n");
		scanf("%s", &an);
		count = strlen(an);
		for (a = 0; a < count; a++)
		{
			ming[a] = an[a] - a - 5;
		}
		ming[a] = '\0';
		printf("解密后的明文是：%s\n", ming);
		system("pause");
		return 0;
	}
	case 3:
	{
		printf("退出系统");
		return 0;
	}
	default:
	{
		printf("输入的数不符合要求，退出系统");
		return 0;
	}
	}
	return 0;
}