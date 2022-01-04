#include<stdio.h>

int main(void)
{
	float a;
	for (a = 1.0; 1; a=a+1) {
		if (a / 6 + a / 12 + a / 7 + 5 + a / 2 + 4 == a)
		{
			printf("%d\n", (int)a);
			return 0;
		}
	}
}