#include<stdio.h>
int main()
{
	int a=0;
	int b = 1;
	int i = 0;
	printf("请输入数字");
	scanf_s("%d", &a);
	while (b <= a)
	{if (a % b == 0) {
			i++;
		}
	b++;
	}
	if (i == 2)
	{
		printf("该数为素数");
	}
	else {
		printf("该数不是素数");
	}
	return 0;
}