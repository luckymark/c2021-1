#include<stdio.h>
#include<string.h>
int	main(){
	int	count=0,i,q=1;
	char	text[128]={'\0'};
	char	code[128]={'\0'};
	while(1){
		if(q==1){
			printf("输入明文:%s\n",text);
			scanf("%s",&text);
			 count=strlen(text);
			for(i=0;i<count;i++){
				code[i]=text[i]+i+5;
			}
			code[i]='\0';
			printf("密文：%s\n",code);
		}
		else	if(q==2){
			count=strlen(text);
			for(i=0;i<count;i++){
				text[i]=code[i]-i-5;
			}
			text[i]='\0';
			printf("明文:%s",text);
		}
		printf("输入1加密，输入2解密\n"); 
		scanf("%d",&q);
	}
	return	0;
}
