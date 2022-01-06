#include<bits\stdc++.h>
int n;
bool isPrime(int n)
{
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}
int main()
{
    scanf("%d",&n);
    if(isPrime(n)) printf("Yes,it is.\n");
    else printf("No,it's not.\n");
    system("pause");
    return 0;
}