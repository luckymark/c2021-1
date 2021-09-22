#include<stdio.h>
#include<windows.h>
#define N 1000
int main()
{
    LARGE_INTEGER  t1,t2,tc;
    double time;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceFrequency(&t1);
    int x;
    for(x=2;x<N;x++){
        int i;
        int a=1;
        for(i=2;i<x;i++){
            if(x%i==0){
                a=0;
                break;
            }
        }if(a==1){
            printf("%d\t",x);
        }
    }QueryPerformanceFrequency(&t2);
        time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart;
        printf("%e",time);
    return 0;
}