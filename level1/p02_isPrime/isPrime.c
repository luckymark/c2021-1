#include <stdio.h>
#include <math.h>
int main(void){
    int p;
    scanf("%d",&p);
    int flag =1;//判断标志
    if (p>0){
        for (int i=2;i<=sqrt(p);i++){
            int result=p%i;
            if(result==0){
                flag=0;
            }
        }
        if (flag){
            printf("%d是素数\n",p);
        }else{
            printf("%d不是素数\n",p);
        }
    }else{ printf("数据错误！\n");}
    return 0;
}


