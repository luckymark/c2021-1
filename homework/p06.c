#include<stdio.h>
int gdbh1(int m,int n,int*p) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (p[i] + p[j] == m)return 1;
		}
	}
	return 0;
}
int gdbh2(int m, int n, int* p) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (p[i] + p[j] + p[k] == m)return 1;
			}
		}
	}
	return 0;
}
int main() {
	int su[50], pd[101], n = 0;
	for (int i = 0; i <= 100; i++) {
		pd[i] = 1;
	}
	for (int i = 2; i <= 100; i++) {
		if (!pd[i])continue;
		n++;
		su[n] = i;
		for (int j = 2; i * j <= 100; j++) {
			if (!su[j])continue;
			pd[i * j] = 0;
		}
	}
	for (int i = 4; i <= 100; i += 2) {
		if (!gdbh1(i, n, su)) {
			printf("在100以内哥德巴赫猜想不成立\n");
			return 0;
		}
	}
	for (int i = 7; i <= 100; i += 2) {
		if (!gdbh2(i, n, su)) {
			printf("在100以内哥德巴赫猜想不成立\n");
			return 0;
		}
	}
	printf("在100以内哥德巴赫猜想成立\n");
	return 0;
}