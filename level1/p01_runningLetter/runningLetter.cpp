#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	int a = 1;
	int b;
	while (a <= 100)
	{
		b = 0;
		system("cls");
		while (b <= a)
		{
			printf(" ");
			b++;
		}
		printf("A");
		a++;
	}
	while (a <= 101)
	{
		b = 0;
		system("cls");
		while (b <= a)
		{
			printf(" ");
			b++;
		}
		printf("A");
		a--;
	}
	return 0;
}