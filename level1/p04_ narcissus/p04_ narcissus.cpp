#include<stdio.h>
int main()
{
	int a = 100;
		while(a >= 100&&a <= 999)
		{int b = a / 100;
		int	c = a / 10 - b * 10;
		int	d = a % 10;
			if(a == b*b*b+c*c*c+d*c*c)
			{
				printf(" %d", a);
			}
			a++;
		}
	return 0;
}