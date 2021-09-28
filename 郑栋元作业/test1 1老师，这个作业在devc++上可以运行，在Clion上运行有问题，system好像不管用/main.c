#include<stdio.h>
#include<stdlib.h>
#include <synchapi.h>
int main()
{
    char a='a';
    int m=0;
    int n=0;
    for (;n<120;n++){
        printf("%*c",n,a);
        m++;
        system ("cls");
        Sleep(10);
    }
    for (;m>0;m--){
        printf("%*c",m,a);
        system ("cls");
        Sleep(10);

    }
    return 0;
}