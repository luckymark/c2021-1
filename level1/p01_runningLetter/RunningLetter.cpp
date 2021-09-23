#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define Length 100
#define TIME 100

int main() {
    int n = Length;
    int k = 0;
    int j, m = 0;
    char arr[10];
    printf("ÇëÊäÈëÒª±¼ÅÜµÄ×Ö·û´®£º\n");
    scanf("%s", arr);

    for (int i = 0; i++ <= 2*n; )
    {
        for (j = 0;j <= k; j++)
            printf(" ");
        printf("%s", arr);
        Sleep(TIME);
        system("cls");
        if (m < n)
        {
            m++;
            k = i;
        }
        else
            k--;
    }


    return 0;
}

