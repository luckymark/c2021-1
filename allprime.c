#include <stdio.h>
#include <time.h>
int main() {
	int num, Div;
	clock_t start,finish;
	double totalTime;
	start = clock();
	printf("1, 2");
	for (num = 3; num <= 1000; num += 2) {
		for(Div = 3; Div < num; Div +=2 ) {
			if (num % Div == 0) {
				break;
			}
		}
 
		if(Div >= num) {
			printf(", %d", num);
		}
	}
	printf("\n");
	finish = clock();
	totalTime = (double)(finish-start) / CLOCKS_PER_SEC;
	printf("打印的总时间为%.30f",totalTime);
	return 0;
}