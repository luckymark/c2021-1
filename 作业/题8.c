#include<stdio.h>
int main()
{int n;
int d[3]={'a','b','c'};
scanf ("%d",&n);
g(n,d[0],d[1],d[2]);
return 0;}
g(int h,int l,int m,int o)
{if(h==1)
{printf ("%c-->%c ",l,m);}
else{g(h-1,l,m,o);
printf ("%c-->%c ",l,o);
g(h-1,m,o,l);
}
} 
