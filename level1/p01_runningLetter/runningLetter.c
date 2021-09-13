#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>


int main()
{
    int speed = 0;
    printf("Please input a speed.(1-1000)\n");
    if(!(scanf("%d",&speed) && speed>0 && speed<1001))
    {
        printf("goodbye!");
        exit(1);
    }



    int sleepSpeed = 1000/speed;
    for (int i = 0; i <= 80; i++)
    {

        printf("w\b\b ");

	    Sleep(sleepSpeed);
	    printf("w");
	    Sleep(sleepSpeed);
	}
    for (int i = 0; i <= 80; i++)
	{
        Sleep(sleepSpeed*2);
        printf("\b \b\bw");
    }

    return 0;

}