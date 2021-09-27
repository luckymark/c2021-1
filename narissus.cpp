#include <iostream>
#include <stdio.h>
int main() {
    for(int num = 100; num < 999; num++){
        int fir = num/100;
        int sec = (num - fir*100)/10;
        int thi = num - fir*100 - sec*10;
        if(num == fir*fir*fir+sec*sec*sec+thi*thi*thi){
            printf("%d\n",num);
        }
    }
}
