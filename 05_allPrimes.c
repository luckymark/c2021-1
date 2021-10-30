#include<stdio.h>
#include<time.h>
#define MAX 2000
char array[MAX+1];
int main() {
	clock_t start, end;
	double time;
	start = clock();
	int i = 2, j;
	for (; i <= MAX; i++) {
		array[i] = 1;
	}
	for (i = 2; i <= MAX; i++) {
		if (array[i]) {
			for ( j = i; j * i <= MAX; j++) {
				array[j * i] = 0;
			}
		}
	}
	end = clock();
	for (i = 2; i <= MAX; i++) {
		if (array[i]) {
			printf("%d\n", i);
		}
	}
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%lfs", time);
	return 0;
}
