#include <stdio.h>
int main()
{
	int a,i;
	again:
	printf("������һ����������\n");
	scanf("%d",&a);
	if(a<=0){
		printf("���������������������롣\n");
		printf("\n");
		goto again; 
	}
	else{
		for(i=2;i<a;i++){
			if(a%i==0&&a!=i){
				printf("�����ַ�������\n");
				break;
			}
		}
		if(a==i){
			printf("������Ϊ������\n");
		}
	}
	return 0;
}
