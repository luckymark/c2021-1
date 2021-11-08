#include<cstdio>
using namespace std;

int tot;
int mark[105],prime[105];

void get()
{
	for(int i=2;i<=100;++i)
	{
		if(!mark[i])
		prime[++tot]=i;
		for(int j=1;j<=tot;++j)
		{
			if(i*prime[j]>100)break;
			mark[i*prime[j]]=1;
		}
	}
}

int main()
{
	get();
	for(int i=4;i<=100;i+=2)
	{
		for(int j=1;j<=tot;++j)
		{
			if(!mark[i-prime[j]])
			{
				printf("%d=%d+%d\n",i,prime[j],i-prime[j]);
				break;
			}
		}
	}
	return 0;
}