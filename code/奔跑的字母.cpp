#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	//system("color 4f");
	int a,b,c;
	cin>>c;
	a=0;
	system("CLS");
	do{
		cout<<"A";
		Sleep(50);
		system("CLS");
		b=1;
		a++;
		while(b<=a){
			cout<<" ";
			b++;
		}
	}
while(a<c);
while(a<=c){
	system("CLS");
	b=1;
	while(b<=a){
		cout<<" ";
		b++;
	}
	cout<<"A";
	Sleep(50);
	a--;
}
system("pause");
return 0;
}
