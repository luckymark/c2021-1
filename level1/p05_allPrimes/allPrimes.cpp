#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define MAX_SIZE 1005
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

inline void Read(int &x){
	x=0; char ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
}

int primeSize;
int primeSet[MAX_SIZE];

bool isPrime[MAX_SIZE];

void Euler_Sieve(){
	rep(i,2,MAX_SIZE-5){
		if(!isPrime[i])
			primeSet[++primeSize]=i;
		for(int j=1;i*primeSet[j]<=MAX_SIZE;j++){
			isPrime[i*primeSet[j]]=1;
			if(i%primeSet[j]==0)
				break;
		}
	}
}

int main(){
	Euler_Sieve();
	rep(i,1,primeSize)
		printf("%d ",primeSet[i]);
	return 0;
}
