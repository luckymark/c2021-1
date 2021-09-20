//
// Created by 24962 on 2021/9/15.
//
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define MAX 1000

int main(void)
{
    int primes[MAX] = {2, 3};
    int i = 2;
    bool flag = true;
    clock_t start, stop;
    double time;
    
    start = clock();

    for (int j = 4; j <= MAX; j++)
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
        
    stop = clock();
    
    time = (double)(stop - start) / CLK_TCK;
    printf("\n运行时间为%lf毫秒", time);
    
    return 0;
}

