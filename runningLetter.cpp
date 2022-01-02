#include <iostream>
#include <stdio.h>
#include <windows.h>
int main() {
    int a,b;
    a = 0;
    while(a < 1000){
        system("cls");
        b = 0;
        while(b < a){
            printf(" ");
          b++;
        }
        printf("HelloWorld!");
        Sleep(1000);
        system("cls");
        a++;
    }
    return 0;
}
