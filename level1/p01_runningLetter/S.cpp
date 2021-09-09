#include<stdio.h>
#include<windows.h>
int main()
{
	int i = 0;
	while (i < 100) {
		printf("w\b");
		Sleep(100);
		printf(" ");
		i++;
	}printf("w");
	return 0;
}