#include <stdio.h>
int main()  
{	int a;
 	int b;
 	int c;
	int i;
	for (i=100;i<1000;i++){
		a=i/100;
		b=(i/10%10);
		c=i%10;
		if(a*a*a+b*b*b+c*c*c==i){
			printf ("%d\n",i);
		}
		
	}
}//��֪��Ϊʲôif����a^3��ʱ����100-999ȫ�������orz 
