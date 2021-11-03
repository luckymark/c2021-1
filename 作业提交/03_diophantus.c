#include<stdio.h>

int main() {
	int a[900];
	int i = 0;
	for(;i<900;)
	{
		a[i++] = 99 + i;
	}
	i = 0;
	for(;i<900;i++)
	{
		int x,y,z;
		x = a[i] / 100;
		y = a[i] % 100 / 10;
		z = (a[i] %100 - y * 10);
		if(a[i] == x * x * x + y * y * y + z * z * z)
		{
			printf("%d\t",a[i]);
		}
	}
	return 0;

} 
