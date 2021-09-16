#include<cstring>
#include<iostream>
using namespace std;
bool fl[200];
int boundary=100;
bool check(int n)
{
      for(int i=2;i<=n-1;i++)
      {
          if(fl[i]&&fl[n-i])
              return 1;
      }
      return 0;
}
int main()
{
    memset(fl,true,sizeof(fl));
    fl[1]=false;
    for(int i=2;i<=boundary;i++){
        for(int j=i+i;j<=boundary;j+=i)
            fl[j]= false;
    }
    for(int i=4;i<=boundary;i+=2)
       if(!check(i))
       {
           printf("The idea is worry!");
           fl[0]=false;
           break;
       }
    if(fl[0])
        printf("within 100,the idea is right!");
    return 0;
}