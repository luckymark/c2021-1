#include<iostream>
using namespace std;
int n,tb=0;
int main()
{
      cin>>n;
      for(int i=2;i<=n-1;i++)
          if(n%i==0)
          {
              tb=1;
              cout<<"This isn't a prime";
              break;
          }
      if(tb==0)
          cout<<"This is a prime";
      return 0;
}