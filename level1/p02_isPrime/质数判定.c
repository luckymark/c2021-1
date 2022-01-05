#include <stdio.h>

int main() {
    int a,i;

    printf("please 输入\n");
    scanf("%d",&a);

    for(i=2;i<=a-1;i++)
    {
       if(a%i==0)
           break;}
    if(i<a-1)
        printf("%d is heshu\n ",a);
    else
        printf("%d is zhishu\n",a);
    return 0;
}
