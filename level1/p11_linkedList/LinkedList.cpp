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

inline void Read(int &x){
	x=0; char ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
}

struct Elem{
	int val;
	Elem* Next;
};

void Reverse();
void Traversal();
Elem* Newp(int X);
void AddToRear(Elem* elem);
int FindValue(int X,int order);
void Conn(Elem* prev,Elem* next);

int Size;
int* Rev_Seq;

Elem* Head;
Elem* Rear;
Elem* Temp;

int main(){
	Head=Rear=Newp(3);
	rep(i,1,60){
		Temp=Newp(i*8);
		AddToRear(Temp);
	}
	Traversal();
	Reverse();
	printf("%d\n",FindValue(5,1));
	printf("%d\n",FindValue(5,1));
	return 0;
}

void Reverse(){
	Elem* nowp=Head;
	if(!Rev_Seq)
		free(Rev_Seq);
	Rev_Seq=(int*)malloc((Size+5)*4);
	rep(i,1,Size)
		Rev_Seq[i]=nowp->val,nowp=nowp->Next;
	nowp=Head;
	for(int i=Size;i>=1;i--)
		nowp->val=Rev_Seq[i],nowp=nowp->Next;
	return;
}

int FindValue(int X,int order){
	int ret=0;
	Elem* nowp=Head;
	while(order){
		ret++;
		if(nowp->val==X)
			order--;
		if(nowp==Rear && order)
			return -1;
		nowp=nowp->Next;
	}
	return ret;
}

void Conn(Elem* prev,Elem* next){
	prev->Next=next;
	return;
}

Elem* Newp(int X){
	Size++;
	Elem* ret=(Elem*)malloc(sizeof(Elem));
	ret->val=X;
	return ret;
}

void AddToRear(Elem* elem){
	Conn(Rear,elem);
	Rear=elem;
	return;
}

void Traversal(){
	Elem* nowp=Head;
	rep(i,1,Size){
		printf("%d ",nowp->val);
		nowp=nowp->Next;
	}
	putchar('\n');
	return;
}
