#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int jg(int x)
{
	int i ;
	int p ;
	while (x == 2)
	{
		return 1;
	}
	for (p = 2; p < x; p++)
	{
		i = x % p;
		if (p == x - 1 && i != 0)
		{
			return 1;
		}
		if (i == 0)
		{
			return 0;
		}
	}
}
int main()
{
	int a;
	printf("输入一个4~100的偶数:\n");
	scanf("%d", &a);
	while (a < 4)
	{
		printf("输入的数不符合要求");
		return 0;
	}
	while (a >100)
	{
		printf("输入的数不符合要求");
		return 0;
	}
	while (a == 4)
	{
		printf("4=2+2");
		return 0;
	}
	int Jianyan;
	Jianyan = a % 2;
	while (Jianyan != 0)
	{
		printf("输入的数不符合要求");
		return 0;
	}
	int b = 2;
	int k;
	int l;
	for (b; b < a; b++)
	{
		int c = a - b;
		k = jg(b);
		l= jg(c);
		if (b > c)
		{
			return 0;
		}
		while (l== 1 && k == 1)
		{
			printf("%d=%d+%d\n", a, b, c);
			break;
		}
	}
	return 0;
}