#include<stdio.h>
#include<math.h>
#include<string.h>
inline int read(){
	char ch;int ans,flag=1;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') flag=-1;
	ans=ch-48;
	while((ch=getchar())>='0'&&ch<='9') ans=(ans<<3)+(ans<<1)+ch-48;
	return ans*flag;
}
inline void write(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
int n,cnt=0;
bool f[20000001];
int prime[10000001];
int main(){
	memset(f+1,20000001,0);
	n=read();
	//n=20000001;
	for(int i=2;i<=n;i++){
		if(f[i]==0) cnt++,prime[cnt]=i;
		for(int j=1;j<=cnt&&(i*prime[j]<=n);j++){
			f[i*prime[j]]=1;
			if(!(i%prime[j])) break;
		}
	}
	
	if(f[n]==0) printf("%d is a prime!",n);
	else        printf("%d is not a prime!",n);
	//19260817 is a prime!!!! 
	return 0;
} 
