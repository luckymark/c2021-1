#include<stdio.h>
#include<math.h>
#include<string.h>
void write(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
int a[4];
bool check(int x){
	a[1]=x%10,a[2]=(x/10)%10,a[3]=x/100;
	int sum=0;
	for(int i=1;i<=3;i++) sum+=a[i]*a[i]*a[i];
	if(sum==x) return 1;
	return 0;
}
int main(){
	for(int i=100;i<=999;i++){
		if(check(i)) write(i),putchar('\n');
	}
	return 0;
} 
