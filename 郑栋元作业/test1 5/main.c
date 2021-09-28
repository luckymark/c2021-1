#include <stdio.h>
#include <time.h>
int main()
{	clock_t t1,t2;
    t1=clock();
    const int maxNumber=300;
    int prime[maxNumber];
    int i;
    int x;
    for (i=0;i<maxNumber;i++)
    {
        prime[i]=1;
    }


    for(x=2;x<maxNumber;x++){
        if(prime[x])
        {
            for(i=2;i*x<maxNumber;i++)
            {
                prime[i*x]=0;
            }
        }


    }
    for(i=2;i<maxNumber;i++)
    {
        if(prime[i])
        {
            printf("%d\t",i);
        }

    }
    printf("\n");
    t2=clock();
    printf("所用时间：%e",t2-t1);

}