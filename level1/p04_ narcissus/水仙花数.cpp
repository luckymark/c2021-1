#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int g,s,b,sum,i;
	for(i=100;i<=999;i++)
	{
		g=i%10;
		s=i/10%10;
		b=i/100;
		sum=g*g*g+s*s*s+b*b*b;
		if (i==sum) cout<<i<<" ";	
	}
	return 0;
}
