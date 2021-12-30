#include<stdio.h>
#include<string.h>
#define MAX 100
int main()
{
	char c[MAX];
	gets(c);
	int len = strlen(c);
	for (int i = 0; i < len; i++)
	{
		if (c[i] == 32)
		{
			c[i] = 126;
		}
		else
		{
			c[i] -= 1;
		}
	}
	printf("%s", c);
	return 0;
}
