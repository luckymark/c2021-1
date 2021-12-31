#include<stdio.h>
int main()
{
	int i, j, k = 0;
	for (i = 2; i < 1000; i++)
	{
		for (j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
				break;
		}
		if (j * j > i)
		{
			printf("%d ", i);
			k++;
			if (k % 10 == 0)
			{
				printf("\n");
			}
		}
	}
}