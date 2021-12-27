#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define Length 500

int main()
{	
	int a,b=0;
	int present_Length;
	char array[10];
	printf("请输入奔跑的字符串\n");
	scanf("%s",array);
	for (int i = 0; i++ <= 2*Length; )
	{
		for (int a = 0; a <= b; a++) 
		{
			printf(" ");
			printf("%s",array);
			Sleep(100);
			system("cls");
			if (present_Length<Length)
			{
				present_Length++;
				b=i;
			}
			else
				b--;
		}
	}

	return 0;
 } 
