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

    printf("��������Ҫ���ܵ��ַ�����\n");
    scanf("%s", p);
    printf("�����Ҫ���ܵ��ַ���Ϊ%s\n", p);

    encrypt(p);
    printf("���ܺ���ַ���Ϊ��%s\n", p);

    decrypt(p);
    printf("���ܺ���ַ���Ϊ��%s\n", p);

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

