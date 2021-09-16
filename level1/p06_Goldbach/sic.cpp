#include<stdio.h>
int main()
{
	const int cm = 100;
	printf("4由素数2和素数2组成，哥德巴赫猜想成立\n");
	int x, y, z, m, n, i;
	x =6 ;
	while (x <= cm)
	{
		m = x/2;
		n = m;
		y = 0;
		z = 0;
		while (y==0||z==0)
		{
			i = 2;
			while (i < n)
			{
				y = m % i;
				z = n % i;
				if (y ==0||z==0)
				{
					break;
				}
				else
					i++;
			}
			m++;
			n--;
		}
		printf("%d由素数%d和素数%d组成，哥德巴赫猜想成立\n", x, n+1, m-1);
		x = x + 2;
	}
	return 0;
}