#include<stdio.h>
int main()
{
	float i;
	for (i = 0; i < 1000; i++)
		if ((i / 12 + i / 6 + i / 7 + 5 + i / 2 + 4) == i) {
			printf("\neag=%.0f", i);
			break;
		}
}