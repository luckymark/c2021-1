#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int a, b, c, shu;
int main()
{
	int fang;
	for (a=1; a < 10; a++)
	{
		for (b = 0; b < 10; b++)
		{
			for (c = 0; c < 10; c++)
			{
				fang = a ^ 3 + b ^ 3 + c ^ 3;
				if (fang == shu)
				{
					int shu = 100 * a + 10 * b + c;
					printf("%d%d%d \n", a, b, c);
				}
			}
		}
	}
	printf("以上就是所有3位水仙花数");
	return 0;
}