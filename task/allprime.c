//
// Created by Durant on 2021/9/16.
//
#include <stdio.h>
#include <time.h>
#include <math.h>
int main(void){
    clock_t start,end;
    printf("\t2\t");
    start=clock();
    for(int i=3;i<=1000;i++){
        int judge=1;//判断标志
        if (i%2!=0){//偶数必不是素数
            for(int j=2;j<=sqrt(i);j++){
                if(i%j==0){
                    judge=0;//不是素数
                    break;
                }
            }

        }else{
            continue;
        }
        if (judge){
            printf("%d\t",i);
        }
    }

    end=clock();
    printf("\n打印时间是%lf秒。\n",(double )(end-start)/CLOCKS_PER_SEC);


    return 0;
}
