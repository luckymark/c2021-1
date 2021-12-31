#include<stdio.h>
int myfunc(int n) {
    int a, b, c;
    if (n == (a = n % 10) * a * a + (b = n / 10 % 10) * b * b + (c = n / 100) * c * c)
        return n;
    return 0;
}
int main(void) {
    int i, x;
    for (i = 101; i < 1000; i++)
        if (x = myfunc(i))
            printf("%4d", x);
    printf("\n");
    return 0;
}