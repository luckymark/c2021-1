//线性筛 
#include <cstdio>
#include <windows.h>
#include <list>
using namespace std;
const int N = 101;

int prime[N], len;
bool vis[N];

list<int> f(int n, int i, int rem){
	if(!rem) return n == 0 ? list<int>() : list<int>(1);
	if(!rem && n == 0) return list<int>();
	for(; i <= len && prime[i] <= n; i++){
		list<int> lst = f(n - prime[i], i, rem - 1);
		if(lst.size() == rem - 1){
			lst.push_back(prime[i]);
			return lst;
		}
	}
	return list<int>();
}

int main(){
	prime[1] = 1, len = 1;
	for(int i = 2; i < N; i++){
		if(!vis[i]) prime[++len] = i;
		for(int j = 2; j <= len && i * prime[j] < N; j++){
			vis[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
	for(int i = 3; i < N; i++){
		list<int> lst = f(i, 1, 3);
		if(lst.empty()){
			printf("数字%d哥德巴赫猜想不成立！\n", i);
			return 0;
		}
		printf("数字%d可被分解为：", i);
		for(auto x : lst) printf("%d ", x);
		putchar('\n');
	}
	puts("已验证哥德巴赫猜想在100以内正确性");
	return 0;
}
