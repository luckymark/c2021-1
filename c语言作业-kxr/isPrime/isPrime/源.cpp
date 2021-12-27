#include<stdio.h>

int main() {
	int number,ret=0;
	puts("输入一个正整数：");
	scanf_s("%d", &number);
	for (int i = 2; i < number; ++i) {
		if (number % i == 0)ret++;
	}
	if (ret != 0)printf("%d不为质数\n", number);
	else printf("%d为质数\n", number);
	return 0;
}