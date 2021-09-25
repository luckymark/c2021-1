#include<stdio.h>
#include<stdlib.h>
void	haoni(int	n, char	A, char	B, char	C) {
	if (n == 1) {
		printf("%c->%c\n", A, C);
	}
	else {
		haoni(n - 1, A, C, B);
		printf("%c->%c\n", A, C);
		haoni(n - 1, B, A, C);
	}
}
int	main() {
	haoni(64, 'A', 'B', 'C');
	return	0;
}