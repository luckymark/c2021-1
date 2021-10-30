#include<stdio.h>
#include<string.h>
#define MAX 100
int main()
{
	char c[MAX];
	scanf("%s", c);
	int len = strlen(c);
	for (int i = 0; i < len; i++)
	{
		if (c[i] == 126)
		{
			c[i] = 33;
		}
		else
		{
			c[i] += 1;
		}
	}
	printf("%s", c);
	return 0;
}
