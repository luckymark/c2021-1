#include <stdio.h>
#include <string.h>
int main()
{
	char a[100];
	char d[100];
	int b,c,i;
	printf("����Ҫ���ܣ��밴1��\n����Ҫ���ܣ��밴������\n"); 
	scanf("%d",&b);
	if(b==1){
		printf("���������ġ�\n");
		scanf("%s",&a);
		c=strlen(a);
		for(i=0;i<c;i++){
			d[i]=a[i]+1;
		}
		printf("��Ӧ����Ϊ%s\n",d);
	}
	else{
		printf("��������Ӧ�����ġ�\n");
		scanf("%s",&a);
		c=strlen(a);
		for(i=0;i<c;i++){
			d[i]=a[i]-1;
		}
		printf("��Ӧ����Ϊ%s\n",d);
	}
	return 0; 
}
