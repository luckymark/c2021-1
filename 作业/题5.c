#include<stdio.h>
int main()

{int a,b,c;

for(a=2;a<=1000;a++)
	{for(b=2;b<a;b++)
		{c=0;
		if(a%b==0)	
			{c=1;
			break;
			}
		}if(c==0)
			{printf("%d ",a);
			}
	}return 0;
}
