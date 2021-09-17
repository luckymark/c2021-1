//
// Created by 24962 on 2021/9/15.
//
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int primes[100] = {2, 3};
    int i = 2;
    bool flag = true;

    for (int j = 4; j <= 100; j++)
    {
        for (int k = 0; k < i; k++)
        {
            if(j % primes[k] == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            primes[i++] = j;
        }
        flag = true;
    }

    for (int j = 4; j <= 100; j += 2)
    {
        for (int k = 0; k < i; k++)
        {
            for (int n = 0; n < i; n++)
            {
                if(j == primes[k] + primes[n])
                    printf("%d = %d + %d\n", j, primes[k], primes[n]);
            }
        }
    }
}