#include<stdio.h>
#include<math.h>

int main(void)
{
	int a, b, i;
	printf("输入正整数:");
	scanf_s("%d", &a);
	if (a <= 0) {
		printf("error");
		return 0;
	}
	else if (a == 1) {
		printf("既不是质数也不是和数");
		return 0;
	}
	else if (a == 2 || a == 3) {
		printf("质数");
		return 0;
	}
	b = sqrt(a);
	for (i = 2; i <= b; i++) {
		if (a % i == 0)
			break;
		if (i == b) {
			printf("质数");
			return 0;
		}
	}
	printf("合数");
	return 0;
}