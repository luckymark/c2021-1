#include<iostream>
#include<cstdio>
using namespace std;

//这里证明强哥德巴赫猜想
//即任一大于2的偶数可以表示成两个素数的和 

int main()
{
	int a[30],n,bo;
	a[1]=2;a[2]=3;
	n=3;
	
	for(int i=4;i<=100;i++){
		bo=1;
		for(int j=2;j<i;j++){
			if(i%j==0) bo=0;
		}
		if(bo==1) {
			a[n]=i;
			n++;
		}
	}
	int in; cin>>in; 
	for(int b=1;a[b]<=in;b++)
		for(int c=1;c<=b;c++)
			if(in==a[b]+a[c]) {
				cout<<in<<"="<<a[b]<<"+"<<a[c];
				system("pause"); 
				return 0;
			}
 }
