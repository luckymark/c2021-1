#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main(){
	char a[101];
	int len;
	gets(a);
	len=strlen(a);
	//���� 
	for(int i=0;i<=len-1;i++)
	{
		a[i]=a[i]+3;
	}
	puts(a); 
	//���� 
	for(int i=0;i<=len-1;i++)
	{
		a[i]=a[i]-3; 
	}
	puts(a);
	return 0;
} 
