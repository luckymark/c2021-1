#include<cstdio>
using namespace std;

int Pow(int num) { return num * num * num; }

int main()
{
	for (int i = 100; i < 1000; ++i) {
		int ans = Pow(i / 100);
		ans += Pow((i / 10) % 10);
		ans += Pow(i % 10);
		if (ans == i) printf("%d\n", ans);
	}
	return 0;
}//sunxiaorui