#include<ctime>
#include<cstdio>
#include<cstdlib>
using namespace std; 

const int M = 1e3 + 1;

int tot, prm[M];
bool Minprm[M];

void Print_Primes() {
	for (int i = 2; i < M; ++i) {
		if (!Minprm[i]) {
			prm[++tot] = i;
			printf("%d\n", i);
		}
		for (int j = 1; j <= tot && i * prm[j] < M; ++j) {
			Minprm[i * prm[j]] = true;
			if (i % prm[j] == 0) break;
		}
	}
	return;
}

int main()
{
	clock_t Starttime, Endtime;
	Starttime = clock();
	Print_Primes();
	Endtime = clock();
	printf("Running time is:%lfs\n", (double)(Endtime - Starttime)/CLOCKS_PER_SEC);
	return 0;
}