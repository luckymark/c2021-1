#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define LEN 7
void move(int* x, int* y, int* ispass, int* map);
void prin(int a);
int main()
{
    int cnt = 0, ispass = 0;
    int x = 1, y = 1;
    int map[LEN + 2][LEN + 2] =
    {
        0,0,0,0,0,0,0,0,0,
        0,5,1,1,0,1,1,1,0,
        0,0,0,1,0,0,0,1,0,
        0,0,0,1,1,1,1,1,0,
        0,1,1,1,0,0,0,0,0,
        0,1,0,1,0,1,1,1,0,
        0,1,0,1,0,1,0,1,0,
        0,1,0,1,1,1,0,1,8,
        0,0,0,0,0,0,0,0,0
    };
    while (ispass == 0)
    {
        system("cls");
        for (int i = 0; i < LEN + 2; i++)
        {
            for (int j = 0; j < LEN + 2; j++)
            {
                prin(map[i][j]);
            }
            printf("\n");
        }
        printf("你已经走了%d步\n", cnt);
        move(&x, &y, &ispass, &map[0][0]);
        cnt++;
    }
    system("cls");
    printf("CONGRATULATIONS!\n");
    return 0;
}

void move(int* x, int* y, int* ispass, int* map)
{
    int xx = 0, yy = 0;

    int key;
    key = _getch();
    switch (key)
    {
    case 0xE0:
        switch (key = _getch())
        {
        case 72:
            xx = -1;
            break;//上
        case 80:
            xx = 1;
            break;//下
        case 75:
            yy = -1;
            break;//左
        case 77:
            yy = 1;
            break;//右
        default: break;
        }break;
    }

    if (*(map + (*x + xx) * (LEN + 2) + (*y + yy)) == 8)
    {
        *ispass = 1;
    }
    else if (*(map + (*x + xx) * (LEN + 2) + (*y + yy)) == 0)
    {

    }
    else if (*(map + (*x + xx) * (LEN + 2) + (*y + yy)) == 1)
    {
        *(map + (*x + xx) * (LEN + 2) + (*y + yy)) = 5;
        *(map + (*x) * (LEN + 2) + (*y)) = 1;
        *x += xx;
        *y += yy;
    }
}

void prin(int a)
{
    switch (a)
    {
    case(0):printf("+"); break;
    case(1):printf(" "); break;
    case(5):printf("@"); break;
    case(8):printf("*"); break;
    default:break;
    }
}