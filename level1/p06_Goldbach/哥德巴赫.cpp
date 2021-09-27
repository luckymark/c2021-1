#include<stdio.h>
int main()
{
	const int maxN = 25;
	int prime[maxN] = { 2,3,5,7,11,13,17,19.23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
	int x = 6, a = 0, b = 0;
	while (x <= 100)
	{
		while (x != prime[a] + prime[b] && a < maxN)
		{
			a++;
			while (x != prime[a] + prime[b] && a < maxN)
			{
				b++;
			}
		}
		printf("%d=%d+%d\t", x, prime[a], prime[b]);
		a = 0, b = 0;
		x++;
	}
}
	/*for (; x <= 100; x++)
	{
		for (;x != prime[a++] + prime[b]&&a<maxN ; a++)
		{
			for (; x != prime[a] + prime[b]&&b<maxN; b++)
			{

			}
			
		}
		printf("%d=%d+%d\t", x, prime[a], prime[b]);
		a = 0, b = 0;
	}
}*/