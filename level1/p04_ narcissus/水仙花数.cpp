#include<iostream>
#include<math.h>
using namespace std;
int main()
	{
		int r=100;
		int a,b,c;
		for(;r<=999;++r) 
			{
				a=r/100;
				b=r%10;
				c=(r/10)%10;
				if (r==pow(a,3)+pow(b,3)+pow(c,3)) 
					cout<<r<<endl;
			}
		return 0;
	}
