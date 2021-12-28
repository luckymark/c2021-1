#include <stdio.h>
int isprime(int number)
{
	int i=2;
	int c=1;
	for(i=2;i<number;i++)
	{
		if(number%i==0)
		c=0;
	}
	return c;
}
int main()
 {
 	int i,p;
 	int a=0;
 	int b=0;
 	int sum=0;
 	for(p=2;p<100;p++)
 	{	
 		if(isprime(p))
 		sum++;	
 	}
 	int n[sum];
 	int w=0;
 	for(p=2;p<100;p++)
 	{	
 		if(isprime(p)){
 			n[w]=p;
 			w++;
 		}
 	}
 	int x,y,thenumber;
 	
 	for(thenumber=0;thenumber<100;thenumber+=2){
 		for(x=0;x<sum;x++){
 			for(y=0;y<sum;y++){
 				if(n[x]+n[y]==thenumber){
 				printf("%d+%d=%d\n",n[x],n[y],thenumber);
 				}
 			}
 		}
 	}
	  
}
