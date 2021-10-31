#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	int n,a;
	cout<<"输入1`5的随机数字"<<endl;
	cin>>n; 
	srand(time(0));
	a=rand()%5+1;
	if(n==a)cout<<"中奖";
	else cout<<"再接再厉"; 
	
	system("pause");
	return 0;
} 
