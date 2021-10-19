#include<stdio.h>
int main() {
	int m, n, sum;
	for (int i = 100; i < 1000; i++) {
		m = i;
		sum = 0;
		for (int j = 0; j < 3; j++) {
			n = m % 10;
			sum += n * n * n;
			m /= 10;
		}
		if (sum == i) {
			printf("%d\n", i);
		}
	}
	return 0;
}