#include <stdio.h>
#include "maze.h"
int main() {
    int SIZE = 0;
    printf("请输入迷宫大小:");
    scanf_s("%d", &SIZE);
    SIZE = SIZE + (SIZE % 2 + 1)%2;
     while (SIZE < 5) {
        printf("太小了，换一个大一点的数字吧！\n");
        printf("请输入迷宫大小:");
        scanf_s("%d", &SIZE);
    }
    pMaze pmaze = creatMaze(SIZE);
    play(pmaze, SIZE);
    return 0;
}
