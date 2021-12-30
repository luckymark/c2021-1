#include<iostream>
using namespace std;
int main(){
	for(int i=2;i<1001;i++){
		for(int j=2;j<=i;j++){
			if(i%j==0&&i!=j) break;
			if(i==j) cout<<i<<" ";
		}
	}
	return 0;
} 
