#include <cstdio>
#include <cstring>
#include <windows.h>
#include <cstdlib>

using namespace std;

const int turn_dir = 100;
int main(){
	int n = 1;
	int c = 1;
	while(1){
		
		for (int j = 1; j <= abs(n); j++) printf(" ");
		printf("%c", c == 1 ? '>':'<');
		system("cls");
		n += c;
		if (abs(n) == turn_dir) c = -c;
	}
	return 0;
}
