#include<iostream>
using namespace std;
int panduan(int x)
{
    int sum=1;
    for (int i=2;i<=x/2+1;i++)
    {
        if (x%i==0)
        {
            sum=0;break;
        }
    }
    if (x==2) return 1;
    if (sum==1) return 1;
    else return 0;
}
int main()
{
    int x,sum=1,sum1=0;
    for (int x=6;x<=100;x++)
    {
        sum=1;
        if (x%2==1)
        {
            for (int i=2;i<=x-3;i++)
                if ((panduan(i)==1)&&(panduan(x-i-3)==1)) { sum=0;break; };
            if (sum==0) sum1++;
        }
        else
        {
            for (int i=2;i<=x-2;i++)
                if ((panduan(i)==1)&&(panduan(x-i-2)==1)) { sum=0;break; };
            if (sum==0) sum1++;
        }
    }
    if (sum1==95) cout<<"ÕıÈ·";
    else cout<<"´íÎó";
    return 0;
}