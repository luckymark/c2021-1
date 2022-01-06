#include<stdio.h>
#include<time.h>
int main()
{
	int begin, end;
	const int f = 999;
	begin=clock();
	int y,x,i;
	x  = 2;
	y = 1;
	while (x<=f)
	{
		i = 2;
		while (i <= (x / 2)) 
		{
			y = x % i;
			if (y == 0) 
			{
				break;
			}
			else
				i++;
		}
			if (y != 0)
				printf("%d ", x);
		x++;
	}
	end = clock();
	printf("运行时间为%dms", end - begin);
    return 0; 
}