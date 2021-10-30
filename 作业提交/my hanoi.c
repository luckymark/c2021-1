#include<stdio.h>
void hanoi(int cnt, char a, char b, char c)
{
	if(cnt == 1) {
		printf("%c -> %c\n", a, b);
	}else {
		hanoi(cnt - 1, a, c, b);
		printf("%c -> %c\n", a, b);
		hanoi(cnt - 1, c, b, a);
	}
} 

int main()
{
	hanoi(4, 'A', 'C', 'B');
	return 0;
}
