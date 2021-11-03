#include<stdio.h>
#include<windows.h>

int main()
{
	int a, b, c;
	for(a = 0; a < 119; a++)
	{
		for(b = 0; b < a; b++)
		{
			printf(" ");
		}
		printf("H");
		Sleep(1);
		system("cls");
	}
	for(; a > 0; a--)
	{
		for(c = a - 1 ; c > 0; c-- )
		{
			printf(" ");
		}
		printf("H");
		Sleep(1);
		system("cls");
	}
	return 0;
 } 
