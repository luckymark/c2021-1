#include<stdio.h>
#include<math.h>
int main()
{
	for (int i = 100; i <= 999; i++)
	{
		int ge = i % 10;
		int shi = i / 10 % 10;
		int bai = i / 100;
		if (i == pow(ge, 3) + pow(shi, 3) + pow(bai, 3))
		{
			printf("%d\t", i);
		}
	}
	return 0;
}