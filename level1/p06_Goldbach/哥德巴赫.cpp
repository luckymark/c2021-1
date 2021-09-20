#include<iostream>
#include<cmath>
using namespace std;
int main()
	{	
		int isprime(int x);
		int a[26];
		int n=1,symbol;
		for(int i=2;i<=100;++i)
			{
				if (isprime(i)) a[n++]=i;
			}
		for(int i=4;i<=100;i+=2) 
			{	
				symbol=0;
				for(int j=1,k=1;j<=25,k<=25;)
					{
						if (i==a[j]+a[k])
							{
								symbol=1;
								break;
							}
						else
							{	
								if(k<25)	k++;
								else {k=1;j++;
								}								
							}
						
					}
				
			}
	if(symbol) cout<<"Right"<<endl;
	return 0;
	}
int isprime(int x)
	{	
		int flag=1;
		for(int i=2;i<=(int)sqrt(x);++i)
			{
				if(x%i==0) flag=0;
			}
		return flag;
	 } 
