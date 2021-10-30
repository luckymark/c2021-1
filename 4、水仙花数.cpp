#include<cstdio>
using namespace std;

void check(int x)
{
	int a[3],tot=0,ret=0,y=x;
	while(y)
	{
		a[tot++]=y%10;
		y/=10;
	}
	for(int i=0;i<3;++i)
	ret+=a[i]*a[i]*a[i];
	if(ret==x)
	printf("%d ",x);
}

int main()
{
	for(int i=100;i<=999;++i)
	check(i);
	return 0;
}