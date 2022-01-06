#include<iostream>
using namespace std;
void move(char m,char n)
{
    cout<<m<<" ¡ú "<<n<<endl;
}
void hanoi(int n,char a,char b,char c)
{
    if(n==1) move(a,c);
    else
    {
    	hanoi(n-1,a,c,b);
    	move(a,c);
    	hanoi(n-1,b,a,c);
	}  
}
int main()
{
    hanoi(64,'A','B','C');
    return 0;
}


