#include<iostream>
#include<cstdio>
#include<windows.h>
#include<conio.h>
using namespace std;
int main(){
char a[60][60]={"□□□□□□□□□□□□□□□□□□□□",
                "□S □      □  □            □      □",
                "□  □  □  □  □  □  □    □ X□  □",
                "□      □  □  □  □                □",
                "□□□□□              □□□□□□□□",
                "□  □      □  □  □  □  □      □□",
                "□  □  □□□  □  □         E□  □□",
                "□  □ X□      □          □□□  □□",
                "□              □  □  □  □      □□",
                "□□□□□□□E     □  □      □□□□",
                "□  □      □  □□□  □  □  □    □",
                "□  □  □  □          □            □",
                "□ X□          □  □□□  □  □□  □",
                "□      □□□          □  □  □    □",
                "□  □            E □      □        □",
                "□□□□□□□□□□□□□□□□□□□□",};
	for(int i=0;i<17;i++) puts(a[i]);
	cout<<"人为'S',箱子为'X',终点为'E'。"<<endl<<"如将箱子成功推到终点'E',则终点'E'会变为'F',视作该箱子已到达指定位置。"
	<<endl<<"如箱子走到死角，则视为失败，请按R重新开始游戏."<<endl; 
	 int x=1,y=2; int t=0;
		while(1){
		char ch=getch();  
		if(ch=='w'){
			if(a[x-1][y]==' '){
				a[x][y]=' '; x--;
				a[x][y]='S';
			}
			else if(a[x-1][y]=='X'&&a[x-2][y]==' '){
				    a[x-1][y]=' '; a[x-2][y]='X';
				    a[x][y]=' '; x--;
				    a[x][y]='S';
			}
			else if(a[x-1][y]=='X'&&a[x-2][y]=='E'){
			    	a[x-1][y]=' '; a[x-2][y]='F';
			    	a[x][y]=' '; x--;
				    a[x][y]='S';
			} 
			t++;
		}
		else if(ch=='s'){
			if(a[x+1][y]==' '){
				a[x][y]=' '; x++;
				a[x][y]='S';
			}
			else if(a[x+1][y]=='X'&&a[x+2][y]==' '){
				    a[x+1][y]=' '; a[x+2][y]='X';
				    a[x][y]=' '; x++;
				    a[x][y]='S';
			}
			else if(a[x+1][y]=='X'&&a[x+2][y]=='E'){
				    a[x+1][y]=' '; a[x+2][y]='F';
				    a[x][y]=' '; x++;
				    a[x][y]='S';
			}
			t++;			
		}
		else if(ch=='a'){
			if(a[x][y-1]==' '){
				a[x][y]=' '; y--;
				a[x][y]='S';
			}
			else if(a[x][y-1]=='X'&&a[x][y-2]==' '){
				    a[x][y-1]=' '; a[x][y-2]='X';
				    a[x][y]=' '; y--;
				    a[x][y]='S';
			}
			else if(a[x][y-1]=='X'&&a[x][y-2]=='E'){
				    a[x][y-1]=' '; a[x][y-2]='F';
				    a[x][y]=' '; y--;
				    a[x][y]='S';
			}	
			t++;		
		}
		else if(ch=='d'){
			if(a[x][y+1]==' '){
				a[x][y]=' '; y++;
				a[x][y]='S';
			}
			else if(a[x][y+1]=='X'&&a[x][y+2]==' '){
				    a[x][y+1]=' '; a[x][y+2]='X';
			    	a[x][y]=' '; y++;
				    a[x][y]='S';
			}
			else if(a[x][y+1]=='X'&&a[x][y+2]=='E'){
				    a[x][y+1]=' '; a[x][y+2]='F';
				    a[x][y]=' '; y++;
				    a[x][y]='S';
			}	
			t++;		
		}
		else if(ch=='r') {
			system("cls"); Sleep(1000);
			cout<<"即将重新游戏"; Sleep(1000); system("cls");
            main(); 
		}
		system("cls");
		for(int i=0;i<17;i++) puts(a[i]); 
		if(a[9][14]=='F'&&a[14][18]=='F'&&a[6][31]=='F'){
        Sleep(1000);
	    goto next;
		}
		cout<<"人为'S',箱子为'X',终点为'E'。"<<endl<<"如将箱子成功推到终点'E',则终点'E'会变为'F',视作该箱子已到达指定位置。"
		<<endl<<"如箱子走到死角，则视为失败，请按R重新开始游戏."<<endl<<endl<<"当前所用步数为："<<t<<"步"; 
     }
     next:
     system("cls"); Sleep(1000);
	 cout<<"恭喜通关！"<<endl<<endl<<"所用步数为："<<t<<"步";
	 system("pause"); 
	return 0;
} 
