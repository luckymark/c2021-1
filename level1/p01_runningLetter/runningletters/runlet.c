//
// Created by Durant on 2021/9/14.
//
#include <stdio.h>
#include <windows.h>
#define formation 41//字母跑到屏幕边
#define times 3//来回次数
#define _CRT_SECURE_NO_WARNINGS

int main(void){
    for(int d=0;d<times;d++) {//控制来回次数
        int p = 1;
        for (int b = 0; b < formation; b++) {//跑过去
            int i = p;
            int count = 1;
            while (i > count) {
                printf("   ");
                i--;
            }
            printf("%s", "A");
            system("cls");
            p++;

        }

        for (int b = formation; b > 0; b--) {//跑回来
            int i = p;
            int count = 1;
            while (i > count) {
                printf("   ");
                i--;
            }
            printf("%s", "A");
            system("cls");
            p--;
        }
    }
}
