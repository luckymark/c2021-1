#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */ 
  int main (){
  	srand(time(NULL));
	int a=0;
	cout<<"���������²������"<<endl;
	int b=rand()%100+1;
	int i=0;
	while(i<=4){
		cin>>a;
		if(a>b){ 
		system("CLS");
		cout<<"�²��������������"<<endl; 
		}
		if(a<b){
		system("CLS");
		cout<<"�²��С������������"<<endl; 
		}
		if(a==b){
			system("CLS");
		cout<<"��ϲ���¶���"; 
		break;
		}
	i++;
	if(i>4) {
		system("CLS");
	cout<<"����������";} 
	}
	 
	system("pause");
	return 0;
}
