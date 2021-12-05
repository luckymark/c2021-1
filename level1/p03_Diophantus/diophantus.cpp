#include<stdio.h>
int main() {
	double age ;
	for (age = 1.0;; age++) {

		if (0.5 * age + (1.0/6+1.0/12+1.0/7 )*age+ 5.0 + 4.0 == age) {

			printf("%f", (0.5 + 1.0 / 6 + 1.0 / 12 + 1.0 / 7) *age);
			break;
		}
	}
}