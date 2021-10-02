#include<stdio.h>
int main()
{
	for (int a = 1; a <= 150; a++)
	{
		if (a % 12 == 0 && a % 7 == 0)
		{
			printf("%d", a-4);
		}
	}
	return 0;
}