#include <stdio.h>
#include "maze.h"
int main() {
    int SIZE = 0;
    printf("�������Թ���С:");
    scanf_s("%d", &SIZE);
    SIZE = SIZE + (SIZE % 2 + 1)%2;
     while (SIZE < 5) {
        printf("̫С�ˣ���һ����һ������ְɣ�\n");
        printf("�������Թ���С:");
        scanf_s("%d", &SIZE);
    }
    pMaze pmaze = creatMaze(SIZE);
    play(pmaze, SIZE);
    return 0;
}
