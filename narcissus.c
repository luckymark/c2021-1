#include<stdio.h>
int main()
{
	int num,a,b,c;
	for(num=100;num<1000;num++)
	{
		a=num/100;
		b=(num%100)/10;
		c=(num%10)/1;
		if(num==a*a*a+b*b*b+c*c*c)
			printf("水仙花数：%d\n",num);
	}
}
