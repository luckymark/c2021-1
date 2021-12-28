#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define ROW 25
#define COLUMN 26
void shuru (char shuju[ROW][COLUMN],int *a,int *b);
void shuchu(char shuju[ROW][COLUMN],int *a,int *b);

int main()
{
    int a,b;
    int flag=0;
    char ch,c;
    char shuju[ROW][COLUMN];

    shuru(shuju,&a,&b);
    shuchu(shuju,&a,&b);

    ch=getch();  //conio.h，从控制台读取一个字符，但不显示在屏幕上
    while(1)
    {
        if (ch==0 || ch==0xe0)    //获取方向键
        {
            ch=getch();
            if(ch==72)
            {
                ch='w';
            }
            if(ch==80)
            {
                ch='s';
            }
            if(ch==75)
            {
                ch='a';
            }
            if(ch==77)
            {
                ch='d';
            }
        }
        switch(ch)
        {
            case 'w':
            case 'W':
                if (shuju[a-1][b]=='*'){
                    flag=1;
                }
                else if(shuju[a-1][b]=='3'||shuju[a-1][b]=='6')
                {
                    c=shuju[a-1][b];
                    shuju[a-1][b]=shuju[a][b];
                    shuju[a][b]=c;
                    shuchu(shuju,&a,&b);
                }
                break;
            case 'a':
            case 'A':
                if(shuju[a][b-1]=='*')
                {
                    flag=1;
                }
                if(shuju[a][b-1]=='3'||shuju[a][b-1]=='6')
                {
                    c=shuju[a][b-1];
                    shuju[a][b-1]=shuju[a][b];
                    shuju[a][b]=c;
                    shuchu(shuju,&a,&b);
                }
                break;
            case 's':
            case 'S':
                if(shuju[a+1][b]=='*')
                {
                    flag=1;
                }
                if(shuju[a+1][b]=='3'||shuju[a+1][b]=='6')
                {
                    c=shuju[a+1][b];
                    shuju[a+1][b]=shuju[a][b];
                    shuju[a][b]=c;
                    shuchu(shuju,&a,&b);
                }
                break;
            case 'd':
            case 'D':
                if(shuju[a][b+1]=='*')
                {
                    flag=1;
                }
                if(shuju[a][b+1]=='3'||shuju[a][b+1]=='6')
                {
                    c=shuju[a][b+1];
                    shuju[a][b+1]=shuju[a][b];
                    shuju[a][b]=c;
                    shuchu(shuju,&a,&b);
                }
                break;
        }
        if (shuju[22][24]=='2')
        {
            printf("你已成功逃出迷宫！\n");
            break;
        }
        if(flag)
        {
            printf("你已死亡！\n");
            break;
        }
        ch=getch();
    }
    return 0;
}

void shuru(char shuju[ROW][COLUMN],int *a,int *b)
{
    int i=0;
    int j=0;

    FILE*fp;
    char ch;
    
    if((fp=fopen("maze.txt","r"))==NULL)
    {
        printf("文件路径不正确！");
        exit(1);
    }
    ch=fgetc(fp);
    while(ch!=EOF)
    {
        if(ch=='2')
        {
            shuju[i][j]=ch;
            *a=i;
            *b=j;
            j++;
            if(j==COLUMN)
            {
                i++;
                j=0;
            }
        }
        else
        {
            shuju[i][j]=ch;
            j++;
            if(j==COLUMN)
            {
                i++;
                j=0;
            }
        }
        ch=fgetc(fp);
    }
    fclose(fp);
}

void shuchu(char shuju[ROW][COLUMN],int *a,int *b)
{
    int i,j;
    system("cls");
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COLUMN;j++)
        {
            if(shuju[i][j]=='1')
            {
                printf("▓ ");
            }
            else if (shuju[i][j]=='2')
            {
                printf("♀");
                *a=i;
                *b=j;
            }
            else if(shuju[i][j]=='3')
            {
                printf("  ");
            }
            else if (shuju[i][j]=='4')
            {
                printf("卐");
            }
            else if (shuju[i][j]=='5')
            {
                printf("卍");
            }
            else if (shuju[i][j]=='6')
            {
                printf("o ");
            }
            else if(shuju[i][j]=='*'){
                printf("◎");
            }
        }
        printf("\n");
    }
    printf("          W:向上移动    S:向下移动                \n"
        "          A:向左移动    D:向右移动                \n"
        "          向o 处逃生!触碰◎ 则死亡!\n");
}
