#include <stdio.h>

int main() {
    int b,e,f,g=1,h=0;
    for(b=100;b>=100&&b<1000;b++)
    {
    int d=b;
    h=0;
    while(d>0)
    {
    e=d%10;
    d=d/10;
    for(f=1;f<=3;f++)
    {
    g=g*e;
    }
    h=h+g;
    g=1;
    }
    if(h==b)
    {
    printf("%d ",b);
    }
    }
    return 0;
}
