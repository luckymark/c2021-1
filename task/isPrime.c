#include <stdio.h>
#include <math.h>
int main(void){
    int p;
    scanf("%d",&p);
    int flag =1;//�жϱ�־
    if (p>0){
        for (int i=2;i<=sqrt(p);i++){
            int result=p%i;
            if(result==0){
                flag=0;
            }
        }
        if (flag){
            printf("%d������\n",p);
        }else{
            printf("%d��������\n",p);
        }
    }else{ printf("���ݴ���\n");}
    return 0;
}


