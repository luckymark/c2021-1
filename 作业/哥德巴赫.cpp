#include<stdio.h>
int	main(){
	int	n,a,b,i,count1,count2;
	for(n=4;n<=100;n+=2){
		for(a=2;a<=n/2;a++){
			count1=0;
			for(i=2;i<=a-1;i++){
				if(a%i==0){
					count1=1;
					break;
				}
			}
			if(count1==0){
				count2=0;
				b=n-a;
				for(i=2;i<=b-1;i++){
					if(b%i==0){
						count2=1;
					}
				}
				if(count2==0){
					printf("%d=%d+%d\n",n,a,b);
					break;
				}
			}
		}
	}
	return	0;
}
