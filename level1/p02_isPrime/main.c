#include <stdio.h>

int main() {
    int number;
    int i;
    int a = 1;
    scanf("%d", &number);
    for (i = 2; i < number; i++) {
        if (number % i == 0) {
            a = 0;
            printf("%d��������", number);
            break;
        }
    }
    if (a == 1) {
        printf("%d������?", number);
    }
    return 0;
}