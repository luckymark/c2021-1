#include<bits/stdc++.h>
#include<windows.h>
#define max_ch 100;
using namespace std;
string s;
int k,i=1,j=1;
int main()
{
	cin>>k;
	cin>>s;
	for (i;i<=k;i++)
	{
		cout<<s;		
		Sleep(50);
		system("cls");
		for (int p=1;p<=i;p++) cout<<" ";
	}
	system("cls");
	for (i=k;i>=1;i--)
	{
		for (int p=1;p<=i;p++) cout<<" ";
		cout<<s;
		Sleep(100);
		system("cls");
	}

	return 0;
}
