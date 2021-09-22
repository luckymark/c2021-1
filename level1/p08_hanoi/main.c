#include <stdio.h>
#define N 64
void move(int x,int y)
{
    printf("%d--->%d\t",x,y);
}
void transport(int n,int a,int b,int c)
{
    if(n==1){
        move(a,c);
    }else{
        transport((n-1),a,c,b);
        move(a,c);
        transport((n-1),b,a,c);
    }
}
int main()
{
    transport(N,1,2,3);
    return 0;
}