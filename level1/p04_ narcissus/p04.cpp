#include <cstdio>
#include <cmath>
using namespace std;

int f(int x){return x*x*x;}
int main(){
	for (int i = 100; i <= 999; i++){
		int a = i % 10, b = i / 10 % 10, c = i / 100;
		if (f(a) + f(b) + f(c) == i) printf("%d\n", i);
	}
	return 0;
}
