#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int b = 2;
int main()
{
	int a;
	int c;
	printf("����һ�������ж��ǲ�������");
	scanf("%d", &a);
	while (a <= 1)
		printf("�������%d��������", a);
	while (a == 2)
	{
		goto end;
	}
	for (b; b < a ; b++)
	{
		c = a % b;
		if (c == 0)
		{	
			//goto Show;
			printf("NO");
			break;
		}
		else if (b == a - 1)
		{
			//goto Show2;
			printf("yes");
			break;
		}
	}
end:
	printf("YES");
//Show:
	//printf("NO");
	//return 0;
//Show2:
	//printf("YES");
	return 0;
}