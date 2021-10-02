#include<stdio.h>
int main()
{
	char B[5];
	int i = 0;
	printf("请输入五个字母");
	for (; i <= 4; i++)
	{

		scanf("%c", &B[i]);
	}
	i = 0;
	printf("对该段内容加密");
	for (; i <= 4;i++)
	{
		B[i]--;
		printf(" %c", B[i]);
	}
	printf("\n对该段内容解密");
	i = 0;

	for (; i <= 4; i++)
	{
		B[i]++;
		printf(" %c", B[i]);
	}
	return 0;
}