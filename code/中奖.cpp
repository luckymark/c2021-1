#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	int n,a;
	cout<<"����1`5���������"<<endl;
	cin>>n; 
	srand(time(0));
	a=rand()%5+1;
	if(n==a)cout<<"�н�";
	else cout<<"�ٽ�����"; 
	
	system("pause");
	return 0;
} 
