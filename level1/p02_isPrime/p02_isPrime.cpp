#include <cstdio>
using namespace std;

long long x;

int main(){
	while(true){
		bool flag = false;
		printf("���������֣�֧��long long��Χ����");
		scanf("%d", &x);
		for(int i = 2; i * i <= x; i++)
			if(x % i == 0){
				flag = true;
				break;
			}
		if(flag) puts("��������һ������");
		else puts("������һ������"); 
	}
	return 0;
}
