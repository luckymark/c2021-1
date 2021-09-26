//Created by 日比谷ななお、2021，9，26
#include<stdio.h>
#include<string.h>
void move(char x, char y);
void suki(int n, char a, char b, char c)
{
    if (n == 1)move(a, c);
    else
    {
        suki(n - 1, a, c, b);
        move(a, c);
        suki(n - 1, b, a, c);
    }
}
void move(char x, char y)
{
    printf("%c-->>%c\n", x, y);
}
int main()
{
    const int N = 64;
    suki(N, 'A', 'B', 'C');
    return 0;
}
