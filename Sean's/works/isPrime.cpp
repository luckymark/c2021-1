#include<cstdio>
#include<stdlib.h>
using namespace std;

void Prime(int num) 
{
	if(num==1)
	{
		puts("It is not a prime!");
		return;
	}
	for (int i = 2; i*i <= num; ++i)
	{
		if (num % i == 0)
		{
			puts("It is not a prime!");
			return;
		}
	}
	puts("It is a prime!");
	return;
}

int main()
{
	int n;
	scanf_s("%d",&n);
	Prime(n);
	return 0;
}//sunxioarui
