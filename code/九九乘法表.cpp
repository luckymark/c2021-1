#include<iostream>
using namespace std;
int mul(int num1,int num2){
	return num1*num2;
}
int main(){
	for(int i=1;i<=9;i++){
	    for(int j=1;j<=i;j++){
	    int a=mul(j,i);
		cout<<j<<"*"<<i<<"="<<a;
		if(a/10==0) cout<<"  "; 
		else cout<<" ";
    }
    	cout<<endl;
    }
	return 0;
} 
