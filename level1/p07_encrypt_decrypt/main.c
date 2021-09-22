#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main() {
    int a = 1;
    int i;
    int count = 0;
    char password[256] = {'\0'};
    char encrypt[256] = {'\0'};

    while (1)
    {
        if (a == 1)
        {
            printf("请输出密码：\n");
            scanf("%s", &password);
            count = strlen(password);
            for (i = 0; i < count; i++)
            {
                encrypt[i] = password[i] + i + 2;
            }
            encrypt[i] = '\0';
            printf("加密后是:%s\n", encrypt);
        }
        else if (a == 2)
        {
            count = strlen(password);
            for (i = 0; i < count; i++)
            {
                password[i] = encrypt[i] - i - 2;
            }
            password[i] = '\0';
            printf("解密后是：%s\n", password);
        }
        else if (a == 3)
        {
            break;
        }
        else
        {
            printf("请按提示输入：\n");
        }

        printf("输入1加密，输入2进行解密，输入3退出程序：\n");
        printf("请按提示输入：\n");
        scanf("%d",&a);
    }

    return 0;
}
