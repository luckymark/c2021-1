#include<stdio.h>
/*
在100范围内验证哥德巴赫猜想的正确性
*/
int main()
{
	int i = 0, n = 25;
	int j,t,s;
	int prime[25]{ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
	for (i = 4; i < 101; i++)
	{
		if (i > 2 && i % 2 == 0)
		{
			for (j = 0; j < n - 1; j++)
			{
				for (t = 0; t < n - 1; t++)
				{
					if (prime[j] + prime[t] == i)
					{
						printf("%d=%d+%d\n", i, prime[j], prime[t]);
						goto out;
					}
				}
			}
		}
		if (i > 5 && i % 2 == 1)
		{
			for (j = 0; j < n - 1; j++)
			{
				for (t = 0; t < n - 1; t++)
				{
					for (s = 0; s < n - 1; s++)
					{
						if (prime[j] + prime[t]+prime[s] == i)
						{
							printf("%d=%d+%d+%d\n", i, prime[j], prime[t],prime[s]);
							goto out;
						}
					}
				}
			}
		}
	out:;
	}
	return 0;
}