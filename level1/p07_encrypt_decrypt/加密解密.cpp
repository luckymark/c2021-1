#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char passwd[1000], encrypted[1000];
	int i, j, k, t, move, tmp;
	while (1) {
		printf("����ѡ��1������ѡ��2���������ֽ�������");
		scanf("%d", &tmp);
		if (tmp == 1) {
			printf("����ԭ��:");
			scanf("%s", passwd);
			printf("�Զ����ܳ�(1-25):");
			scanf("%d", &move);
			for (i = 0; i < strlen(passwd); i++)
			{
				if (passwd[i] >= 'A' && passwd[i] <= 'Z')
				{
					passwd[i] = ((passwd[i] - 'A') + move) % 26 + 'A';
				}
				else if (passwd[i] >= 'a' && passwd[i] <= 'z')
				{
					passwd[i] = ((passwd[i] - 'a') + move) % 26 + 'a';
				}
			}
			printf("���ܺ������");
			printf("%s\n", passwd);
		}
		else if (tmp == 2) {
			printf("��������:");
			scanf("%s", passwd);
			printf("�ܳ�Ϊ(1-25):");
			scanf("%d", &move);
			for (i = 0; i < strlen(passwd); i++)
			{
				if (passwd[i] >= 'A' && passwd[i] <= 'Z')
				{
					passwd[i] = ((passwd[i] - 'A') + 26 - move) % 26 + 'A';
				}
				else if (passwd[i] >= 'a' && passwd[i] <= 'z')
				{
					passwd[i] = ((passwd[i] - 'a') + 26 - move) % 26 + 'a';
				}
			}
			printf("���ܺ��ԭ��");
			printf("%s\n", passwd);
		}
		else
			return 0;
	}
}
