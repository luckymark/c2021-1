//
// Created by 24962 on 2021/9/20.
//
#include <stdio.h>
#include <malloc.h>

#define length 1000
#define step 5

void encrypt(char *);
void decrypt(char *);

int main(void)
{
    char *p = (char *)malloc(sizeof(char) * length);

    printf("请输入你要加密的字符串：\n");
    scanf("%s", p);
    printf("输入的要加密的字符串为%s\n", p);

    encrypt(p);
    printf("加密后的字符串为：%s\n", p);

    decrypt(p);
    printf("解密后的字符串为：%s\n", p);

    return 0;
}

void encrypt(char *p)
{
    while (*p != '\0')
    {
        *p += step;
        p ++;
    }
}

void decrypt(char *p)
{
    while (*p != '\0')
    {
        *p -= step;
        p++;
    }
}

