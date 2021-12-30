#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void dayin(char A, int n, char B) 
{
	printf(" %d ¥”%c≈≤µΩ%c\n", n, A, B);
}
void fang(int n, char A, char B, char C)
{
	if (n == 1)
		dayin(A, 1, C);
	else
	{
		fang(n - 1, A, C, B);
		dayin(A, n, C);
		fang(n - 1, B, A, C);
	}
}
int main()
{
	int a = 64;
	char A = 'A',
		B = 'B',
		C = 'C';
	fang(a, A, B, C);
	return 0;
}
