#include <stdio.h>

int main() {
    int number;
    int i;
    int a = 1;
    scanf("%d", &number);
    for (i = 2; i < number; i++) {
        if (number % i == 0) {
            a = 0;
            printf("%d不是素数", number);
            break;
        }
    }
    if (a == 1) {
        printf("%d是素数?", number);
    }
    return 0;
}