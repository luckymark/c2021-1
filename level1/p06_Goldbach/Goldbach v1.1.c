//这是第一个版本 还有第二个正在修改中
//写的时候不知道怎么想的  怎么麻烦怎么来
#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100

int isPrime(int num);

int main()
{
    int cnt = 0;
    for(int i = 2;i<=MAXNUM;i++)
    {
        if(isPrime(i))
        ++cnt;
    }
    int * primeArr = malloc(sizeof(int) * cnt);
    if(primeArr == NULL)
        exit(1);
    int primeCnt = 0;
    for(int i = 2;i<MAXNUM;i++)
    {
        if(isPrime(i))
        {
            primeArr[primeCnt] = i;
            ++primeCnt;
        }
    }

    for(int i = 4;i <= MAXNUM;i = i+2)
    {
        int yes = 0;
        for (int j = 0; j < primeCnt; ++j)
        {
            if(i > primeArr[j]-1)
            {
                int cha = i - primeArr[j];
                for (int k = 0; k < primeCnt; ++k)
                {
                    if(cha == primeArr[k])
                    {
                        goto Skip;
                    }

                }
            }
        }
        printf("Goldbach's conjecture is not correct");
        free(primeArr);
        exit(1);
        Skip: 
            continue;
    }

    printf("Goldbach's conjecture is correct");
    free(primeArr);
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
