#include<stdio.h>
#include<string.h>
int	main(){
	int	count=0,i,q=1;
	char	text[128]={'\0'};
	char	code[128]={'\0'};
	while(1){
		if(q==1){
			printf("��������:%s\n",text);
			scanf("%s",&text);
			 count=strlen(text);
			for(i=0;i<count;i++){
				code[i]=text[i]+i+5;
			}
			code[i]='\0';
			printf("���ģ�%s\n",code);
		}
		else	if(q==2){
			count=strlen(text);
			for(i=0;i<count;i++){
				text[i]=code[i]-i-5;
			}
			text[i]='\0';
			printf("����:%s",text);
		}
		printf("����1���ܣ�����2����\n"); 
		scanf("%d",&q);
	}
	return	0;
}
