#include<stdio.h>
#include<time.h>
#define MAX 2000
char su[MAX+1];
int main() {
	clock_t start, end;
	double time;
	start = clock();
	for (int i = 2; i <= MAX; i++) {
		su[i] = 1;
	}
	for (int i = 2; i <= MAX; i++) {
		if (su[i]) {
			for (int j = i; j * i <= MAX; j++) {
				su[j * i] = 0;
			}
		}
	}
	end = clock();
	for (int i = 2; i <= MAX; i++) {
		if (su[i]) {
			printf("%d\n", i);
		}
	}
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%lfs", time);
	return 0;
}