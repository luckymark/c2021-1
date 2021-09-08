#include <cstdio>
#include <cstring>
#include <windows.h>
#include <cstdlib>

using namespace std;

const int halt = 80;
int main(){
	int n = 1;
	int c = 1;
	while(1){
		
		for (int j = 1; j <= abs(n); j++) printf(" ");
		printf("1");
		system("cls");
		n += c;
		if (abs(n) == halt) c = -c;
	}
	return 0;
}
