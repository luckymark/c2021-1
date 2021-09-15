#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int Maxn=1000;
bool fl[1000];
int main()
{
    memset(fl,false,sizeof(fl));
      for(int i=2;i<=Maxn;i++)
    {
        if (!fl[i]) printf("%d  ", i);
        for (int j = i + i; j <= Maxn ;
        j += i)
        fl[j] = true;
    }
      return 0;
}