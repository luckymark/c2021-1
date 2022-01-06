//
// Created by Durant on 2021/9/16.
//
#include <stdio.h>
#include <math.h>
#define MAX 100
void isprime(int* ISPRIME[MAX]);//2到MAX的素数表
int main(void){
    int ISPRIME[MAX];
    isprime(ISPRIME);
    int judge;//判断猜想是否正确的标志
    for(int i=3;i<=MAX;i++){//接下来用循环加以验真。
        judge=0;//假设猜想错误，每个数都要进行验真

        // 大于2的偶数是两个素数的和
        if (i%2==0){
            for(int a=0;a<MAX;a++){//两个循环找素数的和满足猜想
                for(int b=0;b<MAX;b++){
                    if(ISPRIME[a]+ISPRIME[b]==i){
                        judge=1;//猜想在i处成立
                        break;
                    }

                }
                if (judge){//验真后立即跳出两个循环
                        break;
                }
            }
        }

        //大于5的素数等于三个素数的和
        if(i%2!=0 && i>5){
            for (int a=0;a<MAX;a++){
                for (int b=0;b<MAX;b++){
                    for (int c=0;c<MAX;c++){
                        if(ISPRIME[a]+ISPRIME[b]+ISPRIME[c]==i){
                            judge=1;
                            goto loop;//验真后跳出三个循环,至50行的判断
                        }
                    }
                }
            }
        }
        //为保持循环完整性，不属于猜想的数3,5在此判断为真，以保证后面结论的正确性
        if(i==3 || i==5){
            judge=1;
        }

        //判断：对于数i猜想是否正确
        loop:if(judge){
            continue;
        }else {
            printf("哥德巴赫猜想对%d不成立\n",i);
            break;
        }
    }

    //结束全部的循环后仍为真
    if(judge==1){
        printf("哥德巴赫猜想在2到MAX范围内成立\n");
    }

    return 0;

}
void isprime(int* ISPRIME[MAX]){
    ISPRIME[0]=2;//特殊的素数
    int count=1;//数组下标
    for (int i=3;i<MAX;i++){
        int flag=1;//判断标志


        if(i%2!=0){//偶数除2不属于素数
            for(int j=2;j<=sqrt(i);j++){//判断素数的循环
                if (i%j==0){
                    flag=0;//不是素数
                    break;
                }else {continue;}
            }
            if(flag){//判断素数，是则写入数组
                ISPRIME[count]=i;
                count++;
            }
        }
    }
}