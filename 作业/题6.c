#include<stdio.h>
int main()
{int a,b,c;
int d=0;
int num[200];
for(a=2;a<=100;a++)
	{d++;
	for(b=2;b<a;b++)
		{c=0;
		if(a%b==0)	
			{c=1;
			break;
			}
		}if(c==0)
			{num[d]=a;
			}
	}	
int i,j,e,f;
int g=0; 
for(e=4;e<=100;e+=2)
{f=0;
for(i=1;i<=100;i++)
	{if(f==1)
		{break;
		}
	for(j=1;j<=100;j++)
		{if(num[i]+num[j]==e)
			{f=1;
			g++;
			break;
			}
		}
	}
}
if(g==49){printf("����һ����\n����5����������3����һ������2��ż������Ͻ���һ�����۶�������");}
return 0;}
	
	











