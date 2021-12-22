#include <stdio.h>
int main()
{
	int a,i;
	again:
	printf("请输入一个正整数。\n");
	scanf("%d",&a);
	if(a<=0){
		printf("不符合条件，请重新输入。\n");
		printf("\n");
		goto again; 
	}
	else{
		for(i=2;i<a;i++){
			if(a%i==0&&a!=i){
				printf("此数字非素数。\n");
				break;
			}
		}
		if(a==i){
			printf("此数字为素数。\n");
		}
	}
	return 0;
}
