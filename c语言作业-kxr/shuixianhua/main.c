#include <stdio.h>
#include<stdlib.h>
int main() {
    for(int i=100;i<=999;i++){
        for(int a=1;a<=10;a++){
            for(int b=1;b<=10;b++){
                for(int c=1;c<=10;c++) {
                    if (i == a * 100 + b * 10 + c&&i==a*a*a+b*b*b+c*c*c)printf("%d\n",i);

                }
            }
        }
    }
    system("pause");
    return 0;
}
