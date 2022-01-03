#include <stdio.h>
int main()
{
	double i,j;
	for(i=1.0;i<200.0;i++){
		j=(1.0/4+1.0/7)*i;
		if(j+9==0.5*i)
		{
			printf("¶ª·¬Í¼Îª%dËê",(int)i);
		}
	}
	return 0;
} 
