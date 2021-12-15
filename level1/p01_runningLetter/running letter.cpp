#include<stdio.h>
#include<windows.h>
int main()
{
    
	for (;;)
	{
		int a = 1, b = 0;
		int width = 120;
		while (a <= width)
		{
			printf("A");
			Sleep(10);
			system("cls");
			a++;
			b = 0;
			while (b < a)
			{
				printf(" ");
				b++;
			}
		}
		while (a > width&&a<=width*2)
		{
			printf("A");
			Sleep(10);
			system("cls");
			a++;
			b = 0;
			while (b < width * 2 - a)
			{
				printf(" ");
				b++;
			}
		}
	}
	return 0;
}
