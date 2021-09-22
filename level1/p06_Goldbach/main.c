#include<stdio.h>
#define N 100
#define M 25
int main()
{
    int number[M];
    int q=0;
    for(int x=2;x<N;x++){
        int origin=1;
        for(int i=2;i<x;i++){
            if(x%i==0){
                origin=0;
                break;
            }
        }if(origin==1){
            number[q]=x;
            q++;
        }
    }
    int a,b,d,m,n,y;
    int c=5;
    while(c<=N){
        for(n=0;n<=M;n++){
            a=number[n];
            for(y=0;y<=M;y++){
                b=number[y];
                for(m=0;m<=M;m++){
                    d=number[m];
                    if(c==a+b+d){
                        printf("%d=%d+%d+%d\t",c,a,b,d);
                        goto out;
                    }
                }
            }
        }out:c++;
    }
    return 0;
}