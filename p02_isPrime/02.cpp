#include<stdio.h>
int main()
{
	int a, i = 2;
	int isprime = 0;
	scanf_s("%d", &a);
	while (i < a && isprime == 0)
	{
		if (a % i == 0)
		{
			isprime = 1;
			printf("%d��������\n", a);
		}
		i++;
	}
	if (isprime == 0)
	{
		printf("%d������\n", a);
	}
	return 0;
}