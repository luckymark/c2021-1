#include<stdio.h>
#include<math.h>

int main(void)
{
	int a, b, i;
	printf("����������:");
	scanf_s("%d", &a);
	if (a <= 0) {
		printf("error");
		return 0;
	}
	else if (a == 1) {
		printf("�Ȳ�������Ҳ���Ǻ���");
		return 0;
	}
	else if (a == 2 || a == 3) {
		printf("����");
		return 0;
	}
	b = sqrt(a);
	for (i = 2; i <= b; i++) {
		if (a % i == 0)
			break;
		if (i == b) {
			printf("����");
			return 0;
		}
	}
	printf("����");
	return 0;
}