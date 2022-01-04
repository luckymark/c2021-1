#include<stdio.h>
#include<time.h>

int main()
{
	int i, m, n, p, q, a, b;
	a = clock();
	printf("2  3  ");
	for (i = 2; i <= 8192; i++)
	{
		p = i*i+1;
		q = (i + 1) * (i + 1) - 2;//i平方和i平方减1均非素数，3除外
		for (m = p; m <= q; m++)//测试m是否为素数
		{
			for (n = 2; n <= i; n++)
			{
				if (m == 1000)
					goto loop;
				if (m % n == 0)
				{
					break;
				}
				else if (n == i)
				{
					printf("%d  ", m);
				}
				
			}
		}
	}
	loop: b = clock();
	printf("time=%d\n", b - a);
	return 0;
}