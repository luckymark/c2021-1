#include<iostream>
#include<cstdio>
using namespace std;
void hanoi(int,char,char,char);
int main(){
	hanoi(64,'A','B','C');	
	return 0;
}
void hanoi(int n,char ch1,char ch2,char ch3){
	if(n==1) cout<<ch1<<"->"<<ch3<<endl;
	else{hanoi(n-1,ch1,ch3,ch2);
	     cout<<ch1<<"->"<<ch3<<endl;
	     hanoi(n-1,ch2,ch1,ch3);
	 }
}
