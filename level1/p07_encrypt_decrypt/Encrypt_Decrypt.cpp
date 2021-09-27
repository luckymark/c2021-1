#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define OFFSET 1
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

int a;
char ch;

void Encrypt(){
	ch=getchar();
	while(ch!='\n' && ch!=EOF){
		putchar(ch+OFFSET);
		ch=getchar();
	}
	return;
}

void Decrypt(){
	ch=getchar();
	while(ch!='\n' && ch!=EOF){
		putchar(ch-OFFSET);
		ch=getchar();
	}
	return;	
}

int main(){
	printf("1 - Encrypt, 2 - Decrypt\n");
	scanf("%d\n",&a);
	if(a==1)
		Encrypt();
	else if(a==2)
		Decrypt();
	return 0;
}
