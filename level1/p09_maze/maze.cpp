#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;
int a[13][13]={
	{0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,2,1,1,0,0,0,0,0,0,0,1,1},
    {0,0,0,0,0,1,0,1,1,1,0,0,1},
	{0,1,1,1,1,0,1,1,1,0,0,1,1},
    {0,0,0,0,0,0,0,0,1,1,0,0,1},
    {0,0,1,0,1,1,1,0,0,0,0,1,1},
    {0,0,1,0,1,1,1,1,1,1,1,1,1},
    {0,0,1,1,0,0,0,0,0,0,1,1,1},
    {0,0,0,0,0,1,1,1,1,0,1,1,1},
    {0,1,0,1,1,1,0,0,0,0,1,1,1},
    {0,1,0,1,1,0,0,1,1,1,1,1,1},
    {0,1,0,1,1,0,0,0,0,0,0,0,0},
    {0,1,0,1,1,1,1,1,1,1,1,1,-1},
};
char n;
int x1=1,x2=1,sum=0;
void start()
{
        cout<<"这是12*12的迷宫"<<endl;
        cout<<"#号是墙体,空格是可行的路线"<<endl;
        cout<<"右下角的Q是终点";
        cout<<"按A,S,D,W控制小人'T'移动"<<endl;
		system("pause");
        system("cls");
}
int end(int x,int y)
{
	if ((x==12)&&(y==12)) return 1;
	else return 0;
}
void draw()
{
	for (int i=1;i<13;i++)
	{
		for (int j=1;j<13;j++)
		{
			switch (a[i][j])
			{
				case -1:cout<<"Q";
						break;
				case 0 :cout<<" ";
					    break;
				case 1 :cout<<"#";
						break;
				case 2 :cout<<"T";
						break;
			}
		}
		cout<<endl;
	}
}
void move(char c)
{
	if (c=='A')
	{
		if ((a[x1][x2-1]==1)||(x2-1<1)) cout<<"error"<<endl<<"restart";
		else 
		{
			a[x1][x2-1]=2;a[x1][x2]=0;
			x2--;
		}
	}
	if (c=='S')
	{
		if ((a[x1+1][x2]==1)||(x1+1>12)) cout<<"error"<<endl<<"restart";
		else 
		{
			a[x1+1][x2]=2;a[x1][x2]=0;
			x1++;
		}
	}
	if (c=='D')
	{
		if ((a[x1][x2+1]==1)||(x2+1>12)) cout<<"error"<<endl<<"restart";
		else 
		{
			a[x1][x2+1]=2;a[x1][x2]=0;
			x2++;
		}
	}
	if (c=='W')
	{
		if ((a[x1-1][x2]==1)||(x1-1<1)) cout<<"error"<<endl<<"restart";
		else 
		{
			a[x1-1][x2]=2;a[x1][x2]=0;
			x1--;
		}
	}
	system("cls");
	if (end(x1,x2)==1) cout<<"恭喜你到达了终点!"<<endl;
	else draw();
}
int main()
{
	cout<<"--------------------------"<<endl;
    start();
	draw();
    while(1)
	{
		n=getchar();
		cin.get();
		system("cls");
		move(n);
		if (end(x1,x2)==1) 
		{
			break;
		}
	}
    return 0;
}