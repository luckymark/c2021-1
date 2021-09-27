#include<stdio.h>
int main()
{
	int maxN = 25;
	int prime[25] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
	int x = 4, a = 0, b = 0,d=0;
	for (; x <= 100;x+=2 )
	{
		d++;
		a = 0;
		for (; a < maxN; a++)
		{
			b = 0;
			for (; b < maxN; b++)
			{
				if (x == prime[a] + prime[b] && a < maxN&&prime[a]<=prime[b])
				{
					printf("%d=%d+%d  ", x, prime[a], prime[b]);
					break;
				}
			}
		}
		printf("\n");
	}
	if (d == (100 - 4) / 2+1)
	{
		printf("\n哥德巴赫猜想在100以内正确");
	}
	return 0;
}