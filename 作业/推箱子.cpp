#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h> 
using namespace std;

char a[10][10],end[10][10]={0},m[10];
int score=0;

void map(){
	int i=0;
	FILE *fp;
	fp=fopen("map1.txt","r");//文件打开地图 
	while(fgets(m,100,fp)!=NULL)
	{
		for(int j=0;j<10;j++)
			a[i][j]=m[j];
		i++;
	}
	fclose(fp);
}

void draw(){
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			switch(a[i][j])
			{
				case '0':cout<<"  ";break;//可走 
				case '1':cout<<"■";break;//墙壁 
				case '2':cout<<"▲";break;//人 
				case '3':cout<<"**";break;//终点 
				case '4':cout<<"□";break;//箱子 
			}
		}
		cout<<"\n";
	}
}

void move()
{
	int x,y; 
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		{
			if(a[i][j]=='2')//找小人位置
			{
				x=i;
				y=j;
			}
			if(a[i][j]=='3')//记录终点位置
				end[i][j]='3'; 
		}
	char k;
	k=getch();//读入移动 
	score++;
	//判断移动 
	switch(k) 
	{
		case 'W':
		case 'w':
			if((a[x-1][y]=='0'&&end[x][y]!='3')||a[x-1][y]=='3')
			{
				a[x-1][y]='2';
				a[x][y]='0';
			}
			else if(a[x-1][y]=='0'&&end[x][y]=='3')
			{
				a[x-1][y]='2';
				a[x][y]='3';
			}
			else if(a[x-1][y]=='4')
			{
				if(a[x-2][y]=='0'||a[x-2][y]=='3')
				{
					a[x-1][y]='2';
					a[x][y]='0';
					a[x-2][y]='4';
				}
			}
			break;
		case 'A':
		case 'a':
			if((a[x][y-1]=='0'&&end[x][y]!='3')||a[x][y-1]=='3')
			{
				a[x][y-1]='2';
				a[x][y]='0';
			}
			else if(a[x][y-1]=='0'&&end[x][y]=='3')
			{
				a[x][y-1]='2';
				a[x][y]='3';
			}
			else if(a[x][y-1]=='4')
			{
				if(a[x][y-2]=='0'||a[x][y-2]=='3')
				{
					a[x][y-1]='2';
					a[x][y]='0';
					a[x][y-2]='4';
				}
			}
			break;
		case 'S':
		case 's':
			if((a[x+1][y]=='0'&&end[x][y]!='3')||a[x+1][y]=='3')
			{
				a[x+1][y]='2';
				a[x][y]='0';
			}
			else if(a[x+1][y]=='0'&&end[x][y]=='3')
			{
				a[x+1][y]='2';
				a[x][y]='3';
			}
			else if(a[x+1][y]=='4')
			{
				if(a[x+2][y]=='0'||a[x+2][y]=='3')
				{
					a[x+1][y]='2';
					a[x][y]='0';
					a[x+2][y]='4';
				}
			}
			break;
		case 'D':
		case 'd':
			if((a[x][y+1]=='0'&&end[x][y]!='3')||a[x][y+1]=='3')
			{
				a[x][y+1]='2';
				a[x][y]='0';
			}
			else if(a[x][y+1]=='0'&&end[x][y]=='3')
			{
				a[x][y+1]='2';
				a[x][y]='3';
			}
			else if(a[x][y+1]=='4')
			{
				if(a[x][y+2]=='0'||a[x][y+2]=='3')
				{
					a[x][y+1]='2';
					a[x][y]='0';
					a[x][y+2]='4';
				}
			}
			break;
	}
	system("cls");
}

void pass()//判断通关 
{
	int b=0;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		{
			if(a[i][j]=='4'&&end[i][j]=='3')
				end[i][j]='0';
			else if(end[i][j]=='3'&&a[i][j]!='4')
					b++;
		}
	if(b==0)
	{
		system("cls");
		cout<<"恭喜你通关!!!"<<endl;
		cout<<"您一共用了"<<score<<"步!!!"; 
		exit(0);
	}
}

int main()
{
	printf("用WASD控制小▲,注意无效步数也计入步数中\n开始游戏");
	system("pause"); 
	system("cls");
	map();//读入地图
	while(1){
		draw();//打出地图
		move();
		pass();
	}
	return 0;
}
