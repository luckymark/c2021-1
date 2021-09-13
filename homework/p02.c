#include<stdio.h>
#include<math.h>
int main() {
	int n;
	scanf_s("%d", &n);
	for (int i = 2; i <= sqrt(n); i++) {
		if (!(n % i)) {
			printf("%d不是素数", n);
			return 0;
		}
	}
	printf("%d是素数", n);
	return 0;
}