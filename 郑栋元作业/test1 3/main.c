#include <stdio.h>
int main()
{
    double x;
    int c=0;

    for (x=0.0;c==0;x++){
        double y=x/2.0;
        double z=x/6.0+x/7.0+x/12.0+5;
        if(z+y+4==x)
        {
            printf("����ͼ�������ǣ�%f\n",x);
            c++;
        }
    }
    return 0;

}