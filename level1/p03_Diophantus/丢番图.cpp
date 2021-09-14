#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,e;
	for (int i=1;i<=150;i++)
	{
		a=i/6;b=i/12;c=i/7;d=i/2;
		if ((a+b+c+5+d+4)==i) {cout<<i;break;}
	}
	return 0;
}
