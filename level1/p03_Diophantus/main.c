#include<stdio.h>

int main()
{
    double x=1.0;
    for(x=1.0;x<85;x++){
        if(x/6+x/12+x/7+5+x/2+4==x){
            printf("%.0f",x-4);
        }
    }return 0;
}
