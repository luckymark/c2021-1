#include <stdio.h>
#include <time.h>
int main()
{
	printf("2 ");//先排除2这唯一一个偶素数，仅对奇数处理即可。
	clock_t start, finish;
	double time;
	start = clock();
	for (int a = 3; a >= 3 && a < 2000; a = a + 2)
	{
		int b;
		for (b = 3; b <= a && a % b != 0; b = b + 2)
		{
		}
		if (b == a)
			printf("%d ", a);
	}
	finish = clock();
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\n本次计算所耗时间为 % f秒。",time);
	return 0;
}
