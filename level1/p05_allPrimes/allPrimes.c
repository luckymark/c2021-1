#include <stdio.h>
#include <time.h>


int main() {

    int cnt = 0;
    int judge = 1;

    for (int i = 2; i <= 1000; ++i)
    {
        for(int n=2;n*n<=i;++n)
        {
            if (i%n == 0)
            {
                judge = 0;
                break;
            }
        }
        if(judge)
        {
            printf("%-4d",i);
            ++cnt;
            if (cnt%8 == 0)
                printf("\n");
        }
        judge = 1;
    }
    printf("\nrunning time : %lf s", (double)clock()/CLOCKS_PER_SEC);
}

