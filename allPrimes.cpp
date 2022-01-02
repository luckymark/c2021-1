#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;
int main() {
    clock_t Starttime, Endtime;
    Starttime = clock();
    bool tag=true;
    for(int num = 2; num < 1000; num++){
        for(int a = 2; a < sqrt(num)+1; a++) {
            if (num % a == 0 && num!=2) {
                tag = false;
                break;
            }
            else{
                tag = true;
            }
        }
        if(tag == true){
            printf("%d\n",num);
        }
    }
    Endtime = clock();
    printf("Running time is:%lfs\n", (double)(Endtime - Starttime)/CLOCKS_PER_SEC);
    system("pause");
    return 0;
}
