#include <stdio.h>
#define LEVELNUM 64

int move(int level,char mainFrom,char middle,char aim);

int main()
{
    move(LEVELNUM,'A','B','C');
    return 0;
}

int move(int level,char mainFrom,char middle,char aim)
{
    if(level == 0)
        return 0;
    else
    {
        move(level-1,mainFrom,aim,middle);
        printf("%c -> %c\n",mainFrom,aim);
        move(level-1,middle,mainFrom,aim);
        return 0;
    }

}