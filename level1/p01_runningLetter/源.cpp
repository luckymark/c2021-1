#include<stdio.h>
#include<windows.h>
int main()
{
	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			putchar('\t');
		}
		putchar('a');
		
		system("CLS");
	}
	for (int i = 20; i>=0; i -- )
	{
		for (int j = 0; j <= i; j++)
		{
			putchar('\t');
		}
		putchar('a');

		system("CLS");
	}
	return 0;
}