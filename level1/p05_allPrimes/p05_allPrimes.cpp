#include<stdio.h>
#include<time.h>
int main()
{
	clock_t t1, t2;
	t1 = clock();
	int a = 2;
	printf("2—1000的素数有\n");
	for (; a <= 1000;)
	{
		int i = 0;
		int b = 1;
		while (b <= a)
		{
			if (a % b == 0)
			{
				i++;
			}
			b++;
		}
			if (i==2)
			{
				printf(" %d", a);
			}
		a++;
	}t2 = clock();
	printf("\n用时%d毫秒", t2 - t1);
	return 0;
}