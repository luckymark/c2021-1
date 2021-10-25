#include	<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	if(n == 1)
	{
		printf("不是素数"); 
	}
	if(n >= 2)
	{ 
		int	i;
		int	isPrime = 0;
		for(i = 2; i <= n-1; i++)
		{
			if(n % i ==0)
			{
				isPrime = 1;
				break;
			}
		}
		if(isPrime)
		{
			printf("不是素数");
		}
		else
		{
			printf("素数");
		}
	}
	return	0;
}
