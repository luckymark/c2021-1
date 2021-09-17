//线性筛 
#include <cstdio>
#include <windows.h>
using namespace std;
const int N = 1001;

int prime[N], len;
bool vis[N];

int main(){
	LARGE_INTEGER li;
	QueryPerformanceFrequency(&li);
	double freq = li.QuadPart;
	QueryPerformanceCounter(&li);
	double start = li.QuadPart;
	for(int i = 2; i < N; i++){
		if(!vis[i]) prime[++len] = i;
		for(int j = 1; j <= len && i * prime[j] < N; j++){
			vis[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
	QueryPerformanceCounter(&li);
	double end = li.QuadPart;
	printf("1~1000内质数计算完成，所用时间：%.07lf s\n接下来开始打印素数\n", (end - start) / freq);
	for(int i = 1; i <= len; i++)
		printf("%d\n", prime[i]);
	puts("1~1000以内素数打印完毕");
	system("pause");
	return 0;
}
