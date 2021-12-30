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
	fp=fopen("map1.txt","r");//�ļ��򿪵�ͼ 
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
				case '0':cout<<"  ";break;//���� 
				case '1':cout<<"��";break;//ǽ�� 
				case '2':cout<<"��";break;//�� 
				case '3':cout<<"**";break;//�յ� 
				case '4':cout<<"��";break;//���� 
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
			if(a[i][j]=='2')//��С��λ��
			{
				x=i;
				y=j;
			}
			if(a[i][j]=='3')//��¼�յ�λ��
				end[i][j]='3'; 
		}
	char k;
	k=getch();//�����ƶ� 
	score++;
	//�ж��ƶ� 
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

void pass()//�ж�ͨ�� 
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
		cout<<"��ϲ��ͨ��!!!"<<endl;
		cout<<"��һ������"<<score<<"��!!!"; 
		exit(0);
	}
}

int main()
{
	printf("��WASD����С��,ע����Ч����Ҳ���벽����\n��ʼ��Ϸ");
	system("pause"); 
	system("cls");
	map();//�����ͼ
	while(1){
		draw();//�����ͼ
		move();
		pass();
	}
	return 0;
}
