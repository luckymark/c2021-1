//
// Created by 24962 on 2021/9/15.
//
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define MAX 1000

int * primes_array(int);
void print_array(int *);

int main(void)
{
    clock_t start, stop;
    double time;

    start = clock();

    int * primes = primes_array(MAX);
    print_array(primes);

    stop = clock();

    time = (double)(stop - start) / CLK_TCK;
    printf("\n运行时间为%lf毫秒", time);

    return 0;
}

int * primes_array(int max)
{
    int * primes = (int *)malloc(sizeof(int) * max);
    int i = 2;
    bool flag = true;

    primes[0] = 2;
    primes[1] = 3;

    for (int j = 4; j <= max; j++)
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
    primes[i] = -1;
    return primes;
}

void print_array(int * primes)
{
    for (int k = 0; primes[k] != -1; k++ )
        printf("%d ", primes[k]);
}

