#include<iostream>
#include<math.h> 
using namespace std;

int main()
{
	int a,b,c,d;
	cout<<"2 3 ";
	
	for(int i=1;i<=166;i++){
		
		int n=0;
		a=i*6-1;
		//b=sqrt(a);
		for(int j=2;j<a;j++)
		{
			if(a%j==0){
				n=1;
				break; 
			}
		}
		if(n==0)cout<<a<<" ";
		
		n=0;
		a=i*6+1;
		//b=sqrt(a);
		for(int j=2;j<a;j++)
		{
			if(a%j==0){
				n=1;
				break;
			}
		}
		if(n==0)cout<<a<<" ";
	}
	system("pause");
	return 0;
}
