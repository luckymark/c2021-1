#include<iostream>
#include<conio.h> 

using namespace std;

   char a[10][50]={"****************************************",
	               "*              ������ϵͳ              *",
				   "*                                      *",                                   
				   "*  1����ʾ����б�                     *",
				   "*  2�����                             *",                                   
				   "*  3������                             *", 
				   "*  4���˳�ϵͳ                         *",                                  
				   "*                                      *", 
				   "****************************************",}; 
				   
   char x[3][8]={ "1��ƻ��",
				  "2���㽶",    
         		  "3������", };  
				   
int main(){
	  int t,e,f,g,h; int b=5,c=2,d=8; 
	  char p;
	  do{
	  system("cls");
      for(int i=0;i<10;i++)  puts(a[i]);                  
	  cout<<"����������Ҫѡ��Ĺ��ܵ���ţ�"; cin>>t;
	  switch(t){
	  	case 1:  system("cls");
		         cout<<"ƻ��ʣ�ࣺ"<<b<<"��"<<endl; 
		         cout<<"�㽶ʣ�ࣺ"<<c<<"��"<<endl; 
				 cout<<"����ʣ�ࣺ"<<d<<"��"<<endl<<endl; 
				 cout<<"���ز˵��밴'R'"; 
				 break; 
	  	
	  	case 2:  system("cls");
	 	         for(int i=0;i<4;i++) puts(x[i]);
	 	         cout<<"��ѡ��Ҫ������Ʒ����: "; cin>>e;
	 	         cout<<"������Ҫ������Ʒ����: "; cin>>f; 
	  	         switch(e){
	  	         	case 1:cout<<endl<<"�����ƻ��"<<f<<"��"<<endl<<endl; b=b+f; 
					   	   cout<<"���ز˵��밴'R'"; break;
	  	         	case 2:cout<<endl<<"������㽶"<<f<<"��"<<endl<<endl; c=c+f;
					   	   cout<<"���ز˵��밴'R'"; break;	  	         	
	  	         	case 3:cout<<endl<<"���������"<<f<<"��"<<endl<<endl; d=d+f;
					   	   cout<<"���ز˵��밴'R'"; break;	  	         	
				   }
                 
		         break;
	  	
	  	case 3:  system("cls");
	 	         for(int i=0;i<4;i++) puts(x[i]);
	 	         do {
				    cout<<"��ѡ��Ҫ�������Ʒ����: "; cin>>g;
	 	            cout<<"������Ҫ�������Ʒ����: "; cin>>h;
					if((g==1&&h>b)||(g==2&&h>c)||(g==2&&h>d)) cout<<endl<<"��Ʒ��治�㣡�������������������"<<endl<<endl;}
				 while((g==1&&h>b)||(g==2&&h>c)||(g==2&&h>d));
	  	         switch(g){
	  	         	case 1:cout<<endl<<"�ֳ���ƻ��"<<h<<"��"<<endl<<endl; b=b-h; 
					       cout<<"���ز˵��밴'R'"; break;
	  	         	case 2:cout<<endl<<"�ֳ����㽶"<<h<<"��"<<endl<<endl; c=c-h;
	  	         		   cout<<"���ز˵��밴'R'"; break;
	  	         	case 3:cout<<endl<<"�ֳ�������"<<h<<"��"<<endl<<endl; d=d-h;
	  	         	       cout<<"���ز˵��밴'R'"; break;
				   }
                 
		         break;
	  	
	  	case 4:  exit(0); break;
	  	
	    } char ch=getch(); p=ch;
	  }  while(p=='r');
	  
	return 0;
	
}
