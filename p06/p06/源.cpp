#include <stdio.h>
#include <math.h>
int ss(int n) 
{
	int i;
	for (i = 2; i <= (int)sqrt(n); i++)
		if (n % i == 0) return 0;
	return 1;
}
int main(void)
{
	int i, j, iLine = 0;
	for (i = 2; i <= 100; i += 2)
		for (j = 3; j < i; j++) {
			if (ss(j) && ss(i - j)) {
				printf("%d=%d+%d ", i, j, i - j);
				iLine++;
				if (iLine % 5 == 0) putchar('\n');
				break;
			}
		}
	return 0;
}