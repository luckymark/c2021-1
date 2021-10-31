#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
    loop:int a = 0, b;
    while (a <= 119)
    {
        system("cls");
        b = 1;
        while (b <= a)
        {
            printf(" ");
            b++;
        }
        printf("H");
        Sleep(10);
        a++;
    }
    while (a >= 0)
    {
        system("cls");
        b = 1;
        while (b <= a)
        {
            printf(" ");
            b++;
        }
        printf("H");
        Sleep(10);
        a--;
    }
    goto loop;
}
