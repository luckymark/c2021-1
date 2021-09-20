//
// Created by 24962 on 2021/9/15.
//
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

int main(void)
{
    bool flag = true;
    clock_t start, stop;
    double time;
    
    start = clock();

    for (int i = 2; i <= 1000; i++)
    {
        for (int j = 2; j <= (int)sqrt(i); j++)
        {
            if (i % j == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            printf("%d ", i);
        }
        flag = true;
    }
    
    stop = clock();
    
    time = (double)(stop - start) / CLK_TCK;
    printf("\n运行时间为%lf毫秒", time);
    
    return 0;
}

