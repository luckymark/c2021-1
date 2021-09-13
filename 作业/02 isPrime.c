#include <stdio.h>
int main()
{
	int n;
	scanf_s("%d", &n);
		int a = 2;
		while (n % a != 0 && a < n)
		{
			a++;
		}
		 if (a == n)
			printf("%d是素数",n);
		else
			printf("%d不是素数",n);
	return 0;
}
