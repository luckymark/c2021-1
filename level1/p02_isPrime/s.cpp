#include<stdio.h>
int main()
{
	int x, y, i;
	i = 2;
	y = 1;
	scanf_s("%d", &x);
	if (x < 2)
		printf("你的输入不对");
	else if (x == 2)
		printf("素数");
	else
	{
		while (i <= (x / 2)) {
			y = x % i;
			if (y == 0) {
				break;
			}
			else
				i++;
		}
		if (y != 0)
			printf("素数");
		else
			printf("合数");
	};
	return 0;
}