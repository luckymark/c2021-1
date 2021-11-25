//
// Created by 24962 on 2021/9/17.
//
#include <stdio.h>

#define LENGTH  64

void hanoi(int, char, char, char);
void move(int i, char, char, char);

int main(void)
{
    int i = LENGTH;
    char a = 'A';
    char b = 'B';
    char c = 'C';

    hanoi(i, a, b, c);

    return 0;
}

void hanoi(int i, char a, char b, char c)
{
    if (i == 1)
    {
        move(i, a, b, c);
        return;
    }

    hanoi(i - 1, a, c, b);
    move(1, a, b, c);
    hanoi(i - 1, b, a, c);

}

void move (int i, char a, char b, char c)
{
    if (i == 1)
    {
        printf("%c---->%c\n", a, c);
        return;
    }

    printf("%c---->%c, %c---->%c, %c---->%c\n", a, b, a, c, b, c);

    return;
}
