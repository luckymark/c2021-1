#include<stdio.h>

int main() {
	int number,ret=0;
	puts("����һ����������");
	scanf_s("%d", &number);
	for (int i = 2; i < number; ++i) {
		if (number % i == 0)ret++;
	}
	if (ret != 0)printf("%d��Ϊ����\n", number);
	else printf("%dΪ����\n", number);
	return 0;
}