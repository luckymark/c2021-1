#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	float a;//男主年龄
	float b;//儿子年龄
	float c;//儿子死的时候男主年龄

	for (a = 10; a < 120; a++)
	{
		b = a / 2;
		c = a - 4;
		while (b == a - 4 - 5 - a / 7 - a / 6 - a / 12)
		{
			printf("儿子死的时候丢番图有%f岁了\n", c);
			return 0;
		}
	}
	return 0;
}