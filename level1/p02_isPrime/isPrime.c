#include<stdio.h>
int main(void){
	int n;
	scanf("%d",&n);
	int ret = 1;

	for (int i=2;i<n;i++){
		if (n%i==0){
			ret=0;
			break;
		}
	}
	if(ret==0 || n<2){
		printf("%d不是素数",n); 
	} else {
		printf("%d是素数",n);
	}
	return 0;
}
