#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
	while(1){
	
    int a=0,b;
    while(a<=30)
    {
    
    b=1;
    while(b<=a)
    {
    printf(" ");
    b++;
    }
    printf("Z");
    Sleep(200);
    a++;
    system("cls");
    }
    while(a>=0)
    {
    b=1;
    while(b<=a)
    {
    printf(" ");
    b++;
    }
    printf("Z");
    Sleep(200);
    system("cls");
    a--;
    
	}}
    return 0;
}
