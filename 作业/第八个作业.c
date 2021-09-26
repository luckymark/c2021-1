#include <stdio.h>
#include <string.h>
void move(char x,char y);
void hanoi(int n,char a,char b,char c);

int main(){
int n=64;
hanoi(n,'A','B','C');
out:
return 0;	
}

void move(char x,char y){
printf("%c--->%c\n",x,y);
}

void hanoi(int n,char a,char b,char c)
{if(n>0){
hanoi(n-1,a,c,b);
	move(a,c);
	hanoi(n-1,b,a,c);}
}
