//
// Created by Durant on 2021/9/21.
//
#include <stdio.h>
#include <string.h>
#define MAX 9999

char *s_getsplus(char *st,int n);//自定义输入函数
int list(char a);//把字符换成随机数表的数字

int main(){
    int judge;
    printf("分别输入1,0表示加密，解密：");
    scanf("%d",&judge);

    if (judge){
        printf("\n请输入原始密码(请在英文半角状态输入，可包含大小写英文字母、符号，空格和数字除外,最大容量9999):");
        char save[MAX];
        scanf("%s",save);
        int change1[strlen(save)];
        for (int i=0;i< strlen(save);i++){
            change1[i]=list(save[i]);
        }
        printf("%\n");//测试
        for (int i=0;i< strlen(save);i++){//用户得到经加密的密码
            printf("%d ",change1[i]);//空格加以分隔数字
        }

    }else {
        printf("\n请输入需解密的数字串")
    }
}

char *s_getsplus(char *st,int n){
    char *ret_val;

    ret_val=fgets(st,n,stdin);

    if (ret_val)//ret_val!=NULL
    {
        char *find;
        find=strchr(st,'\n');
        if(find){
            *find='\0';
        }else{
            while (getchar()!='\n'){
                continue;
            }
        }
    }
    return ret_val;
}

int list(char a){
    int out;
    switch (a){
        case 'a':out=41;break;
        case 'b':out=18467;break;
        case 'c':out=6334;break;
        case 'd':out=26500;break;
        case 'e':out=19169;break;
        case 'f':out=15724;break;
        case 'g':out=11478;break;
        case 'h':out=29358;break;
        case 'i':out=26962;break;
        case 'j':out=24464;break;
        case 'k':out=5705;break;

    }
    return out;


}



