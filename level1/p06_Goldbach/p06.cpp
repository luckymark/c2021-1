/*
 * @Author: your name
 * @Date: 2021-09-06 21:09:42
 * @LastEditTime: 2021-10-25 20:45:45
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \undefinedc:\VScode_c\level1\p06.cpp
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
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

bool _Goldbach(int x){
	for (int i = 1; pri[i] < x; i++) {
		if (is_p[x - pri[i]]){
			printf("%d = %d + %d\n", x, pri[i], x - pri[i]);
			return true;
		}
	}
	return false;
}

int main(){
	makepri();
	
	for (int i = 4; i <= MAXN; i+=2){
		if (!_Goldbach(i)){
			printf("Goldbach was wrong\n");
			exit(0);
		}
	}
	return 0;
}
