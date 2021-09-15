#include<bits/stdc++.h>  
#include<windows.h>
using namespace std;
string s;
int cnt=0,k,bj;
int main()
{
	  cin>>bj;
	  cin>>s;
	  system("cls");
	  k=1;
	  while(cnt!=-1)
	  {
	  	  for(int j=1;j<=cnt;j++)
	  	    cout<<" ";
	  	  cout<<s;
	  	  Sleep(50); 
	      system("cls");
	      if(cnt==bj)
	        k=-1;
	      cnt+=k;
	  }
	  return 0;
}
