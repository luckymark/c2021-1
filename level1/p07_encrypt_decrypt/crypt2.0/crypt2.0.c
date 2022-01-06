#include <stdio.h>
#include <string.h>
#include <stdlib.h>

# define LEN 10000

void input(char** p);//保存任意小于10000长度的字符串输入


int rand0(int a);//伪随机数

void encrypt(char *p1);//加密函数

void decrypt(int *p2);//解密函数

int main(void){
    char *pst;
    int ar3[LEN];
    encrypt(pst);
    decrypt(ar3);
    

    return 0;
}

int rand0(int a){
    int b=a*1103515245+12345;
    return (unsigned int) (b/65536)%32768;
}

void encrypt(char *p1){
    printf("请输入要加密的内容：（区分大小写字母，可以包括数字、字母和英文输入状态的符号，空格、回车除外）\n");
    
    input(&p1);
    int length=strlen(p1);
    int *ar2;
    ar2= (int *) malloc ((length+1) * sizeof(int));//字符转ASCII，进行加密计算

    printf("请输入并记住密码（11到999间任意数字）：\n");
    scanf("%d",&ar2[0]);//随机数种子

    int ss=rand0(ar2[0]);//用于四则运算的一个数

    for(int i=0;i<length;i++){
        ar2[i+1]=p1[i]*ss+ss;//加密
    }

    printf("加密结果：\n");
    int count=0;
    for(int i=1;i<length+1;i++){
        printf("%d",ar2[i]);
        if(count<length-1){
            printf(" ");//空格分隔数组元素
        }
        count++;
    }
    printf("\n");

    free(ar2);
}

void decrypt(int ar3[]){
    printf("请逐个数字段（以被空格分开为一段）输入解密内容，第一段为密码。最后输入-1并回车表示结束：\n");
    int count=-1;//计数有多少数字段,除了开头的密码和-1

    for (int i=0;i<LEN;i++){
        scanf("%d",&ar3[i]);
        if (ar3[i]==-1){
            break;
        }
        count++;
    }
    int ss=rand0(ar3[0]);//反向四则远算解密

    char *ar4;
    ar4=(char *) malloc(count * sizeof (char));//保存解密结果

    for(int i=0;i<count;i++){
        ar4[i]=(ar3[i+1]-ss)/ss;
    }

    printf("您的解密结果是：\n");
    for (int i=0;i<count;i++){
    	printf("%c",ar4[i]);
	}

    free(ar4);
}


void input(char** p) {
    char temp[LEN];
    scanf("%s", temp);
    *p = (char*)malloc(strlen(temp) + 1);
    strcpy(*p,temp);

}

