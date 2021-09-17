//
// Created by 24962 on 2021/9/15.
//
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void)
{
    bool flag = true;

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
}

