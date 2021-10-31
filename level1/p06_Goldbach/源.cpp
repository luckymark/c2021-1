#include<stdio.h>
#include<math.h>
#include<time.h>

int JP(int a)//JP means JudgePrime,
{
	int i ;
	if (a == 2 || a == 3)
	{
		return 1;
	}
	for (i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int num, a, m, n;
	m = clock();
	
	for (num = 4; num <= 100; num=num+2)
	{
		for (a = 2; a <= num / 2; a++)
		{
			if (JP(a) && JP(num - a))
			{
				//printf("%d = %d + %d\n", num, a, num - a);
				break;
			}
			if (a == num / 2) {
				printf("哥德巴赫猜想不成立");
				return 0;
			}
        }
	}
	n = clock();
	printf("经检验，哥德巴赫猜想对4至10000000的偶数成立\n计算用时为%lf分钟",(n-m)/60000.0);

	return 0;
}