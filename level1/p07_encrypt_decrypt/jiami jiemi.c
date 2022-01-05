#include <stdio.h>

void encrypt(char p[],int length,int mima[])
{
    for(int i=0;i<=length-1;i++)
    {
        mima[i] = p[i] + 3;
        printf("%d\t",mima[i]);
    }
    putchar('\n');
}
void decode(int t[],int length,char jiemima[])
{
    for(int i=0;i<=length-1;i++)
     {
         jiemima[i]=t[i]-3;

     }printf("%s",jiemima);
}
int main() {
    int length;
    printf("please input the length of your words\n");
    scanf("%d",&length);
    char yuanma[length+1];
    printf("please input your words\n");
    scanf("%s",yuanma);

    int mima[length+1];
    encrypt(yuanma, length,mima);

    char jiema[length-1];
    decode(mima,length,jiema);
    



    


    return 0;
}
