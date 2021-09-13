#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<unistd.h>
#include<algorithm>

#define INF 0x7f7f7f7f

#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)<(y)?(x):(y)
#define swap(x,y) {int T=x; x=y; y=T;}
#define wipe(x,y) memset(x,y,sizeof(x))
#define rep(x,y,z) for(int x=y,I=z;x<=I;++x)

#define dbgIn(x) freopen(x".in","r+",stdin)
#define dbgOut(x) freopen(x".out","w+",stdout)

#define MAX_X 28
#define MAX_Y 118

typedef long long LL;
typedef unsigned long long ULL;

char ch;

void printChar(int X,int Y){
	putchar('\b');
	putchar(' ');
	if(Y>=MAX_Y){
		putchar('\n');
		if(X>=MAX_X)
			system("cls");
	}
	putchar(ch);
	return;
}

int main(){
	ch=getchar();
	system("cls");
	while(1)
		rep(x,-1,MAX_X)
			rep(y,0,MAX_Y)
				printChar(x,y);
	return 0;
}

