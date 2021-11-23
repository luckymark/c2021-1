/*
 * @Author: your name
 * @Date: 2021-09-06 20:51:46
 * @LastEditTime: 2021-10-25 19:38:23
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \undefinedc:\VScode_c\level1\p02.cpp
 */
#include <cstdio>
#include <cmath>
using namespace std;

bool is_prime(int x){
	for (int i = 2; i <= sqrt(x); i++) if(!(x % i)) return false;
	return true;
}

int main(){
	int n;
	printf("Plz input a positive number:");
	scanf("%d", &n);
	if (n <= 0) printf("%d is not a positive number!\n",n);
	else if (is_prime(n)) printf("%d is a prime!\n", n);
	else printf("%d isn't a prime,SAD\n", n);
	return 0;
}
