#include<stdio.h>
#include<math.h>
int main() {
	int n;
	scanf_s("%d", &n);
	for (int i = 2; i <= sqrt(n); i++) {
		if (!(n % i)) {
			printf("%d��������", n);
			return 0;
		}
	}
	printf("%d������", n);
	return 0;
}