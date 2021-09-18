#include<stdio.h> 
#include<math.h>
int main(){
	int r[10]={0};
	int k=0;
	for(int i=1;i<10;i++){
		for(int m=0;m<10;m++){
			for (int n=0;n<10;n++){
				int ret=i*100+m*10+n;
				if (ret==pow(i,3)+pow(m,3)+pow(n,3)){
						r[k++]=ret;
					}
			}
		}
	}
	k=0;
	while(r[k]!=0){
		printf("%d\t",r[k++]);
	}
	return 0;
}
