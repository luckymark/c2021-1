#include<iostream>
#include<math.h>
using namespace std;
int main()
{	
	int a;
	cin>>a;
	bool isprime(int x);
	if (isprime(a)) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}
	bool isprime(int x)
		{	bool flag=true;
			for(int i=2;i<=(int)(sqrt(x));++i)
				{ 
					if (x%i==0) flag=false;
				}
			return flag;
		}
