#include<stdio.h>
int main() {
	int a[25] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43 , 47, 53,59,61,67, 71, 73,79, 83,89,97 };
	int n = 2;
	int num = 2*n;
	int i = 0;
	int b = 0;
	for (; i < 25; i++) {
		for (b = 0; b < 25;b++) {
			num = 2 * n;

		if (num == a[i]+a[b]){
			printf("%d=%d+%d\n", num, a[i], a[b]);
			n++;
			b = 0; i = 0;
		}
	
		if (num > 100) {
			goto out;
		}
		
		if (i==25&&b==25) {
			n++;
		}
		
		}
	}
out:printf("结束");
}