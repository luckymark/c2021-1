#include<stdio.h>
#include<stdlib.h>
#define HIGH 17
#define WIDE 17
int map[HIGH][WIDE]={
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
        {1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1},
        {1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1},
};void print() {
    int i,j;
    for ( i = 0; i < HIGH; i++) {
        for ( j = 0; j < WIDE; j++) {
            if (map[i][j] == 0) {
                printf("  ");
            } else if (map[i][j] == 1) {
                printf("¡ù");
            } else if (map[i][j] == 2) {
                printf("¡â");
            } else if (map[i][j] == 3) {
                printf("³ö");
            }
        }
        printf("\n");
    }
}
int x,y;
void up(){
    if(map[x-1][y]==0){
        map[x-1][y]=2;
        map[x][y]=0;
        x--;
    }
}
void down(){
    if(map[x+1][y]==0||map[x+1][y]==3){
        map[x+1][y]=2;
        map[x][y]=0;
        x++;
    }
}
void left(){
    if(map[x][y-1]==0){
        map[x][y-1]=2;
        map[x][y]=0;
        y--;
    }
}
void right(){
    if(map[x][y+1]==0){
        map[x][y+1]=2;
        map[x][y]=0;
        y++;
    }
}
int main() {
    x=1;
    y=1;
    int direction;
    while (1) {
        system("cls");
        print();
        if (x == 16 && y == 15) {
            map[x][y] = 0;
            break;
        }
        direction=getchar();
        switch (direction) {
            case 72:
                up();
                break;
            case 80:
                down();
                break;
            case 75:
                left();
                break;
            case 77:
                right();
                break;
        }}
    printf("¹§Ï²Í¨¹Ø£¡");
    return 0;
}