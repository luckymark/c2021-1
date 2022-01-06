#include<stdio.h>
int main(){
	int n=1;
	while(n*84<=150){
		n++;
	} 
	n-=1;
	printf("%d",n*84-4);
	return 0;
}
