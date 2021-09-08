#include<stdio.h>
#include<stdlib.h>
void running(int i);
int main(void){
	
	int i=0;	
	while(1){    
		for(i=0;i<100;i++){
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
	for(int a=1;a<=i;a++){
		printf(" ")	;
	}
		printf("A");
		system("cls");
}

	
