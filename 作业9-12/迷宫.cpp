#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
int	main() {
    char	maze[10][10] = { "######","#@ #  ","# ## #","#  # #","##   #","#####", };
    int x = 1, y = 1, p = 1, q = 5;
    char ch;
    int i;
    for (i = 0; i <= 5; i++) {
        puts(maze[i]);
    }
    while (x != p || y != q) {
        ch = _getch();
        if (ch == 'd') {
            if (maze[x][y + 1] != '#') {
                maze[x][y] = ' ';
                y++;
                maze[x][y] = '@';
            }
        }
        if (ch == 'a') {
            if (maze[x][y - 1] != '#') {
                maze[x][y] = ' ';
                y--;
                maze[x][y] = '@';
            }
        }
        if (ch == 'w') {
            if (maze[x - 1][y] != '#') {
                maze[x][y] = ' ';
                x--;
                maze[x][y] = '@';
            }
        }
        if (ch == 's') {
            if (maze[x + 1][y] != '#') {
                maze[x][y] = ' ';
                x++;
                maze[x][y] = '@';
            }
        }
        system("cls");
        for (i = 0; i <= 5; i++) {
            puts(maze[i]);
        }
    }
    system("cls");
    printf("YOU WIN!\n");
    Sleep(100);
    return  0;
}
