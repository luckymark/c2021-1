#include<stdio.h>
int judge(float i);
int main(){
	float i;
	int ret;
	for (i=20;i<200;i++){
		if(judge(i)){
			ret=(int)i;
			break;
		}
	}
	printf("¶ù×ÓËÀÊ±¶ª·¬Í¼%dËê",ret-4);
	return 0;
}
int judge (float i){
	int ret=0;
	if(i-4.0-(1/6.0*i+1/12.0*i+1/7.0*i+5.0)==1/2.0*i){
		ret=1;
	}
	return ret;
}
