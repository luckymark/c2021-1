#include<stdio.h>
#include<windows.h>
int main() {
	int number, k = 1, ret = 0;
	puts("補秘貧�泯�");
	scanf_s("%d", &number);
	system("cls");
	printf("                 2欺%6d議嵎方嗤��\n", number);
	printf("�亜�！！！！！！！！！！！！！！！！！！！！！！！！��\n");
	printf("��");
	for (int j = 2; j < number; ++j) {
		
		for (int i = 2; i < j; ++i) {
			if (j % i == 0)ret++;
		}
		if (ret == 0) {
			printf("%6d", j);
			if (k % 8 == 0) {
				printf("  ��\n��");
			}
			k++;
		}
		ret = 0;
	}
	printf("\n�検�！！！！！！！！！！！！！！！！！！！！！！！！��\n");
	system("pause");
	return 0;
}