#include<stdio.h>
#include<math.h>
int main(){
	int a,b,c,sum;
	for(a=1;;a++){
		c=a;
		sum=0;
		do{
			b=c%10;
			sum+=pow(b,3);
			c=c/10;
		}while(c>0);
	if(sum==a){
	printf("%d ",a);}
	}
	return 0;
}

