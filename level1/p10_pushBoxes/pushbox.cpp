#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int WIDTH;
int HEIGHT;
// 关卡
int checkpoint = 1;
/**
 *	0	表示空
 *	1	表示墙
 *	2	表示人
 *	3	表示箱子
 *	4	表示球（箱子需要推到的位置）
 *	5	表示推到目的地的箱子
 */
int map[10][10];

//人的位置
int x, y;

//箱子的个数
int boxs;

//声明方法
void createMap();
void initData();
void drawMap();
void move(char direction);

int main(int argc, char* argv[])
{
    char direction; //存储键盘按的方向
    createMap();
    initData();
    // while (1);
    while (1)
    {
        system("cls");
        drawMap();

        if (!boxs)
        {
            if (checkpoint == 3)
            {
                break;
            }
            else
            {
                checkpoint++;
                printf("按任意键进入下一关");
                createMap();
                initData();
            }
        }

        direction = getch();
        move(direction);
    }
    printf("恭喜你完成游戏！※");
    return 0;
}

/**
 * 读取地图
 */
void createMap()
{
    FILE* fp = NULL;
    char path[100];
    sprintf(path, "maze%d.txt", checkpoint);
    fp = fopen(path, "r");
    if (checkpoint == 1)
        WIDTH = HEIGHT = 8;
    else if (checkpoint == 2)
        WIDTH = HEIGHT = 9;
    else if (checkpoint == 3)
    {
        WIDTH = 6;
        HEIGHT = 8;
    }
    int i, j;
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            map[i][j] = fgetc(fp) - '0';
        }
        fgetc(fp);
    }
}
/**
 *	初始化一些必须的数据
 */
void initData()
{
    int i, j;

    // printf("游戏加载中，请稍后.........");

    //获取人的位置
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            //遍历到2时，记录人的左边
            if (map[i][j] == 2)
            {
                x = j;
                y = i;
                map[i][j] = 0;
            }
            //遍历到3时，箱子的数目增加
            if (map[i][j] == 3)
            {
                boxs++;
            }
        }
    }
}

/**
 *	用于在控制台显示地图
 */
void drawMap()
{
    printf("\t第《%d》关\n", checkpoint);
    int i, j;
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (i == y && j == x)
            {
                printf("♀");
                continue;
            }
            switch (map[i][j])
            {
            case 0:
                printf("  ");
                break;
            case 1:
                printf("■");
                break;
            case 2:
                // printf("♀");
                break;
            case 3:
                printf("◆");
                break;
            case 4:
                printf("●");
                break;
            case 5:
                printf("★");
                break;
            }
        }
        printf("\n");
    }
}
/**
 *	用于移动人物
 */
void move(char direction)
{
    // 人物下一步位置
    int next_y = y, next_x = x;
    int dir_y = 0, dir_x = 0;
    switch (direction)
    {
    case 'w':
        dir_y--;
        break;
    case 'a':
        dir_x--;
        break;
    case 's':
        dir_y++;
        break;
    case 'd':
        dir_x++;
        break;
    default:
        return;
    }
    next_y += dir_y;
    next_x += dir_x;

    // 下一步越界
    if (next_y < 0 || next_y > HEIGHT || next_x < 0 || next_x > WIDTH)
    {
        return;
    }

    // 下一步位置为墙
    if (map[next_y][next_x] == 1)
    {
        return;
    }
    // 下一步位置是箱子或已完成方块
    if (map[next_y][next_x] == 3 || map[next_y][next_x] == 5)
    {
        // 箱子或已完成方块的下一步越界
        if (next_y + dir_y < 0 || next_y + dir_y > HEIGHT || next_x + dir_x < 0 || next_x + dir_x > WIDTH)
        {
            return;
        }
        // 箱子或已完成方块的下一步位置为墙或箱子
        if (map[next_y + dir_y][next_x + dir_x] == 1 || map[next_y + dir_y][next_x + dir_x] == 3)
        {
            return;
        }
        // 箱子
        if (map[next_y][next_x] == 3)
        {
            if (map[next_y + dir_y][next_x + dir_x] == 0)
            {
                map[next_y + dir_y][next_x + dir_x] = 3;
                map[next_y][next_x] = 0;
            }
            else if (map[next_y + dir_y][next_x + dir_x] == 4)
            {
                map[next_y + dir_y][next_x + dir_x] = 5;
                map[next_y][next_x] = 0;
                boxs--;
            }
        }
        // 已完成方块
        else if (map[next_y][next_x] == 5)
        {
            if (map[next_y + dir_y][next_x + dir_x] == 0)
            {
                map[next_y + dir_y][next_x + dir_x] = 3;
                map[next_y][next_x] = 4;
                boxs++;
            }
            else if (map[next_y + dir_y][next_x + dir_x] == 4)
            {
                map[next_y + dir_y][next_x + dir_x] = 5;
                map[next_y][next_x] = 4;
            }
        }
    }
    y = next_y;
    x = next_x;
}