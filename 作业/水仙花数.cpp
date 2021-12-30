#include<iostream>
#include<stdio.h> 
using namespace std;

int main()
{
	system("color 2f"); 
	int a,b,c,d;
	for(int i=100;i<1000;i++)
	{
		a=i%10;
		b=i/10%10;
		c=i/100;
		//cout<<a<<" "<<b<<" "<<c<<endl;
		d=a*a*a+b*b*b+c*c*c;
		if(d==i)cout<<d<<" ";
	}
	system("pause");
	return 0;
}
