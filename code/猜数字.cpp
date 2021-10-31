#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */ 
  int main (){
  	srand(time(NULL));
	int a=0;
	cout<<"请输入您猜测的数字"<<endl;
	int b=rand()%100+1;
	int i=0;
	while(i<=4){
		cin>>a;
		if(a>b){ 
		system("CLS");
		cout<<"猜测过大，请重新输入"<<endl; 
		}
		if(a<b){
		system("CLS");
		cout<<"猜测过小，请重新输入"<<endl; 
		}
		if(a==b){
			system("CLS");
		cout<<"恭喜您猜对了"; 
		break;
		}
	i++;
	if(i>4) {
		system("CLS");
	cout<<"次数已用完";} 
	}
	 
	system("pause");
	return 0;
}
