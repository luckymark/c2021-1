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

int a;

bool isPrime(int X){
	if(X<=2) return false;
	if(!(X%2)) return false;
	for(int I=3;I*I<=X;I+=2)
		if(!(X%I)) return false;
	return true;
}

int main(){
	scanf("%d",&a);
	printf("%s\n",isPrime(a)?"Yes":"No");
	return 0;
}

