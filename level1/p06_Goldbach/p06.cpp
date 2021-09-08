#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100;

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

void _Goldbach(int x){
	for (int i = 1; pri[i] < x; i++) for (int j = i; pri[i] + pri[j] < x; j++){
		if (is_p[x - pri[i] - pri[j]]){
			printf("%d = %d + %d + %d\n", x, pri[i], pri[j], x - pri[i] - pri[j]);
			return ;
		}
	}
}

int main(){
	makepri();
	
	for (int i = 3; i <= MAXN; i++) _Goldbach(i);
	return 0;
}
