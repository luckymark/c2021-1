#include<stdio.h>
int main()
{int a;
int b;
int c=0;
scanf("%d",&a);
for(b=2;b<a;b++)
{if(a%b==0){printf("不是素数");
c=1;
break;}
}if(c!=1){printf("是素数");
}
return 0;
}
