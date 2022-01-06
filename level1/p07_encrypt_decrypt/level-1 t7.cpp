#include<string.h>
#include<math.h>
#include<stdio.h>
//加密：对称后左移 
//解密：右移后对称 
char ori[101],ans[101],req,s;
int len;
void Swap(char &a,char &b){
	char c;
	c=a;
	a=b;
	b=c;
}
int main(){
	req=getchar();
	scanf("%s",&ori);
	len=strlen(ori);
	if(req=='0'){
		for(int i=0;i<=len/2-1;i++)
			Swap(ori[i],ori[len-1-i]);
		s=ori[0];
		for(int i=1;i<=len-1;i++)
			ori[i-1]=ori[i];
		ori[len-1]=s;	
	}
	else{
		s=ori[len-1];
		for(int i=len-1;i>=1;i--)
			ori[i]=ori[i-1];
		ori[0]=s;
		for(int i=0;i<=len/2-1;i++)
			Swap(ori[i],ori[len-1-i]);
	}
	printf("%s",ori);
	return 0;
} 
