#include<stdio.h>
void isPrime() {
	printf("请输入一个整数：");
    int a = 0;
	scanf_s("%d", &a);
	if (a <= 1) {
		printf("不是素数");
	}
	else if (a == 2) 
	{
		printf("是素数");
	}
	else if(a>=2)
	{
		for (int b = 2; b < a; b++)
		{
			int c = a % b;
			if (c == 0)
			{
				printf("不是素数");
				break;
			}	
		}
	}
	else
	{
		printf("是素数");
	}
}
int main() {
	isPrime();
	return 0;
}