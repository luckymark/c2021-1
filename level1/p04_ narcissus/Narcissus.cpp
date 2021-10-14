#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define inf 0x7f7f7f7f

#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)<(y)?(x):(y)
#define swap(x,y) {int T=x; x=y; y=T;}
#define wipe(x,y) memset(x,y,sizeof(x))
#define rep(x,y,z) for(int x=y,I=z;x<=I;++x)

#define dbgIn(x) freopen(x".in","r+",stdin)
#define dbgOut(x) freopen(x".out","w+",stdout)

typedef long long LL;
typedef unsigned long long ULL;

bool isNarcissus(int X){
	int a=0,x=X;
	while(X)
		a+=(X%10)*(X%10)*(X%10),X/=10;
	return a==x;
}

int main(){
	rep(a,100,999)
		isNarcissus(a)?printf("%d\n",a):0;
	return 0;
}

