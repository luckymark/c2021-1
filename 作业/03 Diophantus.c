#include <stdio.h>
int main()
{
	int x = 1;
	while (x % 6 != 0 || x % 12 != 0 || x % 7 != 0||x/6+x/7+x/12+5+x/2+4!=x)
	{
		x++;
	}
	printf("丢番图的儿子死去时他%d岁", x - 4);
	return 0;
}
