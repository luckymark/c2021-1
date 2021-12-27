#include <windows.h>
#include <stdio.h>
char a='a';
int main() {
    int t=0;
    while(t<100){for (int i=0;i<=t;i++){
        printf(" ");
    }
    printf("%c",a);
    t++;
    system("cls");
    }
    while(t>=100&&t<200){for(int j=0;j<200-t;j++){
        printf(" ");
    }
    printf("%c",a);
    t++;
        system("cls");
    }
    return 0;
}
