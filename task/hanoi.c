//
// Created by Durant on 2021/9/20.
//
//想不出来，代码从网上抄的，递归打开新世界大门
#include <stdio.h>
void hanoi(int n,char x,char y,char z);
void move(char x,char y);

int main(void){
    int n;//汉诺塔层数
    printf("请输入汉诺塔层数：");
    scanf("%d",&n);
    hanoi(n,'A','B','C');//从左到右依次编号柱子为A,B,C
    return 0;

}

void hanoi(int n,char x,char y,char z){
    if (n==1){
        move(x,z);//递归截止条件
    }else{
        hanoi(n-1,x,z,y);//第n-1个移到B柱子
        move(x,z);//第n个移到C柱子
        hanoi(n-1,y,x,z);//第n-1个移到到C柱子


    }
}

void move(char x,char y){
    printf("%c-->%c\n",x,y);
}