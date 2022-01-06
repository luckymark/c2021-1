#include<iostream>
#include<time.h>
using namespace std;
int main()
{
	cout<<"2 ";
	int k;
	for (int i=3;i<=1000;i++)
	{
		k=0;
		for (int j=2;j<=i/2;j++)
		{
			if (i%j==0)	{k=1;break;}
		}
		if (k==0) cout<<i<<" ";
	}
	cout<<endl;
	cout <<"The run time is:"<<(double)clock() / CLOCKS_PER_SEC << "s";
	return 0;
}
