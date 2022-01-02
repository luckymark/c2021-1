#include<cstdio>
using namespace std;

int main()
{
	int Son_age,Father_age = 0;
	while (1) {
		Father_age+=2;
		if (Father_age % 6 != 0 || Father_age % 7 != 0 || Father_age % 12 != 0) continue;
		Son_age = Father_age >> 1;
		if (Father_age * 11 / 28 + 5 + Son_age + 4 == Father_age) {
			printf("%d\n", Father_age - 4);
			break;
		}			
	}
	return 0;
}//sunxiaorui