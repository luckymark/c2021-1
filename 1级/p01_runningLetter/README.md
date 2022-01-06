### 题目：奔跑的字母

### 功能要求：

1. 在console上输出一个字母（或单词）
1. 使该字母或单词，按一定速度从左至右运动
1. 当遇到屏幕边界时反向运动

#include<string.h>
#include<math.h>
#include<stdio.h>
#include<windows.h>
int cnt=1,flag=1;
int n=5000;
const int right=40;
char c[40];
void pre(){
    printf("%s",c);system("CLS");cnt=1;
}
int main(){
    scanf("%s",&c);
//	printf("\b");
    pre();
    while(n--){
        for(int i=1;i<=cnt;i++) putchar(' ');
        printf("%s",c);
        system("CLS");
        if(cnt==0)
            flag=1,pre();
        if(cnt==right)
            flag=-1;
        cnt+=flag;
    }
    return 0;
}



