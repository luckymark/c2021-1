#include<stdio.h>
#include<stdlib.h>
#define WIDTH 100
int main()
{
	int i,j;
	char a;
	a = getchar();
	for (j = 1; j < WIDTH; j++)
	{
		for (i = 1; i < j; i++)
		{
			printf("%c", 32);
		}
		printf("%c", a);
		system("cls");
	}
	for (j = WIDTH; j >0; j--)
	{
		for (i = j; i > 0; i--)
		{
			printf("%c", 32);
		}
		printf("%c", a);
		system("cls");
	}
	return 0;
}