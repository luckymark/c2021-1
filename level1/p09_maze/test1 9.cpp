#include <stdio.h> 
#include<Windows.h>
#include<conio.h>
int main(){	
	int dx=10;
	int dy=10;
	int m[10][10]={ {2,1,2,2,2,2,2,2,2,2},
				    {2,0,0,0,0,2,0,0,0,2},
				    {2,0,2,2,2,2,2,0,2,2},
				    {2,0,0,0,0,0,0,0,0,2},
					{2,0,2,2,2,0,2,0,0,2},
					{2,0,2,0,0,0,0,0,0,2},
					{2,0,0,2,0,2,0,0,0,2},
					{2,2,2,2,0,2,0,2,0,2},
					{2,0,0,0,0,2,0,2,0,2},
					{2,0,2,2,2,2,2,2,2,2}};
for (int i = 0; i < dx; i++) {
		for (int j = 0; j < dy; j++) {
			if (m[i][j] == 0) {
				printf("  ");
			}
			if(m[i][j]==1){
				printf("人"); 
			}
			if(m[i][j]==2) {
				printf("国");
			}
		}
		printf("\n");
	}

	int a;
	int x=0,y=1;
	do {
		int ch=getch();	
		switch(ch){
				case 119:
					if(m[x-1][y]==0){ 
					
					m[x-1][y]=1;
					m[x][y]=0;
					x--;
					system("cls");
					for (int i = 0; i < dx; i++) {
		for (int j = 0; j < dy; j++) {
			if (m[i][j] == 0) {
				printf("  ");
			}
			if(m[i][j]==1){
				printf("人"); 
			}
			if(m[i][j]==2){
				printf("国");
			}
		}
		printf("\n");
	}
}
			continue;		
					
				case 115:
					if(	m[x+1][y]==0){ 
					
					m[x+1][y]=1;
					m[x][y]=0;
					x=x+1;
					system("cls");
					for (int i = 0; i < dx; i++) {
		for (int j = 0; j < dy; j++) {
			if (m[i][j] == 0) {
				printf("  ");
			}
			if(m[i][j]==1){
				printf("人"); 
			}
			if(m[i][j]==2){
				printf("国");
			}
		}
		printf("\n");
	}
}
				continue;
				case 100:
					if(m[x][y+1]==0){ 
					
					m[x][y+1]=1;
					m[x][y]=0;
					y=y+1;
					system("cls");
					for (int i = 0; i < dx; i++) {
		for (int j = 0; j < dy; j++) {
			if (m[i][j] == 0) {
				printf("  ");
			}
			if(m[i][j]==1){
				printf("人"); 
			}
			if(m[i][j]==2){
				printf("国");
			}
		}
		printf("\n");
	}
}
			continue;		
				
				case 97:
					if(m[x][y-1]==0){ 
					
					m[x][y-1]=1;
					m[x][y]=0;
					y=y-1;
					system("cls");
					for (int i = 0; i < dx; i++) {
		for (int j = 0; j < dy; j++) {
			if (m[i][j] == 0) {
				printf("  ");
			}
			if(m[i][j]==1){
				printf("人"); 
			}
			if(m[i][j]==2){
				printf("国");
			}
		}
		printf("\n");
	}
}
				continue;	
				default:
					break;
			}
	}while(m[9][1]!=1);	
	printf("hello");

}


