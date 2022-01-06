#include<stdio.h>

int main()
{
	int x = 1;
	float y = (1 / 6 + 1 / 12 + 1 / 7 + 1 / 2)*x + 4 + 5;
	while (y!=x) {
		x++;
		y = (1 / 6.0 + 1 / 12.0 + 1 / 7.0 + 1 / 2.0)*x + 4 + 5;
	}
	printf("%d", x=x-4);
	return 0;
}