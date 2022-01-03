#include <stdio.h>
#include <string.h>
int main()
{
	char a[100];
	char d[100];
	int b,c,i;
	printf("若需要加密，请按1；\n若需要解密，请按其他；\n"); 
	scanf("%d",&b);
	if(b==1){
		printf("请输入明文。\n");
		scanf("%s",&a);
		c=strlen(a);
		for(i=0;i<c;i++){
			d[i]=a[i]+1;
		}
		printf("对应密文为%s\n",d);
	}
	else{
		printf("请输入相应的密文。\n");
		scanf("%s",&a);
		c=strlen(a);
		for(i=0;i<c;i++){
			d[i]=a[i]-1;
		}
		printf("对应明文为%s\n",d);
	}
	return 0; 
}
