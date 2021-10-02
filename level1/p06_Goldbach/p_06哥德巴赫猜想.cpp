#include<stdio.h>
int main()
{
	int a[25] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 }; 
	int i = 0;
	int j = 0;
	int n = 2;
	int num = 2 * n;
	for (; a[i] <= num && a[j] <= num&&num<=100;)
	{ 
	i = 0;
	for (; a[i] <= num && a[j] <= num;)
	{
		if (num == a[i] + a[j])
		{
			printf("%d=%d+%d\n", num, a[i], a[j]);
			j = -1;
			n++;
		}
		else
		{
			i++;
			if (a[i] >= num)
			{
				i--;
				break;
			}
		}
	}
	num = n * 2;
		j++;
		if (a[j] >= num)
		{
			j--;
		}
	}
	return 0;
}