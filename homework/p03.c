#include<stdio.h>
int main() {
	for (int i = 1; ; i++) {
		if (i % 12 == 0 && i % 7 == 0 && (i - i / 4 - i / 7 - 9) * 2 == i) {
			printf("%d", i - 4);
			return 0;
		}
	}
	return 0;
}