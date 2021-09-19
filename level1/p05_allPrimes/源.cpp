
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define CLOCK_THREAD_CPUTIME_ID 0
double t1 = clock();
int main()
{
	printf("2\n");
	for (int i = 3; i <= 1000; i += 2)
	{
		int j = 0;
		for (j = 2; j <= i / 2; j++)
		{
			if (i % j == 0)
				break;
		}
		if (j > i / 2)
		{
			printf("%d\n", i);
		}

	}
	double t2 = clock() - t1;
	printf("计算所需时间为：%lf", t2);
	system("pause");
	return 0;
}