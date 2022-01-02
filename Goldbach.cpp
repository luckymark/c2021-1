#include <iostream>
#include <stdio.h>
int main() {
    int a = 4;
    for(int a = 4; a < 100; a ++){
        if(a % 2 == 0){
            for (int b = 2; b < 100; b++) {
                bool tag1 = true;
                bool tag2 = true;
                for (int test = 2; test < sqrt(b) + 1; test++) {
                    if (b % test == 0 && b != 2) {
                        tag2 = false;
                        break;
                    } else {
                        tag2 = true;
                    }
                }
                int c = a - b;
                for (int test = 2; test < sqrt(c) + 1; test++) {
                    if (c % test == 0 && c != 2) {
                        tag1 = false;
                        break;
                    } else {
                        tag1 = true;
                    }
                }
                if (tag1 == true && tag2 == true && c > 1) {
                    printf("%d=%d+%d\n", a, b, c );
                }
            }
        }
    }
    return 0;
}