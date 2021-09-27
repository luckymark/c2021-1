#include<stdio.h>
#include<math.h>
#include<time.h>
int isPrime(int a)
{
	int ret = 1;
	for (int i=2; i <= sqrt(a); i++)
	{
		int c = a % i;
		if (c == 0)
		{
			ret = 0;
			break;
		}
	}
	return ret;
}
int main()
{
	time_t t,T;
	time(&t);
	const int maxN = 1000;
	int prime[maxN] ;
	for (int cnt = 2; cnt < maxN; cnt++)
	{
		prime[cnt] = 1;
	}
	for (int i = 2; i < maxN; i++)
	{
		if (isPrime(i))
		{
			for (int d = 2; d * i < maxN; d++)
			{
				prime[d * i] = 0;
			}
		}
	}
	for (int e = 2; e < maxN; e++)
	{
		if (prime[e])
		{
			printf("%d\t", e);
		}
	}
	time(&T);
	printf("%lf", difftime(T,t));
	return 0;
}