#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int isPrime (int i);
int main(){
	clock_t start, finish;
	double Total_time;
	start=clock();
	const int number=10000;
	int prime[10000]={2};
	
	int count=1;
	for(int i=3;i<=number;i++)
	{
		if(isPrime(i)){
			prime[count++]=i;
		}	
	}
	for (int i=0;i<count;i++){
		printf("%d	",prime[i]);
	}
	finish=clock();
	Total_time = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("\nÓÃÊ±%f second\n",Total_time);
	printf("count=%d",count);
	return 0;
}
int isPrime(int i){
	int ret=1;
	for (int t=2;t<i;t++){
		if(i%t==0){
			ret=0;
			break;
		}
	}
	return ret;
}
