#include<cstdio>
using namespace std;

int prime(int n)
{
	for(int i=2;i*i<=n;++i)
	if(n%i==0)return 0;
	return 1;
}

int main()
{
	int n;
	scanf("%d",&n);
	if(prime(n))
	printf("%d is prime.",n);
	else printf("%d is not prime.",n);
	return 0;
}