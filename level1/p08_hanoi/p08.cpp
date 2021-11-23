#include <cstdio>
#include <string>
using namespace std;

int n;

void move(int x, char from, char butter, char to){
	if (x == 1) printf("%c -> %c\n", from, to);
	else{
		move(x - 1, from, to, butter);
		move(1, from, butter, to);
		move(x - 1, butter, from, to);
	}
}

int main(){
	
	scanf("%d", &n);
	
	move(n, 'A', 'B', 'C');
	return 0;
}
