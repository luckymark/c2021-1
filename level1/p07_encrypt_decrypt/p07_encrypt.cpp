#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N = 101;

unsigned int seed;
char s[101], enc[256];
int val[256];

bool cmp(char a, char b){
	return val[a] < val[b];
}

void init(){
	for(int i = 32; i <= 126; i++)
		enc[i] = i, val[i] = rand();
	sort(enc + 32, enc + 127, cmp);
}

int main(){
	while(true){
		printf("请输入加密种子（unsigned int）：");
		scanf("%u", &seed);
		srand(seed);
		init();
		char c = getchar();
		while(c != '\n') c = getchar();
		printf("请输入字符串（最大长度100，请注意，支持空格）：");
		gets(s);
		for(char *c = s; *c; c++)
			putchar(enc[*c]);
		puts("[结束]");
	}
	return 0;
}
