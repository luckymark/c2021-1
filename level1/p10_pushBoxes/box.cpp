#include<windows.h>
#include<cstring>
#include<stdio.h>
#include<conio.h>
using namespace std;
	char a[20][20]={{"**************"},
					{"**     **    *"},
					{"*   ** **X  **"},
					{"* X  *      **"},
					{"***    *X*O  *"},
					{"*     *  **  *"},
					{"**   ** *** **"},
					{"***         **"},
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
					else if(a[x-1][y]=='X'&& a[x-2][y]==' ')
					{	
						a[x][y]=' ';
						x--;
						a[x][y]='O';
						a[x-1][y]='X';			
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
					else if(a[x][y-1]=='X' && a[x][y-2]==' ')
					{	
						a[x][y]=' ';
						y--;
						a[x][y]='O';
						a[x][y-1]='X';			
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
					else if(a[x+1][y]=='X' && a[x+2][y]==' ')
					{	
						a[x][y]=' ';
						x++;
						a[x][y]='O';
						a[x+1][y]='X';			
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
					else if(a[x][y+1]=='X' && a[x][y+2]==' ')
					{	
						a[x][y]=' ';
						y++;
						a[x][y]='O';
						a[x][y+1]='X';			
					}
				}
			system("CLS");
			for(int i=0;i<=8;++i)
				{
					puts(a[i]);
				}
			if(a[1][3]=='X' && a[1][4]=='X' &&a[1][5]=='X')  break;	
		}
	printf("you win");
	Sleep(1000);
	return 0;
}
