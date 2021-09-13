#include <stdio.h>
int main()
{
	int isPrime(int n);
	int a = 4;
	int c,d,e,f; 
	for (a = 4; a <= 100; a = a + 2)
	{
		for (c =1; c <= a / 2; c++)
		{
			d = a - c;
			e = isPrime(c);
			if (e)
			{
				f = isPrime(d);
				if(f)
				{
					printf("%d=%d+%d\n", a, c, d);
					break;
				}
			}
		}
	}
}

int isPrime(int n)
{
	if (n != 1)
	{
		int b;
		b = 2;
		while (n % b != 0 && b < n)
		{
			b++;
		}
		if (b == n)
			return 1;
		else
			return 0;
	}
	else
		return 1;
}
