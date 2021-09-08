#include <cstdio>
#include <string>
using namespace std;

const int MAX_Age = 9999;
bool is_rightAge(int x){
	if ((x % 12) || (x % 7)) return false;
	else return (x / 12 + x / 6 + x / 7 + 5 + x / 2 + 4 == x);
}
int main(){
	for (int i = 1; i <= MAX_Age; i++) if (is_rightAge(i)){
		printf("Diophantus died at the age of %d\n", i);
		break;
	}
	return 0;
}
