#include<iostream>
#include<cstring>
using namespace std;
int mima=4,n;
char outp[10000]={'\0'};
void jiami(string x)
{
	n=x.length();
	for (int i=0;i<n;i++) outp[i]=x[i]+mima;
	for (int i=0;i<n;i++) cout<<outp[i];
}
void jiemi(string x)
{
	n=x.length();
	for (int i=0;i<n;i++) cout<<char(x[i]-mima);
}
int main()
{
    string inp;
    cin>>inp;
    jiami(inp);
    cout<<endl;
    jiemi(outp);
    return 0;
}
