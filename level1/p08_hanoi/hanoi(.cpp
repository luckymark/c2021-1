#include<stdio.h>
using namespace std;
void h(int n,char a,char b,char c);
void move(char a,char b);
int main(){
	int n;
	scanf("%d",&n);
	h(n,'A','B','C');
	return 0;
}
void h(int n,char a,char b,char c)
	{
		if (n==1)
		move(a,c);
		else {
			h(n-1,a,c,b);
			move(a,c);
			h(n-1,b,a,c);
		}
	}
void move(char a,char b)
{
	printf("%c -> %c\n",a,b);
}
