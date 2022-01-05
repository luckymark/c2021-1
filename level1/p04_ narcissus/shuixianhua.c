#include <stdio.h>
#include <math.h>
int main() {
    int a,b1,b2,b3;
    for(a=100;a<=999;a++)
    {
        b1=a/100;
        b2=(a/10)%10;
        b3=a-100*b1-10*b2;
        if(a==pow(b1,3)+pow(b2,3)+pow(b3,3))
        {
            printf("%d\n",a);
        }

    }

    return 0;
}
