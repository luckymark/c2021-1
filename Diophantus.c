#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	float i;
	for(i=1;i<200;i++)
	if((i/6+i/12+i/7+5+i/2+4)==i){
	printf("%.0lf",i);
	break;
	}
	return 0;
}