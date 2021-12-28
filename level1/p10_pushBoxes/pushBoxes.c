#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int row;
int col;   //最后一个数用于存储'\n'
int a,b;//记录人的坐标

void shuru (char shuju[][col],int level,int *boxNum);
void shuchu(char shuju[][col]);
void move(char shuju[][col],int *pboxFni,int *pstep);
void scoreRecord(int level,int step);

int main()
{
    
    
    	
    int level;
    int step=0;
    int boxNum=0;
    int boxFni=0;//boxFnished到达目标点的箱子数

    printf("请输入您要玩的的关卡(1~5关):");
    scanf("%d",&level);
    switch(level)
    {
        case 1:
            row=10;
            col=14;
            break;
        case 2:
            row=8;
            col=9;
            break;
        case 3:
            row=10;
            col=12;
            break;
        case 4:
            row=11;
            col=11;
            break;
        case 5:
            row=11;
            col=14;
            break;
    }
    char shuju[row][col];
    
    shuru(shuju,level,&boxNum);
    shuchu(shuju);

    while(1)
    {
        move(shuju,&boxFni,&step);
        if(boxFni==boxNum){
            printf("你已成功通过游戏，所用步长：%d",step);
            scoreRecord(level,step);
            break;
        }
        else{
            printf("当前步数：%d",step);
        }
    }
    system("pause");
    return 0;
}

void shuru(char shuju[][col],int level,int *pboxNum)
{
    int i=0;
    int j=0;

    FILE*fp;
    char ch;
    
    switch (level)
    {
        case 1:
            fp=fopen("pushBoxes1.txt","r");
            break;
        case 2:
            fp=fopen("pushBoxes2.txt","r");
            break;
        case 3:
            fp=fopen("pushBoxes3.txt","r");
            break;
        case 4:
            fp=fopen("pushBoxes4.txt","r");
            break;
        case 5:
            fp=fopen("pushBoxes5.txt","r");
            break;
    }
    if(fp==NULL)
    {
        printf("文件路径不正确！");
        exit(1);
    }
    ch=fgetc(fp);
    while(ch!=EOF)
    {
            shuju[i][j]=ch;
            if (ch=='2')
            {
                a=i;
                b=j;
            }
            else if(ch=='6')
            {
                (*pboxNum)++;
            }
            j++;
            if(j==col)
            {
                i++;
                j=0;
            }
        ch=fgetc(fp);
    }
    fclose(fp);
}

void shuchu(char shuju[][col])
{
    int i,j;
    system("cls");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(shuju[i][j]=='1')
            {
                printf("□");
            }
            else if (shuju[i][j]=='2')
            {
                printf("♀");
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
                printf("¤");   //目标点
            }
            else if(shuju[i][j]=='*'){
                printf("■");   //箱子
            }
            else if(shuju[i][j]=='7'){
                printf("★");      //人物和目标点重合的图案
            }else if(shuju[i][j]=='8'){
                printf("☆");     //箱子进入目标点后的图案
            }
        }
        printf("\n");
    }
    printf("W:向上移动    S:向下移动\n"
        "A:向左移动    D:向右移动\n"
		"或者输入方向键\n"
		"把所有的箱子□移动到目标点¤即可通关");
}

void move(char shuju[][col],int *pboxFni,int *pstep)
{
    unsigned char ch=getch();
    if (ch==0 || ch==0xe0)    //获取方向键
    {
        ch=getch();
        if(ch==72)  ch='w';
        if(ch==80)  ch='s';
        if(ch==75)  ch='a';
        if(ch==77)  ch='d';
    }
    switch(ch)      //箱子碰到目标点后无法移动
    {
        case 'w':
        case 'W':
            //人碰到了箱子
            if(shuju[a-1][b]=='*')
            {
                //箱子碰到了道路
                if(shuju[a-2][b]=='3')  
                {
                    shuju[a-2][b]='*';
                    shuju[a-1][b]='2';
                    if(shuju[a][b]=='2')
                        shuju[a][b]='3';
                    else if(shuju[a][b]=='7')
                        shuju[a][b]='6';
                    a--;
                    (*pstep)++;
                }
                //箱子碰到了目标点
                else if(shuju[a-2][b]=='6')
                {
                    shuju[a-2][b]='8';
                    shuju[a-1][b]='2';
                    if(shuju[a][b]=='2')
                        shuju[a][b]='3';
                    else if(shuju[a][b]=='7')
                        shuju[a][b]='6';
                    (*pboxFni)++;
                    a--;
                    (*pstep)++;
                }
                
            }
            //人碰到了在目标点的箱子
            else if (shuju[a-1][b]=='8')    
            {
                //箱子碰到道路
                if(shuju[a-2][b]=='3')
                {
                    shuju[a-2][b]='*';
                    shuju[a-1][b]='7';
                    if(shuju[a][b]=='2')
                        shuju[a][b]='3';
                    else if(shuju[a][b]=='7')
                        shuju[a][b]='6';
                    (*pboxFni)--;
                    a--;
                    (*pstep)++;
                }
                //箱子碰到目标点
                else if(shuju[a-2][b]=='6')
                {
                    shuju[a-2][b]='8';
                    shuju[a-1][b]='7';
                    if(shuju[a][b]=='2')
                        shuju[a][b]='3';
                    else if(shuju[a][b]=='7')
                        shuju[a][b]='6';
                    a--;
                    (*pstep)++;
                }
                
            }
            //人碰到了道路
            else if(shuju[a-1][b]=='3')
            {
                shuju[a-1][b]='2';
                if(shuju[a][b]=='2')
                    shuju[a][b]='3';
                else if(shuju[a][b]=='7')
                    shuju[a][b]='6';
                a--;
                (*pstep)++;
            }
            //人碰到目标点
            else if(shuju[a-1][b]=='6')
            {
                shuju[a-1][b]='7';
                if(shuju[a][b]=='2')
                    shuju[a][b]='3';
                else if(shuju[a][b]=='7')
                    shuju[a][b]='6';
                a--;
                (*pstep)++;
            }
            shuchu(shuju);
            break;
        case 'a':
        case 'A':
            //人碰到了箱子
            if(shuju[a][b-1]=='*')
            {
                //箱子碰到了道路
                if(shuju[a][b-2]=='3')  
                {
                    shuju[a][b-2]='*';
                    shuju[a][b-1]='2';
                    if(shuju[a][b]=='2')
                        shuju[a][b]='3';
                    else if(shuju[a][b]=='7')
                        shuju[a][b]='6';
                    b--;
                    (*pstep)++;
                }
                //箱子碰到了目标点
                else if(shuju[a][b-2]=='6')
                {
                    shuju[a][b-2]='8';
                    shuju[a][b-1]='2';
                    if(shuju[a][b]=='2')
                        shuju[a][b]='3';
                    else if(shuju[a][b]=='7')
                        shuju[a][b]='6';
                    (*pboxFni)++;
                    b--;
                    (*pstep)++;
                }
                
            }
            //人碰到了在目标点的箱子
            else if (shuju[a][b-1]=='8')    
            {
                //箱子碰到道路
                if(shuju[a][b-2]=='3')
                {
                    shuju[a][b-2]='*';
                    shuju[a][b-1]='7';
                    if(shuju[a][b]=='2')
                        shuju[a][b]='3';
                    else if(shuju[a][b]=='7')
                        shuju[a][b]='6';
                    (*pboxFni)--;
                    b--;
                    (*pstep)++;
                }
                //箱子碰到目标点
                else if(shuju[a][b-2]=='6')
                {
                    shuju[a][b-2]='8';
                    shuju[a][b-1]='7';
                    if(shuju[a][b]=='2')
                        shuju[a][b]='3';
                    else if(shuju[a][b]=='7')
                        shuju[a][b]='6';
                    b--;
                    (*pstep)++;
                }
                
            }
            //人碰到了道路
            else if(shuju[a][b-1]=='3')
            {
                shuju[a][b-1]='2';
                if(shuju[a][b]=='2')
                    shuju[a][b]='3';
                else if(shuju[a][b]=='7')
                    shuju[a][b]='6';
                b--;
                (*pstep)++;
            }
            //人碰到目标点
            else if(shuju[a][b-1]=='6')
            {
                shuju[a][b-1]='7';
                if(shuju[a][b]=='2')
                    shuju[a][b]='3';
                else if(shuju[a][b]=='7')
                    shuju[a][b]='6';
                b--;
                (*pstep)++;
            }
            shuchu(shuju);
            break;
        case 's':
        case 'S':
            //人碰到了箱子
            if(shuju[a+1][b]=='*')
            {
                //箱子碰到了道路
                if(shuju[a+2][b]=='3')  
                {
                    shuju[a+2][b]='*';
                    shuju[a+1][b]='2';
                    if(shuju[a][b]=='2')
                        shuju[a][b]='3';
                    else if(shuju[a][b]=='7')
                        shuju[a][b]='6';
                    a++;
                    (*pstep)++;
                }
                //箱子碰到了目标点
                else if(shuju[a+2][b]=='6')
                {
                    shuju[a+2][b]='8';
                    shuju[a+1][b]='2';
                    if(shuju[a][b]=='2')
                        shuju[a][b]='3';
                    else if(shuju[a][b]=='7')
                        shuju[a][b]='6';
                    (*pboxFni)++;
                    a++;
                    (*pstep)++;
                }
                
            }
            //人碰到了在目标点的箱子
            else if (shuju[a+1][b]=='8')    
            {
                //箱子碰到道路
                if(shuju[a+2][b]=='3')
                {
                    shuju[a+2][b]='*';
                    shuju[a+1][b]='7';
                    if(shuju[a][b]=='2')
                        shuju[a][b]='3';
                    else if(shuju[a][b]=='7')
                        shuju[a][b]='6';
                    (*pboxFni)--;
                    a++;
                    (*pstep)++;
                }
                //箱子碰到目标点
                else if(shuju[a+2][b]=='6')
                {
                    shuju[a+2][b]='8';
                    shuju[a+1][b]='7';
                    if(shuju[a][b]=='2')
                        shuju[a][b]='3';
                    else if(shuju[a][b]=='7')
                        shuju[a][b]='6';
                    a++;
                    (*pstep)++;
                }
                
            }
            //人碰到了道路
            else if(shuju[a+1][b]=='3')
            {
                shuju[a+1][b]='2';
                if(shuju[a][b]=='2')
                    shuju[a][b]='3';
                else if(shuju[a][b]=='7')
                    shuju[a][b]='6';
                a++;
                (*pstep)++;
            }
            //人碰到目标点
            else if(shuju[a+1][b]=='6')
            {
                shuju[a+1][b]='7';
                if(shuju[a][b]=='2')
                    shuju[a][b]='3';
                else if(shuju[a][b]=='7')
                    shuju[a][b]='6';
                a++;
                (*pstep)++;
            }
            shuchu(shuju);
            break;
        case 'd':
        case 'D':
            //人碰到了箱子
            if(shuju[a][b+1]=='*')
            {
                //箱子碰到了道路
                if(shuju[a][b+2]=='3')  
                {
                    shuju[a][b+2]='*';
                    shuju[a][b+1]='2';
                    if(shuju[a][b]=='2')
                        shuju[a][b]='3';
                    else if(shuju[a][b]=='7')
                        shuju[a][b]='6';
                    b++;
                    (*pstep)++;
                }
                //箱子碰到了目标点
                else if(shuju[a][b+2]=='6')
                {
                    shuju[a][b+2]='8';
                    shuju[a][b+1]='2';
                    if(shuju[a][b]=='2')
                        shuju[a][b]='3';
                    else if(shuju[a][b]=='7')
                        shuju[a][b]='6';
                    (*pboxFni)++;
                    b++;
                    (*pstep)++;
                }
                
            }
            //人碰到了在目标点的箱子
            else if (shuju[a][b+1]=='8')    
            {
                //箱子碰到道路
                if(shuju[a][b+2]=='3')
                {
                    shuju[a][b+2]='*';
                    shuju[a][b+1]='7';
                    if(shuju[a][b]=='2')
                        shuju[a][b]='3';
                    else if(shuju[a][b]=='7')
                        shuju[a][b]='6';
                    (*pboxFni)--;
                    b++;
                    (*pstep)++;
                }
                //箱子碰到目标点
                else if(shuju[a][b+2]=='6')
                {
                    shuju[a][b+2]='8';
                    shuju[a][b+1]='7';
                    if(shuju[a][b]=='2')
                        shuju[a][b]='3';
                    else if(shuju[a][b]=='7')
                        shuju[a][b]='6';
                    b++;
                    (*pstep)++;
                }
                
            }
            //人碰到了道路
            else if(shuju[a][b+1]=='3')
            {
                shuju[a][b+1]='2';
                if(shuju[a][b]=='2')
                    shuju[a][b]='3';
                else if(shuju[a][b]=='7')
                    shuju[a][b]='6';
                b++;
                (*pstep)++;
            }
            //人碰到目标点
            else if(shuju[a][b+1]=='6')
            {
                shuju[a][b+1]='7';
                if(shuju[a][b]=='2')
                    shuju[a][b]='3';
                else if(shuju[a][b]=='7')
                    shuju[a][b]='6';
                b++;
                (*pstep)++;
            }
            shuchu(shuju);
            break; 
    }
}

void scoreRecord(int level,int step)
{
    FILE* fp=fopen("pushBoxesScore.txt","a");
    if(fp){
        fprintf(fp,"%5d\t%5d\n",level,step);
    }else{
        printf("文件路径不正确！");
        exit(1);
    }
    fclose(fp);
}
