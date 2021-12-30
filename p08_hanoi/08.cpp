#include<stdio.h>
#include<string.h>
void move(int x,int y, int k);

int main()
{
	int number;
	scanf_s("%d", &number);
	move(1, 2, number);
	return 0;
}

void move(int x, int y, int i)
{
	char letter[4] = { '0','A','B','C' };
	int z = 6 - x - y;
	if (1 == i)
	{
		printf("%c->%c\n", letter[x], letter[y]);
	}
	else
	{
		move(x, z, i - 1);
		move(x, y, 1);
		move(z, y, i - 1);
	}
}