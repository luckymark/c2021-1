#include<iostream>
using namespace std;
string choice,origin;
int len,fu;
char now;
int deal=(14*22*23*28+11*22);
void encrypt()
{
      for(int i=0;i<len;i++)
      {
            now=origin[i];
            fu=((int)now+deal);
            printf("%d  ",fu);
      }
}
void decrypt()
{
      int m=0;
      for(int i=0;i<len;i++)
      {
            if(origin[i]!=' '){
                m=m*10+(int)origin[i]-48;
                continue;
            }
            else {
                m -= deal;
                printf("%c", (char) m);
                m=0;
            }
      }
}
int main()
{
     string scan;
     cin>>choice;
     origin.clear();
     while(1)
     {
           cin>>scan;
           if(scan=="finished")
               break;
           origin+=scan;
           origin+=' ';
     }
//     cout<<origin;
     len=origin.size();
     if(choice=="encrypt")
         encrypt();
     else
         decrypt();
     return 0;
}