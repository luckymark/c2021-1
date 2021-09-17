//
// Created by 24962 on 2021/9/15.
//
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void)
{
    int primes[500] = {2, 3};
    int i = 2;
    bool flag = true;

    for (int j = 4; j <= 1000; j++)
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

    for (int k = 0; k < i; k++ )
        printf("%d ", primes[k]);
}

