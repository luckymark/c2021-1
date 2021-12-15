#include<stdio.h>
#include<string.h>
#include<windows.h>
int main()
{
	char text[128] = {'\0'};
	char encryption[128] = {'\0'};
	int order = 0;
	while (1)
	{
		printf("请输入正确的指令：1表示加密输入的文件，2表示解密输入的文件，3表示退出\n");
		scanf_s("%d", &order);
		if (order == 1)
		{
			printf("请输入要加密的文件:");
			scanf("%s",&text);
			int len = strlen(text);
			int i = 0;
			int a = 0;
			for (; i < len; i++)
			{
				encryption[i] = text[i] +a;
				a++;
				if (a == 3)
				{
					a = 0;
				}
			}
			encryption[i] = { '\0' };
			printf("加密后的文件是：%s\n", encryption);
		}
		else if (order == 2)
		{
			char input[128] = { '\0' };
			char dencryption[128];
			printf("请输入要解密的文件：");
			scanf("%s",&input);
			int len = strlen(input);
			int i = 0;
			int a = 0;
			for (; i < len; i++)
			{
				if (a == 3)
				{
					a = 0;
				}
				dencryption[i] = input[i] -a;
				a++;
			}
			dencryption[i] = { '\0' };
			printf("解密后的文件是：%s\n", dencryption);
		}
		else if (order == 3)
		{
			break;
		}
		else
		{
			printf("\nerror\n");
			break;
		}
		system("pause");
	}
	return 0;
}

