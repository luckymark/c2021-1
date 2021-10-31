#include <stdio.h>
#define MAXNUM 100

int isPrime(int num);

int main()
{
    int endJudge = 1;
    for (int num = 4; num <= MAXNUM; num=num+2)
    {
        int middleJudge = 0;
        for (int i = 2; i < num - 1; ++i)
        {
            if (isPrime(i))
            {
                int cha = num -i;
                if (isPrime(cha))
                {
                    middleJudge = 1;
                    break;
                }
            }
        }
        if(middleJudge == 0)
            endJudge = 0;
    }

    if(endJudge)
        printf("Goldbach's conjecture is correct.");
    else
        printf("Goldbach's conjecture is not correct.");
    return 0;

}

int isPrime(int num)
{
    for(int i=2;i*i<=num;i++)
    {
        if (num%i == 0)
            return 0;
    }
    return 1;
}
