#include<windows.h>
#include<cstring>
#include<stdio.h>
#include<conio.h>
using namespace std;
	char a[20][20]={{"**************"},
					{"**     **  ***"},
					{"*   ** ** ****"},
					{"  * **    ****"},
					{"***   ****O  *"},
					{"**  ***  **  *"},
					{"**   ** *** **"},
					{"****        **"},
					{"**************"}};
					
int main()
{
	char ch;
	int x,y;
	x=4;
	y=10;
	for(int i=0;i<=8;++i)
		{
			puts(a[i]);
		}
	while(1)
		{
			ch=getch();
			if(ch=='w')
				{
					if(a[x-1][y]==' ')
					{
						a[x][y]=' ';
						x--;
						a[x][y]='O';
					}
					
					
				}
			else if(ch=='a')
				{
					if(a[x][y-1]==' ')
					{
						a[x][y]=' ';
						y--;
						a[x][y]='O';
					}
				}
			else if(ch=='s')
				{
					if(a[x+1][y]==' ')
					{
						a[x][y]=' ';
						x++;
						a[x][y]='O';
					}
				}
			else if(ch=='d')
				{
					if(a[x][y+1]==' ')
					{
						a[x][y]=' ';
						y++;
						a[x][y]='O';
					}
				}
			system("CLS");
			for(int i=0;i<=8;++i)
				{
					puts(a[i]);
				}
			if(x==3 && y==0)  break;
				
		}
	printf("you win");
	Sleep(1000);
	return 0;					
 } 
