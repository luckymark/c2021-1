#include<stdio.h>
int main(void)
{
	int i,n;
	printf("请输入一个大于1的整数: \n");
	scanf("%d", &n);
	for (int i = 2; i < n; i++);
	{
		if (n%i == 0)
		{
			printf("%d不是素数", n);
			return;
		}
	}
	printf("%d是素数"， n);
	return 0;
}
