
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int a, b = 0, flag = 0,prime[100],z=1;
	for (a = 2; a <= 100; a++) {
		flag = 0;
		for (b = 2; b < a-1; b++) {
			if (a % b == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			prime[z] = a;
			z++;
		}
	}//��������
	int number,i=0;
	printf("����һ��186���ڵ�ż��\n");
	scanf_s("%d", &number);
	for (int e = 1; e <= 100; e++) {
		for (int f = 1; f <= e; f++) {
			if (number == prime[f] + prime[e]) {
				printf("%d=%d+%d\n", number, prime[e], prime[f]);
				i = 1;
				}
			}
		}//�ж�
	if (i == 0)printf("���ǲ���ʶ186���ڵ�ż������զ�Σ�\n");//error����
	system("pause");
	return 0;
}