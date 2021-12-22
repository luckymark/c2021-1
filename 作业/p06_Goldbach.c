#include <stdio.h>
int main()
{
	int i,j,a,b,m=2,k=0,c=0;
	int isprime[100];
	for(i=2;i<100;i++){
		for(j=1;j<=i;j++){
			if(i%j==0&&i!=j){
				break;
			}
		}
			if(j==i){
				isprime[k]=i;
				k++;
			}
		}
		while(m<100){
			out:
				m=m+2;
				for(a=1;a<k;a++){
					for(b=1;b<k;b++){
						if(m==isprime[a]+isprime[b]){
							goto out;
						}
					}
				}
		    if(a==b&&b==k&&m!=isprime[a]+isprime[b]){
			    printf("哥德巴赫猜想错误。");
			    c++; 
			    break;
		    }
		}
		if(c==0){
			printf("哥德巴赫猜想在100内正确。");
		}
	return 0;
}
