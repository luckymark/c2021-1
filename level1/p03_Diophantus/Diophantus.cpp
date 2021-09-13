#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define INF 0x7f7f7f7f

#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)<(y)?(x):(y)
#define swap(x,y) {int T=x; x=y; y=T;}
#define wipe(x,y) memset(x,y,sizeof(x))
#define rep(x,y,z) for(int x=y,I=z;x<=I;++x)

#define dbgIn(x) freopen(x".in","r+",stdin)
#define dbgOut(x) freopen(x".out","w+",stdout)

typedef long long LL;
typedef unsigned long long ULL;

int main(){
	printf("%.lf\n",(double)(5+4)/(double)((double)1-((double)1/6+(double)1/12+(double)1/7+0.5))-4);
	return 0;
}
