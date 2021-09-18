#include<stdio.h>
#include<stdlib.h>
#define MAX_CH 100
void running(int i);
int main(void){

	int i=0;
	while(1){
		for(i=0;i<MAX_CH;i++){
			running(i);
			
			i++;
		}
		for(;i>0;i--){
			running(i);
		}
	}
	
	return 0;
}
void running(int i){
	int a;
	for(a=1;a<=i;a++){
		printf(" ")	;
	}
		printf("A");
		system("cls");
}

	
