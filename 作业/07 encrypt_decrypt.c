#include<stdio.h>
#include<string.h>
#define MAXIUM 9999
void puzzle(char* origin, int length)
{
    for (int i = 0; i < length; i++)
    {
        origin[i]++;
    }
    printf("加密后密文为%s", origin);
}
void answer(char* origin, int length)
{
    for (int i = 0; i < length; i++)
    {
        origin[i]--;
    }
    printf("解密后明文为%s", origin);
}
int main()
{
    char origin[MAXIUM];
    int ks = 0;
    printf("请选择要进行加密还是解密（1加密，其余解密）：");
    scanf_s("%d", &ks);
    getchar();
    printf("请输入要加密或解密的文字\n");
    gets(origin);
    int length = strlen(origin);
    if (ks == 1)
    {
        puzzle(origin, length);
    }
    else
    {
        answer(origin, length);
    }
    return 0;
}
