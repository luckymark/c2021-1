#include<iostream>
#include<string.h>
#include<cmath>
#include<time.h> 
using namespace std;
int a[1001];
int main()
	{	
		int j;
		double begin,end;
		int isprime(int x);
		begin=clock();
		for(int i=2;i<=1000;++i)
			{
				a[i]=1;
			}
		for(int i=2;i<=1000;++i)
			{	
				if (a[i]==1){	
					if (isprime(i))
						{
							cout<<i<<"  ";
							j=i*2;
							while(j<=1000){																																				
								a[j]=0;
								j=j+i;
							}
						}	
				}
			}
		end=clock();
		cout<<endl;
		cout<<"spent"<<(double)((end-begin)/1000)<<"S"<<endl;
		return 0;
	}
int isprime(int x)
	{	
		int flag=1;
		for(int i=2;i<=(int)(sqrt(x));++i)
			{	
				if(x%i==0)	flag=0;
			}
		return flag;
	}
