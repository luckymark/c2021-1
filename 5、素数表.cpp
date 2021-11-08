#include<cstdio>
#include<time.h>
#define maxn 1005
using namespace std;

int tot,mark[maxn],prime[maxn];

void get_prime()
{
	for(int i=2;i<=1000;++i)
	{
		if(!mark[i])
		prime[++tot]=i;
		for(int j=1;j<=tot;++j)
		{
			if(i*prime[j]>1000)break;
			mark[i*prime[j]]=1;
		}
	}
}

int main()
{
	int s,t;
	s=clock();
	get_prime();
	for(int i=1;i<=tot;++i)
	printf("%d ",prime[i]);
	t=clock();
	printf("\nÓÃÊ±Îª:%dms",t-s);
	return 0;
}