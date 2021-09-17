#include <cstdio>
using namespace std;

double pre = 1.0 / 6 + 1.0 / 12 + 1.0 / 7;

int main(){
	double x = (4 + 5) / (0.5 - (1.0 / 6 + 1.0 / 12 + 1.0 / 7));
	printf("%lf", x - 4);
	return 0;
}
