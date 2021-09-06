#include <cstdio>
#include <windows.h>
using namespace std;
const int N = 80, M = 10, sleeptime = 10;

char c;

int main(){
	printf("ÇëÊäÈë×Ö·û£º");
	scanf(" %c", &c);
	while(true){
		for(int i = 0; i < N; i++){
			system("cls");
			for(int j = 0; j < M; j++)
				putchar('\n');
			for(int j = 0; j < i; j++)
				putchar(' ');
			putchar(c);
			Sleep(sleeptime);
		}
		for(int i = N - 1; ~i; i--){
			system("cls");
			for(int j = 0; j < M; j++)
				putchar('\n');
			for(int j = 0; j < i; j++)
				putchar(' ');
			putchar(c);
			Sleep(sleeptime);
		}
	}
	return 0;
}
