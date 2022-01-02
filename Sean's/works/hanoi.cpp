#include<cstdio>
using namespace std;

int n;
char tag[4] = {' ','A','B','C'};

void Hanoi(int num, int from, int to) {
	if (num == 1) {
		printf("%c -> %c\n", tag[from], tag[to]);
		return;
	}
	int Next;
	for (int i = 1; i <= 3; ++i)
		if (i != from && i != to) {
			Next = i; 
			break;
	}
	Hanoi(num - 1, from, Next);
	printf("%c -> %c\n", tag[from], tag[to]);
	Hanoi(num - 1, Next, to);
	return;
}

int main() 
{
	scanf_s("%d", &n);
	Hanoi(n, 1, 3);
	return 0;
}//sunxiaorui