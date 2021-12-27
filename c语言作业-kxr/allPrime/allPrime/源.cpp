#include<stdio.h>
#include<windows.h>
int main() {
	int number, k = 1, ret = 0;
	puts("ÊäÈëÉÏÏÞ£º");
	scanf_s("%d", &number);
	system("cls");
	printf("                 2µ½%6dµÄÖÊÊýÓÐ£º\n", number);
	printf("©°¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª©´\n");
	printf("©¦");
	for (int j = 2; j < number; ++j) {
		
		for (int i = 2; i < j; ++i) {
			if (j % i == 0)ret++;
		}
		if (ret == 0) {
			printf("%6d", j);
			if (k % 8 == 0) {
				printf("  ©¦\n©¦");
			}
			k++;
		}
		ret = 0;
	}
	printf("\n©¸¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª©¼\n");
	system("pause");
	return 0;
}