#include<iostream>
using namespace std;
int main()
{
	int x,y,sum=0;
	cin>>x;
	if (x==1) cout<<"no";
	else if (x==2) cout<<"yes";
		else 
		{
			for (int i=2;i<=x-1;i++)
			{
				if (x%i==0)
				{
					cout<<"no";sum=1;break;
				}
			}
			if (sum==0) cout<<"yes";
	}
	return 0;
}
