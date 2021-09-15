//
// Created by 24962 on 2021/9/13.
//
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void) {
    int n;
    int j;
    bool flag = true;

    printf("请输入你要判断的正整数：\n");
    scanf("%d", &n);
    if (1 == n) {
        printf("%d不是素数！\n", n);
        return 0;
    }

    j = sqrt(n);

    for (int i = 2; i <= j; i++) {
        if (n % i == 0)
            flag = false;
    }

    if (flag)
        printf("%d是素数！", n);
    else
        printf("%d不是素数！", n);

    return 0;
}
