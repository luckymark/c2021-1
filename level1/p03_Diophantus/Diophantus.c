//
// Created by 24962 on 2021/9/15.
//
#include <stdio.h>

int main(void)
{
    int i = 8;

    while (i%7 != 0 || i%12 != 0 || (i - i/6 - i/12 - i/7 - 5 - 4) != i/2)
        i++;
    printf("儿子死时丢番图的年龄为%d。", i - 4);
}
