#include <stdio.h>
#include <time.h>

int main() {
    int i,a,b,c;
    b=0;c=0;
    for(i=2;i<=1000;i++)
    {
        for(a=2;a<i;a++)
        {
            if(i%a==0)
           {b++;
            break;}
        }
        if(b==c)
        {printf("%d\n",i);
        } else{c++;}
    }
    printf("the time cost is %f ms",(float)clock());

    return 0;
}
