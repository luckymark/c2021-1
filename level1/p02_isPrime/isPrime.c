#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int getNum();
int judgePrime(int);


int main()
{
    int num = getNum();
    if(num<2)
    {
        printf("%d is not a prime.",num);
        return(0);
    }
    if(judgePrime(num))
        printf("%d is a prime.",num);
    else
        printf("%d is not a prime.",num);

    return 0;

}

int getNum()
{
    int Input;
    char fll;
    printf("Please input a number.\n");
    while(!scanf("%d",&Input))
    {
        printf("error:please in put a number!\n");
        while((fll=getchar()) != '\n' && fll != EOF);
    }
    return Input;
}

int judgePrime(int num)
{
    for(int i=2;i<=num/2;i++)
    {
        if (num%i == 0)
            return 0;
    }
    return 1;
}