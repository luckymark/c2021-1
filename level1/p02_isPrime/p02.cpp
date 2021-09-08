#include <cstdio>
#include <cmath>
using namespace std;

bool if_prime(int x){
	for (int i = 2; i <= sqrt(x); i++) if(!(x % i)) return false;
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	
	if (if_prime(n)) printf("%d is a prime!", n);
	else printf("%d isn't a prime,SAD", n);
	return 0;
}
