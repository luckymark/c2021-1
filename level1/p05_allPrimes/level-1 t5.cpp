#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<windows.h>
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
const int n=1000;
int cnt=0,prime[1001];
bool f[1001];  
int main(){
	memset(f,0,sizeof(f));
	double t1=clock();
	//富强民主文明和谐自由平等公正法治 苟利国家生死以，岂因祸福避趋之 
	for(int i=2;i<=1000;i++){
		if(f[i]==0) {
			cnt++;prime[cnt]=i;
			write(i);putchar('\n');
		}
		for(int j=1;j<=cnt&&(prime[j]*i<=n);j++){
			f[i*prime[j]]=1;
			if(!(i%prime[j])) break;
		}
	}
	putchar('\n');
	double t2=clock();
	printf("%.4lf  %.4lf  %.4lf",t1,t2,t2-t1);
	return 0;
}
