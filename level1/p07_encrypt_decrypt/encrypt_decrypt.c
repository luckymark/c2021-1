#include<stdio.h>
#include<string.h>
#include<stdlib.h>

# define MAX_LEN 100 /*可输入的最长字符串长度*/
# define KEY 2       /*密钥*/
int flag=1;
void encrypt(char*p);
void decrypt(char*p);

int main(){
    char a[MAX_LEN];
    scanf("%100s",a);
    encrypt(a);
    if(flag)
    {
        printf("%s\n",a);
    }
    else
    {
        printf("请输入英文/数字\n");
        exit(1);
    }
    decrypt(a);
    printf("%s\n",a);
    return 0;
}

void encrypt(char*p)
{
    int len=strlen(p);
    for (int i=0;i<len;i++)
    {
        if(p[i]>='0' && p[i]<='9')
        {
            p[i]=(p[i]-'0'+KEY)%('9'-'0'+1)+'0';
        }
        else if(p[i]>='a' && p[i]<='z')
        {
            p[i]=(p[i]-'a'+KEY)%('z'-'a'+1)+'a';
        }
        else if(p[i]>='A' && p[i]<='Z')
        {
            p[i]=(p[i]-'A'+KEY)%('Z'-'A'+1)+'A';
        }
        else
        {
            flag=0;
        }
    }
}

void decrypt(char*p)
{
    int len=strlen(p);
    for (int i=0;i<len;i++){
        if(p[i]>='0' && p[i]<='9')
        {
            p[i]=(p[i]-'0'-KEY+'9'-'0'+1)%('9'-'0'+1)+'0';
        }
        else if(p[i]>='a' && p[i]<='z')
        {
            p[i]=(p[i]-'a'-KEY+'z'-'a'+1)%('z'-'a'+1)+'a';
        }
        else if(p[i]>='A' && p[i]<='Z')
        {
            p[i]=(p[i]-'A'-KEY+'Z'-'A'+1)%('Z'-'A'+1)+'A';
        }
    }
}