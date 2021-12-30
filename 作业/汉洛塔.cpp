#include<iostream>
#include<cstdio>
using namespace std;

void move(int n,char A,char B,char C)
{
	if(n==0) return;
	move(n-1,A,C,B);
	cout<<A<<"->"<<C<<endl;
	move(n-1,B,A,C);
}

int main() {
	int n;
	cin>>n;
	move(n,'A','B','C');
	return 0;
}
