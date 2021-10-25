#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
int	main(){
	int	n;
	clock_t	start,finish;
	double	time;
	start = clock();
	for( n = 2; n <= 1000; n++){
		int i, isPrime;
		isPrime = 0;
		for( i = 2; i <= n-1; i++){
			if( n % i == 0){
				isPrime = 1;
				break;
			}
		}
		if(isPrime == 0)	printf("%d \n", n);
	}
	finish = clock();
	time = (double)(finish - start)/CLOCKS_PER_SEC; 
	printf("time = %lf \n",time);
	return	0;
}
