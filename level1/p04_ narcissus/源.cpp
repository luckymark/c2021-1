#include<stdio.h>

int main()
{
	int a, o, p, q;
	for (a = 100; a < 1000; a++)
	{
		o = a / 100, p = (a / 10) % 10, q = a % 10;
		if (a == o*o*o+p*p*p+q*q*q) 
		{
			printf("%d\n", a);
		}
	}
	return 0;
}