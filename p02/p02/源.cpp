#include<stdio.h>
int main(void)
{
	int i,n;
	printf("������һ������1������: \n");
	scanf("%d", &n);
	for (int i = 2; i < n; i++);
	{
		if (n%i == 0)
		{
			printf("%d��������", n);
			return;
		}
	}
	printf("%d������"�� n);
	return 0;
}
