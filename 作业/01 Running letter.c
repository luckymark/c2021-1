#include <stdio.h>
#include <windows.h>
int main(){
	int i,j,m;
for(j=1;j<100;j++){
for(i=0;i<j;i++){
	printf(" ");
}printf("Z");
Sleep(10);
system("cls");}
for(;j>=0&&j<=100;j--){
	for(m=0;m<j;m++){
	printf(" ");
	}printf("Z");
	Sleep(10);
	system("cls");
	}return 0;}
