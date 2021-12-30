#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include <windows.h>
int main()
{
	printf("A");
	int i = 1;
	while (i < 100)
	{
		printf("A");
		i++;
		system("cls");
	    int p = 0;
		while (p < i)
		{
			printf(" ");
			p++;
		}
		printf("A");
		if (i ==100)
		{
			while (i > 0)
			{
				int k = 0;
				while (k < i)
				{
					printf(" ");
					k++;
				}
				printf("A");
				i--;
				system("cls");
			}
		}
	}
	return 0;
}