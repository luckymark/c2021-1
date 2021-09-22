#include<stdio.h>
void ho(char a,char b,char c,int i)
{
	if (i == 1)
		printf("%d from %c to %c\n",i, a, c);
	else
	{
		ho(a, c, b, i - 1);
		printf("%d from %c to %c\n",i, a, c);
		ho(b, a, c, i - 1);
	}
}
int main()
{
	ho('a', 'b', 'c', 5);//数字代表从上到下的圆盘
	return 0;
}