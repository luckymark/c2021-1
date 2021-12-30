#include<iostream>
using namespace std;
int main(){
	int a=100;
	while(a<=999){

	int b=a%10;
	int c=a/10%10;
	int d=a/100;
	
	if(b*b*b+c*c*c+d*d*d==a){
		cout<<a<<" ";
	}
	a++;
}
	
	
	
	
	return 0;
	
}
