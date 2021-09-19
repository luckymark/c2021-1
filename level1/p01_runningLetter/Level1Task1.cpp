#include<bits\stdc++.h>
#define MAX_LENGTH 110
using namespace std;
int main()
{
    int i=0;
    bool flag=true;
    while(i<=MAX_LENGTH)
    {
        if(flag) i++;
        else i--;
        if(i==MAX_LENGTH) flag=false;
        for(int j=0;j<=i;j++) printf(" ");
        printf("A");
        if(i==-1) break;
        system("CLS");
    }
    system("pause");
    return 0;
}