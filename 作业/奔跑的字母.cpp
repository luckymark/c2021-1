#define	MAX 110
#include	<stdio.h>
#include	<stdlib.h>
#include	<windows.h>
int	main()
{
	int	a,b;
	a = 1;
	while(1) 
	{
		for(int	i = 0; i <= MAX; i++)
		{
			if(a)	
				b = i;
			else	
				b = MAX - i;
			for(int	c = 0;c <= b;c++)
				printf(" ");
			printf("QH");
			Sleep(10);
			system("cls");
		}
		a += 1;
		a %= 2;
	}	
	return	0;
} 
