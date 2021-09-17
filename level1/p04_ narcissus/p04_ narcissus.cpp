#include <cstdio>
#include <windows.h>
using namespace std;

int pow3(int x){
	int ret = x;
	for(int i = 0; i < 2; i++)
		ret *= x;
	return ret;
}

int get(int n){
	if(!n) return 0;
	return pow3(n % 10) + get(n / 10);
}

bool isSXH(int n){
	return n == get(n);
}

int main(){
	for(int i = 100; i < 1000; i++)
		if(isSXH(i)) printf("%d\n", i);
	puts("��λˮ�ɻ�����ӡ���");
	system("pause");
	return 0;
}
