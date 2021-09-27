#include<stdio.h>
/*
打印2-1000以内的所有素数
打印出总的计算时间
尽可能优化算法的效率
*/
int main()
{
	int a[1000];
	int i,j,count=0, prime = 1;
	a[0] = 2;
	for (i = 2; i < 1001; i++)
	{
		for (j = 0; j < count; j++)
		{
			if (i % a[j] == 0)
			{
				prime = 0;
				break;
			}
		}
		if (prime == 1)
		{
			a[count] = i;
			count+=1;
			printf("%d ", i);
		}
		else
		{
			prime = 1;
		}
	}
	return 0;
}