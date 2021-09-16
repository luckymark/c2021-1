#include<stdio.h>
int main()
{
	int x, y,m,n,z;
	x = 100;
	while (x < 1000)
	{
		m = x % 10;//个位
		n = x / 10;
		z = n % 10;//十位
		n = n / 10;//百位
		y = m*m*m + z * z*z + n * n*n;
		if (x == y)
			printf("%d ", x);
		x++;
	}
	return 0;
}