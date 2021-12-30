#include<iostream>
#include<conio.h> 

using namespace std;

   char a[10][50]={"****************************************",
	               "*              进销存系统              *",
				   "*                                      *",                                   
				   "*  1、显示存货列表                     *",
				   "*  2、入库                             *",                                   
				   "*  3、出库                             *", 
				   "*  4、退出系统                         *",                                  
				   "*                                      *", 
				   "****************************************",}; 
				   
   char x[3][8]={ "1、苹果",
				  "2、香蕉",    
         		  "3、西瓜", };  
				   
int main(){
	  int t,e,f,g,h; int b=5,c=2,d=8; 
	  char p;
	  do{
	  system("cls");
      for(int i=0;i<10;i++)  puts(a[i]);                  
	  cout<<"请输入您所要选择的功能的序号："; cin>>t;
	  switch(t){
	  	case 1:  system("cls");
		         cout<<"苹果剩余："<<b<<"个"<<endl; 
		         cout<<"香蕉剩余："<<c<<"个"<<endl; 
				 cout<<"西瓜剩余："<<d<<"个"<<endl<<endl; 
				 cout<<"返回菜单请按'R'"; 
				 break; 
	  	
	  	case 2:  system("cls");
	 	         for(int i=0;i<4;i++) puts(x[i]);
	 	         cout<<"请选择要入库的物品种类: "; cin>>e;
	 	         cout<<"请输入要入库的物品数量: "; cin>>f; 
	  	         switch(e){
	  	         	case 1:cout<<endl<<"现入库苹果"<<f<<"个"<<endl<<endl; b=b+f; 
					   	   cout<<"返回菜单请按'R'"; break;
	  	         	case 2:cout<<endl<<"现入库香蕉"<<f<<"个"<<endl<<endl; c=c+f;
					   	   cout<<"返回菜单请按'R'"; break;	  	         	
	  	         	case 3:cout<<endl<<"现入库西瓜"<<f<<"个"<<endl<<endl; d=d+f;
					   	   cout<<"返回菜单请按'R'"; break;	  	         	
				   }
                 
		         break;
	  	
	  	case 3:  system("cls");
	 	         for(int i=0;i<4;i++) puts(x[i]);
	 	         do {
				    cout<<"请选择要出库的物品种类: "; cin>>g;
	 	            cout<<"请输入要出库的物品数量: "; cin>>h;
					if((g==1&&h>b)||(g==2&&h>c)||(g==2&&h>d)) cout<<endl<<"物品库存不足！请重新输入出库数量！"<<endl<<endl;}
				 while((g==1&&h>b)||(g==2&&h>c)||(g==2&&h>d));
	  	         switch(g){
	  	         	case 1:cout<<endl<<"现出库苹果"<<h<<"个"<<endl<<endl; b=b-h; 
					       cout<<"返回菜单请按'R'"; break;
	  	         	case 2:cout<<endl<<"现出库香蕉"<<h<<"个"<<endl<<endl; c=c-h;
	  	         		   cout<<"返回菜单请按'R'"; break;
	  	         	case 3:cout<<endl<<"现出库西瓜"<<h<<"个"<<endl<<endl; d=d-h;
	  	         	       cout<<"返回菜单请按'R'"; break;
				   }
                 
		         break;
	  	
	  	case 4:  exit(0); break;
	  	
	    } char ch=getch(); p=ch;
	  }  while(p=='r');
	  
	return 0;
	
}
