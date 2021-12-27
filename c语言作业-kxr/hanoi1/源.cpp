#include<stdio.h>
#include<stdlib.h>
void move(int x, int y)
{
	printf("%c->%c\n", x, y);
}
void hanoi(int n, char a, char b, char c)
{
	if (n == 1)
	{
		move(a, c);
	}
	else
	{
		hanoi(n - 1, a, c, b);
		move(a, c);
		hanoi(n - 1, b, a, c);
	}
}
int main()
{
	int n = 0;
	printf("ÇëÊäÈë½×Êı£º\n");
	scanf_s("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	system("pause");
	return 0;
}
