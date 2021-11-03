#include<stdio.h>

int first(int a);

int multiply(int a, int b);

int ls(int a);

int main()
{
	int a = 1000;
	printf("3位的水仙花数：\t");
	if(a % 1000 == 0 && a > 0){
		int i = a / 10;
		printf("从%d到%d中有水仙花数：",i,a);
		for(; i < a; i++)
		{
			if(i == ls(i))
			{
				printf("%d  ", i);
			}
		}
}
	return 0;
}
int first(int a)
{
	int i = 10,cnt = 1;
	for(;a - i >= 0;i *= 10);
	return i/10;
}
int multiply(int a, int b)
{
	int c = a;
	for(; b > 1; b--)
	{
		a *= c; 
	}
	return a;
}
int ls(int a)
{
	int i = 1, cnt = 0, ret;
	for(; first(a)/i >1; i *= 10)
	{
		cnt++;
	}
	//int c = cnt;
	int d = cnt + 1;
	int sum = 0;
	int b[cnt];
	for(; cnt >= 0; cnt--)
	{
		b[cnt] = a / i;
		a = a - b[cnt] * i;
		i /= 10;
		b[cnt] = multiply(b[cnt], d);
		sum += b[cnt];
	}
	/*int sum = 0;
	int d = c + 1;
	for(; c >= 0; c--)
	{
		b[c] = multiply(b[c], d);
		sum += b[c];
	}*/
	return sum;
}
