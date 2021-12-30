#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int from=100,to=999,a,b,c;
int main()
{
      for(int i=from;i<=to;i++)
      {
            a=i/100;
            b=(i/10)%10;
            c=i%10;
            if(pow((double) a,3)+ pow((double) b,3)+ pow((double) c,3)==i)
                printf("%d  " , i);
      }
      return 0;
}