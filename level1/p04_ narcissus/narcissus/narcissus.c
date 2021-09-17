//
// Created by Durant on 2021/9/14.
//
#include <stdio.h>
#include <math.h>
#define mi 3
int main(){
    for (int i=100;i<1000;i++){
        int t=i;
        int first,second,third;
        third=t%10;
        t/=10;
        second=t%10;
        t/=10;
        first=t;


        int result=pow(first,mi)+ pow(second,mi)+pow(third,mi);
        if (result==i){
            printf("%d\t",i);
        }
    }
    return 0;
}
