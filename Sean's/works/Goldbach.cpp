#include<cstdio>
using namespace std;

const int M = 100 + 1;

int tot,prm[M],Sprm[M][3];

int main()
{
	for (int i = 2; i < M; ++i) {
		bool flag = false;
		for (int j = 2; j * j <= i; ++j)
			if (i % j == 0) {
				flag = true; 
				break;
			}
		if (flag == false) prm[++tot]=i;
	}
	for (int i = 1; i <= tot; ++i) {
		for (int j = i; j <= tot; ++j) {
			int now = prm[i] + prm[j];
			if (now >= M) break;
			Sprm[now][1] = prm[i], Sprm[now][2] = prm[j];
		}
	}
	for (int i = 4; i < M; i += 2)
		printf("%d=%d+%d\n", i, Sprm[i][1], Sprm[i][2]);
	return 0;
}