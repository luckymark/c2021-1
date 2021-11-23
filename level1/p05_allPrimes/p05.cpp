#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;

const int MAXN = 2021;

int pri[MAXN], cnt = 0;
bool is_p[MAXN];

void makepri(){
	memset(is_p, true, sizeof(is_p));
	
	for (int i = 2; i < MAXN; i++){
		if (is_p[i]) pri[++cnt] = i;
		
		for (int j = 1; j <= cnt; j++){
		    if (i * pri[j] >= MAXN) break;
		    is_p[i * pri[j]] = false; 
		    if (i % pri[j] == 0) break;
		}
	}
}

int main(){
	clock_t startTime, endTime;
	startTime =clock();
	
	makepri();
	
	endTime =clock();
	
	for (int i = 1; i <= cnt; i++)
		printf("%d\n", pri[i]);
	printf("Time is %lf", (double)(endTime - startTime) / CLOCKS_PER_SEC);
	return 0;
}
