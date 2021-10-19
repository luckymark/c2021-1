#include<stdio.h>
#include<Windows.h>
int main() {
	int n = 0, m;
	while (1) {
		for (int i = 0; i <= 115; i++) {
			if (!n) {
				m = i;
			}
			else {
				m = 115 - i;
			}
			for (int j = 0; j <= m; j++) {
				printf(" ");
			}
			printf("mmp");
			Sleep(100);
			system("cls");
		}
		n += 1;
		n %= 2;
	}
	return 0;
}