#include <stdio.h>
int main (){
	double number;
	printf("����һ������");
	scanf("%lf",&number) ;
	if (number<=0.0)
	{
		if(number==0.0)
		printf("���������0");
		else
		printf("��������Ǹ���");
		 
	}
	else
	printf("�������������");
	return 0; 
}
