#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<math.h>
#include<bios.h>
#define up 0x4800
#define down 0x5000
#define left 0x4d00
#define right 0x4b00
char mp[30][30];
int n,key;
struct node{
	int x,y;
};
struct node pos;
bool check(){
	if(pos.x==n&&pos.y==n) return 0;
	return 1;
}
void change(int f,int id,int st,int ed){
	if(f==1){
		for(int i=st;i<=ed;i++)
			mp[id][i]='1';
	}
	if(f==2){
		for(int i=st;i<=ed;i++)
			mp[i][id]='1';
	}
}
void reset(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mp[i][j]='0';
	change(1,1,1,3);
	mp[4][2]=mp[2][1]=mp[3][7]=mp[3][9]='1';
	mp[4][18]=mp[4][19]=mp[6][11]=mp[6][13]='1';
	mp[7][3]=mp[7][13]=mp[7][14]=mp[9][4]=mp[10][4]=mp[9][14]='1';
	mp[10][21]=mp[11][2]=mp[11][3]=mp[12][4]=mp[13][4]='1';
	mp[20][14]='1';
	
	change(1,2,3,17);
	change(2,3,2,5);
	change(1,3,16,18);
	change(1,4,13,15);
	change(2,16,4,7);
	change(2,10,4,10);
	change(1,5,4,6);
	change(2,20,5,7);
	change(1,6,6,8);
	change(2,19,7,9);
	change(2,6,7,16);
	change(1,8,3,5);
	change(1,8,11,15);
	change(1,9,7,9);
	change(1,9,18,21);
	change(1,10,11,15);
	change(2,1,11,18);
	change(2,3,12,18);
	change(2,4,18,21);
	change(2,5,15,18);
	change(1,21,5,14);
	change(2,17,10,20);
	change(1,20,16,21);
	change(2,21,17,21);
	change(2,13,11,19);
	change(1,19,14,16);
	
	mp[21][21]='B';
	mp[pos.x][pos.y]='A';
}
void print(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			printf("%c",mp[i][j]); 
}
int main(){
	n=21;
	res();
	while(check()){
		key=bioskey(0);
		switch(key){
			case up : {
				if(pos.x>1){
					pos.x-=1;
					reset();
					system("CLS");
					print();
				}
				break;
			}
			case down : {
				if(pos.x<n){
					pos.x+=1;
					reset();
					system("CLS");
					print();
				}
				break;
			}
			case left : {
				if(pos.y>1){
					pos.y-=1;
					reset();
					system("CLS");
					print();
				}
				break;
			}
			case right : {
				if(pos.y<n){
					pos.y+=1;
					reset();
					system("CLS");
					print();
				}
				break;
			}
		}default;
	}
	system("CLS");
	printf("--------------Good  Game ! ! !--------------");
	return 0;
}
