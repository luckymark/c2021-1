#include<stdio.h>

int cover(int i)
{
	i = 2i - 24;
}

int uncover(int i)
{
	i = (i + 24) / 2;
} 

int main()
{
	int i;
	printf("please enter the lenth of your sentence:___\b\b\b");
	scanf("%d", i);
	char dot[i];
	fgets("%s", dot);
	printf("%s", dot);
}
