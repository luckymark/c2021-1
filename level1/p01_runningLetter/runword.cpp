#include<windows.h>
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{	
	char c;
	int n=0,width=20,k=0;
	printf("ÇëÊäÈë×Ö·û %c\n");
	scanf("%c",&c);
	while(1)
	{
		system("cls");
		for(int i=1;i<=n;++i)
			{
				cout<<" ";
			}
		cout<<c;
		++k;
		if(k/width%2==0) 
		++n;
		else
		--n;
		Sleep(100);
	}
	return 0;
} 

