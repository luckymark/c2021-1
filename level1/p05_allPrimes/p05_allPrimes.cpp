//线性筛 
#include <cstdio>
#include <windows.h>
using namespace std;
const int N = 1001;

int prime[N], len;
bool vis[N];

int main(){
	for(int i = 2; i < N; i++){
		if(!vis[i]){
			printf("%d\n", i);
			prime[++len] = i;
		}
		for(int j = 1; j <= len && i * prime[j] < N; j++){
			vis[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
	puts("1~1000内质数打印完成");
	system("pause");
	return 0;
}
