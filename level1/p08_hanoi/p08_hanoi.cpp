#include <cstdio>
#include <windows.h>
using namespace std;
const int N = 64;

void f(int n, char from, char to, char pass){
	if(!n) return;
	f(n - 1, from, pass, to);
	printf("%c -> %c\n", from, to);
	f(n - 1, pass, to, from);
}

int main(){
	f(N, 'A', 'B', 'C');
	printf("%d²ãººÅµËşÒÆ¶¯Íê±Ï\n", N);
	system("pause");
	return 0;
}
