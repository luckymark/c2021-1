#include <cstdio>
using namespace std;

long long x;

int main(){
	while(true){
		bool flag = false;
		printf("请输入数字（支持long long范围）：");
		scanf("%d", &x);
		for(int i = 2; i * i <= x; i++)
			if(x % i == 0){
				flag = true;
				break;
			}
		if(flag) puts("该数不是一个质数");
		else puts("该数是一个质数"); 
	}
	return 0;
}
