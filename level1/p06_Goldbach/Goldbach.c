#include<stdio.h>
#define PRIME_MAX 100
#define NUMBER_MAX 100

int prime_total=0;
int prime[100]={2};

int isPrime (int i);
void print(int t);

int main()
{
    for(int i=3;i<PRIME_MAX;i+=2){
        if (isPrime(i)){
            prime[++prime_total]=i;
        }
    }

    for (int i=5;i<NUMBER_MAX;i++){
        print(i);
    }

    return 0;
}

int isPrime(int i){
    int ret=1;
    for(int t=2;t<i;t++){
        if(i%t==0){
            ret=0;
            break;
        }
    }
    return ret;
}

void print(int t){
    
    for(int x=0;x<prime_total;x++){
        for(int y=0;y<prime_total;y++){
            for(int z=0;z<prime_total;z++){
                if(t==prime[x]+prime[y]+prime[z]){
                    printf("%d = %d+%d+%d\n",t,prime[x],prime[y],prime[z]);
                    goto out;
                }
                if(prime[z]>=t){
                    break;
                }
            }
            if(prime[y]>=t){
                break;
            }
        }
        
    }
    out:;
    
}