#include<cstdlib>
#include<cstdio>
using namespace std;

const int M = 5e6 + 1;
const int N = 1e8 + 1;

int n,q,num;
int Prime[M];//Primes
bool MinPr[N];//To record if this number have been tagged before & To save the memory;
 
void Get_Prime(int Num) 
{
	int tot = 0;
	for (int i = 2; i <= Num; ++i) 
	{
		if (MinPr[i] == 0) Prime[++tot] = i;
		for (int j = 1; j <= tot && i*Prime[j] <= Num; ++j)//avoid meaningless calculation
		{
			MinPr[Prime[j] * i] = true;
			if (i % Prime[j] == 0) break;
			//To ensure that each number can only be tagged once by its Minimum prime.
		}
	}
	return;
}

int main()
{
	scanf_s("%d%d",&n,&q);
	Get_Prime(n);
	for (int i = 1; i <= q; ++i)
	{
		scanf_s("%d", &num);
		printf("%d\n", Prime[num]);
	}
	return 0;
}