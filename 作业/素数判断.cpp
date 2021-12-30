#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n;
	for(int i=2;i<n;i++){
		m=n%i;
		if(m==0){
			printf("·ñ");
			system("pause");
			return 0;
		}
	}
	printf("ÊÇ"); 
	system("pause");
	return 0;
 }
