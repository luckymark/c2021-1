#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define LEN 7

void move(int* x, int* y, int* ispass, int* islose, int* map);
void mapchoose(int* map, int* number);
void mapprint(int* map, int* cnt);
void addpoint(int* number, int* cnt);

int main()
{
    int cnt = 0, ispass = 0, islose = 0;
    int x = 1, y = 1;
    int map[LEN + 2][LEN + 2];
    int number=0;

    mapchoose(&map[0][0],&number);
    do
    {
        mapprint(&map[0][0],&cnt);
        move(&x, &y, &ispass, &islose, &map[0][0]);
        cnt++;
    } while (ispass == 0 && islose == 0);
    
    system("cls");
    if (ispass) addpoint(&number, &cnt);
    if (ispass)printf("VICTORY!\n");
    if (islose)printf("DEFALT!\n");
    return 0;
}

void move(int* x, int* y, int* ispass, int* islose, int* map)
{
    int xx = 0, yy = 0;
    int rightinput = 0;

    int key;
    do
    {
        key = _getch();
        switch (key)
        {
        case 0XE0:
            switch (key = _getch())
            {
            case 72:
                xx = -1;
                rightinput = 1;
                break;//上
            case 80:
                xx = 1;
                rightinput = 1;
                break;//下
            case 75:
                yy = -1;
                rightinput = 1;
                break;//左
            case 77:
                yy = 1;
                rightinput = 1;
                break;//右
            default: break;
            }
            break;
        case 'l':
        case 'L':
            *islose = 1;
            rightinput = 1;
            break;
        default:break;
        }
    } while (!rightinput);

    if (*(map + (*x + xx) * (LEN + 2) + (*y + yy)) == 0)
    {

    }
    else if (*(map + (*x + xx) * (LEN + 2) + (*y + yy)) == 1)
    {
        *(map + (*x + xx) * (LEN + 2) + (*y + yy)) = 5;
        if (*(map + (*x) * (LEN + 2) + (*y)) != 8)
        {
            *(map + (*x) * (LEN + 2) + (*y)) = 1;
        }
        *x += xx;
        *y += yy;
    }
    else if (*(map + (*x + xx) * (LEN + 2) + (*y + yy)) == 8)
    {
        *(map + (*x) * (LEN + 2) + (*y)) = 1;
        *x += xx;
        *y += yy;
    }
    else if (*(map + (*x + xx) * (LEN + 2) + (*y + yy)) == 2)
    {
        if ((*(map + (*x + 2 * xx) * (LEN + 2) + (*y + 2 * yy)) == 1))
        {
            *(map + (*x + 2 * xx) * (LEN + 2) + (*y + 2 * yy)) = 2;
            *(map + (*x + xx) * (LEN + 2) + (*y + yy)) = 5;
            *(map + (*x) * (LEN + 2) + (*y)) = 1;
            *x += xx;
            *y += yy;
        }
        else if ((*(map + (*x + 2 * xx) * (LEN + 2) + (*y + 2 * yy)) == 8))
        {
            *ispass = 1;
        }
    }
}

void mapchoose(int* map, int* number)
{
    int mapnumber;
    FILE* file = NULL;
    errno_t err=1;
    printf("Which map do you want to play ?\n");
    printf("There are 3 maps in total .\n");
    do
    {
        scanf_s("%d", &mapnumber);
    } while (!(mapnumber >= 1 && mapnumber <= 3));
    switch (mapnumber)
    {
    case 1:err = fopen_s(&file, "map1.txt", "r"); break;
    case 2:err = fopen_s(&file, "map2.txt", "r"); break;
    case 3:err = fopen_s(&file, "map3.txt", "r"); break;
    default:break;
    }
    if (err)
    {
        printf("文件打开错误！\n");
    }
    else
    {
        for (int i = 0; i < LEN + 2; i++)
        {
            for (int j = 0; j < LEN + 2; j++)
            {
                char c;
                do
                {
                    c = fgetc(file);
                } while (c < '0' || c > '9');
                {
                    *(map + i * (LEN + 2) + j) = c - '0';
                }
                //printf("%d", *(map + i * (LEN + 2) + j));
            }
            printf("\n");
        }
        fclose(file);
    }
    *number = mapnumber;
}

void mapprint(int* map, int *cnt)
{
    system("cls");
    for (int i = 0; i < LEN + 2; i++)
    {
        for (int j = 0; j < LEN + 2; j++)
        {
            switch (*(map + i * (LEN + 2) + j))
            {
            case(0):printf("+"); break;
            case(1):printf(" "); break;
            case(2):printf("%%"); break;
            case(5):printf("@"); break;
            case(8):printf("*"); break;
            default:break;
            }
        }
        printf("\n");
    }
    printf("你已经走了%d步\n", *cnt);
    printf("按L键结束游戏\n");
}

void addpoint(int* number, int* cnt)
{
    FILE* file = NULL;
    errno_t err=1;
    //printf("%d\n", *number);
    switch (*number)
    {
    case 1:err = fopen_s(&file, "map1.txt", "a+"); break;
    case 2:err = fopen_s(&file, "map2.txt", "a+"); break;
    case 3:err = fopen_s(&file, "map3.txt", "a+"); break;
    default:break;
    }
    if (err)
    {
        printf("文件打开错误！\n");
    }
    else
    {
        fprintf(file, "\n%d", *cnt);
        //printf("here\n");
        fclose(file);
    }
}