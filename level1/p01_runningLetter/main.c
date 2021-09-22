#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define N 120
int main()
{
    char c;
    scanf("%c",&c);
    for(int n=0;n<N;n++){
        printf(" %*c",n,c);
        system("cls");
        Sleep(10);
    }for(int m=N;m>0;m--){
        printf("%*c",m,c);
        system("cls");
        Sleep(10);
    }return 0;
}