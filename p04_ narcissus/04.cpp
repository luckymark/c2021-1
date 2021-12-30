#include<stdio.h>
/*
打印出所有3位水仙花数
水仙花数：n位数的每个数位的n次方之和等于该n位数本身
例如：153=1^3+5^3+3^3
*/
int main()
{
	int a, x,y,z;
	for (a = 100; a < 1000; a++)
	{
		x = a / 100;
		y = (a / 10) % 10;
		z = a % 10;
		if ((x * x * x + y *y* y + z*z*z) == a)
		{
			printf("%d\n", a);
		}
	}
	return 0;
}