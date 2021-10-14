#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define MAX_SIZE 105
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

bool isPrime[MAX_SIZE];

int primeCnt;
int primeSet[MAX_SIZE];

void Euler_Sieve(){
	rep(i,2,MAX_SIZE){
		if(!isPrime[i]) primeSet[++primeCnt]=i;
		for(int j=1;i*primeSet[j]<=MAX_SIZE;j++){
			isPrime[i*primeSet[j]]=1;
			if(i%primeSet[j]==0)
				break;
		}
	}
	return;
}

bool Valid(int X){
	for(int i=1;i<=primeCnt && primeSet[i]<=X;i++)
		for(int j=1;j<=primeCnt && primeSet[i]+primeSet[j]<=X;j++)
			if(!isPrime[X-primeSet[i]-primeSet[j]])
				return true;
	return false;
}

int main(){
	Euler_Sieve();
	rep(i,5,MAX_SIZE-5)
		printf("%d:%s\n",i,Valid(i)?"True":"False");
	return 0;
}

