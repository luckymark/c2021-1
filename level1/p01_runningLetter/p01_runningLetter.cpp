#include <cstdio>
#include <windows.h>
using namespace std;
const int N = 80, M = 10, sleeptime = 1;

char c;

void printtimes(char c, int t){
	while(t--) putchar(c);
}

void print(int i){
	system("cls");
	printtimes('\n', M);
	printtimes(' ', i);
	putchar(c);
	Sleep(sleeptime);
}

int main(){
	printf("ÇëÊäÈë×Ö·û£º");
	scanf(" %c", &c);
	while(true){
		for(int i = 0; i < N; i++)
			print(i);
		for(int i = N - 1; ~i; i--)
			print(i);
	}
	return 0;
}
