#include <stdio.h>

#define PLATE_TOTAL 64

void hanoi(int n,char a,char b,char c);
void move(char a,char c);

int main()
{
    hanoi(PLATE_TOTAL,'A','B','C');
}

void hanoi(int n,char a,char b,char c)
{
    if(n==1){
        move(a,c);
    }else{
        hanoi(n-1,a,c,b);
        move(a,c);
        hanoi(n-1,b,a,c);
    }
}

void move (char a,char c)
{
    printf("%c->%c\n",a,c);
}