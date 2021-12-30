#include<iostream>
#include<windows.h>
#include<conio.h>
#include<cstdio>
using namespace std;
char a[60][60]={"□□□□□□□□□□□□□□□□□□□□",
                "□S □      □  □  □  □  □□      □",
                "□  □  □  □  □  □  □  □□  □  □",
                "□      □  □  □  □            □  □",
                "□□□□□  □      □  □□□□□□□□",
                "□  □      □  □  □  □  □      □□",
                "□  □  □□□  □  □          □  □□",
                "□  □  □      □  □  □  □□□  □□",
                "□          □□□  □  □  □      □□",
                "□□□□□□□      □  □  □  □□□□",
                "□  □      □  □□□  □  □  □    □",
                "□  □  □  □  □      □  □        □",
                "□  □  □      □  □□□  □□□□  □",
                "□      □□□□□  □  □  □E □    □",
                "□  □              □      □        □",
                "□□□□□□□□□□□□□□□□□□□□",};
 //总地图 
 void walk(char,char);
int main(){
    for(int i=0;i<20;i++) puts(a[i]);
	int x=1,y=2;char ch;
	while(1){
		ch=getch();
		if(ch=='w'){
			if(a[x-1][y]==' '||a[x-1][y]=='E'){
				a[x][y]=' ';
				x--;
				a[x][y]='S';
			}
		}
		else if(ch=='s'){
			if(a[x+1][y]==' '||a[x+1][y]=='E'){
				a[x][y]=' ';
				x++;
				a[x][y]='S';
			}
		}
		else if(ch=='a'){
			if(a[x][y-1]==' '||a[x][y-1]=='E'){
				a[x][y]=' ';
				y--;
				a[x][y]='S';
			}
		}
		else if(ch=='d'){
			if(a[x][y+1]==' '||a[x][y+1]=='E'){
				a[x][y]=' ';
				y++;
				a[x][y]='S';
			}
		}
		system("cls");
		for(int i=0;i<20;i++) puts(a[i]);
		if(x==13&&y==30) break;
	}
    char S,E; 
	walk(S,E);
	cout<<"恭喜通过迷宫！";
	system("pause"); 
	return 0;
} 

