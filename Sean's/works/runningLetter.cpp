#include<cstdio>
#include<stdlib.h>
#define MAX_N 111

using namespace std;

void Circulate(bool flag)
{
	for (int i = 1; i <= MAX_N; ++i)
	{
		int j = flag ? i : 101 - i;
		while(--j) printf(" ");
		printf("crush on you");
		system("cls");
	}
}

int main()
{
	Circulate(1);
	Circulate(0);
	return 0;
}//sunxiaorui