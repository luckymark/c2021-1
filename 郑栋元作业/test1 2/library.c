#include <stdio.h>
int main()
{
    int x;
    int n=2;
    int count=0;
    scanf("%d",&x);
    for(;n<x;n++){
        if(x%n==0){
            count++;
        }
    }
    if(count==0){
        printf("是素数");}
    else
        printf("不是素数");
}
