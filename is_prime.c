#include <stdio.h>
int main()
{
	int n;
	printf("请输入一个整数：\n");
	scanf("%d", &n);
	int m = 0;
	for (int i = 2; i < n; i++ ) {
		if(n % i  == 0) {
			m++;
		}
	}
	if (m == 0) {
		printf("%d是素数\n", n);
	} else {
		printf("%d不是素数\n", n);
	}
	return 0;
}
