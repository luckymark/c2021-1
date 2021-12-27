#include <stdio.h>
#include <string.h>
int main(int argc, char const*argv[])
{	int count = 0;
	int result = 1;
	int i;
	char Text[128] = {'\0'};       
	char mima[128] = {'\0'}; 
	while (1)
	{
		if (result == 1)
 		{
			printf("加密函数：\n");
			scanf("%s", &Text);
			count = strlen(Text);
			for (i = 0; i < count; i++)
			{
				mima[i] = Text[i] + i + 3;
			}
			mima[i] = '\0'; 
			printf("加密后函数为：%s\n", mima);
		}
		else if (result == 2)
		{
			count = strlen(Text);
			for (i = 0; i < count; i++) 
			{
				Text[i] = mima[i] - i - 3;
			}
			Text[i] = '\0';
			printf("解密后函数为：%s\n", Text);
		}
		else if (result == 3)
		{
			break;
		}
		else
		{
			printf("请输入命令符：\n");
		}
		printf("输入1加密新函数\n输入2对刚加密的函数进行解密\n输入3退出系统：\n");
		printf("请输入命令符：\n");
		scanf("%d", &result);
	}
	return 0;
}
