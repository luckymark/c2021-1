#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int isPrime(int i);
int main(void){
	int prime[2000]={2};
	int count =1;
	clock_t start, finish;
	double Total_time;
	start =clock();
	for (int i=3;i<=10000;i+=2){
		if (isPrime(i)){
			prime[count++]=i;
		}
	}
	for (int i=0;i<count;i++){
		printf("%d\t",prime[i]);
	}
	printf("count=%d\n",count);
	finish =clock();
	Total_time = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("用时：%f second",Total_time);
	return 0;
}
int isPrime(int i){
	int ret=1;
	for (int t=3;t<=sqrt(i);t++){
		if (i%t==0){
			ret=0;
			break;
		}
	}
	return ret;
}
