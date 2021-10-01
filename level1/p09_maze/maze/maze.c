//
// Created by Durant on 2021/9/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define random(x) (rand()%x)

int main(){
    srand((int) time(NULL));
    printf("%d,%d",random(20),random(20));

    return 0;
}

