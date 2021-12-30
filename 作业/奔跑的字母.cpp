#include<iostream>
#include<windows.h>
using namespace std;

int main()
{	
	int a,b,c;
	c=100;
	while(c>0){
	a=0;
	while(a<c)
	{
		system("CLS");
		b=1;
		while(b<=a)
		{
			cout<<" ";
			b=b+1;
		}
		cout<<"A";
		Sleep(10);
		a=a+1;
	}	
	
	while(a<=c)
	{
		if(a==0)break;
		system("CLS");
		b=1;
		while(b<=a)
		{
			cout<<" ";
			b=b+1;
		}
		cout<<"A";
		Sleep(10);
		a=a-1;
	}
}
 }
