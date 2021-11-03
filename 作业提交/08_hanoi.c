#include<stdio.h>
void hanoi(int n, char a, char b, char c) {
	if (n == 1) {
		printf("%c->%c\n", a, c);
	}
	else {
		hanoi(n - 1, a, c, b);
		printf("%c->%c\n", a, c);
		hanoi(n - 1, b, a, c);
	}
}
int main() {
	hanoi(3, 'A', 'B', 'C');
	return 0;
}
