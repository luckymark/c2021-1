//±¼ÅÜµÄ×ÖÄ¸
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main()
{
    int a, b;
    a = 1;
    while (a<=100)
    {
        b = 1;
        system("cls");
        while (b <= a)
        {
            printf(" ");
            b++;

        }
        printf("H");
        Sleep(100);
        a++;
        
        while (a >= 0) {
            system("cls");
            b = 1;
            while (b <= a) {
                printf(" ");
                b++;
            }
            printf("H");
            Sleep(100);
            a--;

        }


    }
    return 0;
}