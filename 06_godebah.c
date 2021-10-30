#include<stdio.h>
#include<math.h>
int isPrime(int a)
{
	int ret = -1;
	int i, cnt;
	cnt = 0;
	for(i = 1; i <= sqrt(a); i += 2 )
	{

		if(a % i == 0)
		{
			cnt++;
		}
		if(cnt == 2)
		{
			ret = 0;
			break;
		}
	}
	return ret;
}

int main(void)
{
	int a, i, j, cnt;
	cnt = 1;//显然对于4哥德巴赫猜想成立 
	for(a = 6; a <= 100; a += 2)
	{
		for(i = 3; i <= a - 2; i += 2)
		{
			j = a - i;
			if(isPrime(i) == -1 && isPrime(j) == -1)
			{
				printf("%d = %d + %d\t", a, i, j);
				cnt++;
				break; 
			}
		}
		}
	if(cnt == 49)
	{
		printf("由上式知哥德巴赫猜想在100以内成立"); 
	}
}
