#include <stdio.h>

int main() {
    float life;

    for(life=12;life<1000;life=life+1)
    {
        if((life/6+life/12+life/7+5+life/2+4)==life)
            break;
    }
    printf("age==%.0f",life-4);

    return 0;
}
