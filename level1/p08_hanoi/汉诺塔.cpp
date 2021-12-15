#include<stdio.h>
void move(int n, char a, char b, char c)
{
	if (n == 1)
	{
		printf("%c-->%c\n", a, b);
	}
	else
	{
		move(n - 1, a,c,b);
		printf("%c-->%c\n", a, b);
		move(n - 1, c, b, a);
	}
}
int main()
{
	int n;
	printf("请输入盘子数：");
	scanf_s("%d", &n);
	printf("现在有A、B、C三个柱子，%d个盘子，盘子都在A柱子上\n", n);
	printf("把盘子从A移动到B的移动操作如下：\n");
	char a = 'A', b = 'B', c = 'C';
	move(n, a, b, c);
}