#include <iostream>
#include <stdio.h>
int main() {
    for(int year = 1; year < 200; year++){
        if(year - year/6 - year/12 -year/7 - 9 == year/2&& year%6 == 0 && year%7 == 0&& year%12 == 0&&year%2 == 0){
            printf("Diophantus' age is %d and his son died when he was %d",year,year-4);
            system("pause");
        }
    }
    return 0;
}
