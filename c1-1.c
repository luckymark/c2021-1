#include <stdio.h>
int main (){
	double number;
	printf("输入一个数字");
	scanf("%lf",&number) ;
	if (number<=0.0)
	{
		if(number==0.0)
		printf("你输入的是0");
		else
		printf("你输入的是负数");
		 
	}
	else
	printf("你输入的是正数");
	return 0; 
}
