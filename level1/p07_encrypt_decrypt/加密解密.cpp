#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char passwd[1000], encrypted[1000];
	int i, j, k, t, move, tmp;
	while (1) {
		printf("加密选择1，解密选择2，其他数字结束程序");
		scanf("%d", &tmp);
		if (tmp == 1) {
			printf("输入原文:");
			scanf("%s", passwd);
			printf("自定义密匙(1-25):");
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
			printf("加密后的密文");
			printf("%s\n", passwd);
		}
		else if (tmp == 2) {
			printf("输入密文:");
			scanf("%s", passwd);
			printf("密匙为(1-25):");
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
			printf("解密后的原文");
			printf("%s\n", passwd);
		}
		else
			return 0;
	}
}
