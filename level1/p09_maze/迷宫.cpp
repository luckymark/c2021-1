
#include<stdio.h>
#include<stdlib.h>
#define n1 50//定义行范围
#define n2 50//定义列范围
 
typedef struct node//创建一个结构体存储数组信息
{
         int x;
         int y;
         int c;
}linkstack;
int maze[n1][n2]; //创建一个二维数组
linkstack top[n1*n2]; //创建一个N*N的栈
int i,j,k,m=1,run;
 
void array(int g,int h)    //以二维数组形式定义迷宫内容
{
          int a,b;
          for(a=0;a<g;a++)
          {
               for(b=0;b<h;b++)
               {
                     scanf("%d",&maze[a][b]);   //输入迷宫对应的数组数据
             }
         }   
}
 
void initmaze(int g,int h){//生成迷宫
   int a,b;
     printf("生成的迷宫是:\n");
       for(a=0;a<g;a++)
      { for(b=0;b<h;b++)
         printf(maze[a][b]?"#":"");//输出迷宫图形
         printf("\n");
      }
}
 
int main()
{ int g,h,v;
    int w;
   printf("**********     欢迎使用迷宫求解           ********\n");
   printf("***************迷宫求解请按:1   ******************\n");
   printf("***************    退出请按:2   ******************\n");
  printf("**************************************************\n");
   printf("输入您的选择:");
    scanf("%d",&w);
   switch(w)//若输入的W为1或2,则继续程序
   { case 1:printf("输入迷宫大小(提示:行列数不能超过50!):");//W为1时
            scanf("%d",&g);
            printf("大小创建完毕,请输入迷宫:\n");
            h=g;//确定数组大小为g维
            array(g,h);
               for(i=0;i<=g*h;i++)
               top[i].c=1;
            initmaze(g,h);//生成迷宫
            i=0;
            top[i].x=1;//i=0时X方向对应值得和为1
            top[i].y=0; //i=0时Y方向对应值得和为0
            maze[1][0]=2;//入口迷宫值变为2
            run=1;
            v=1;
            do{ //定义行走规则和出口判断
              if(top[i].c<5)//若i点可到方向值小于5则向下进行
              {
                                     if(top[i].x==(g-2)&&top[i].y==(h-1))//当i点为出口时所满足的条件
                                   {
                                                       printf("第%d条通路是:\n",m++);//输出不同的路程
                                             for(j=0;j<=i;j++)
                                                    {
                                                                           printf("(%d,%d)",top[j].x,top[j].y);
                                                                  }//输出通路坐标
                             printf("\n");
                   for(j=0;j<g;j++)//求出迷宫路线图形
                    { 
                                                   for(k=0;k<h;k++)
                        {  
                                                           if(maze[j][k]==0)
                               printf("");
                           else if(maze[j][k]==2)
                              printf("O");
                           else printf("#"); 
                        }
                    printf("\n");
                    }
                maze[top[i].x][top[i].y]=0;
                top[i].c=1;
                i--;
                top[i].c+=1;
                continue;
             }
             switch(top[i].c)
             { 
                                 case 0:
                 { run=0;
                if(v==1)
                     printf("此迷宫无通路!");
                  break;
                 }
                case 1:
                {  if(maze[top[i].x][top[i].y+1]==0)
                {  i++;
                       top[i].x=top[i-1].x;
                       top[i].y=top[i-1].y+1;
                      maze[top[i].x][top[i].y]=2;
                   if(maze[g-2][h-1]==2) v=0;
                }
                       else   top[i].c+=1;
                 break;
                }
                case 2:
                {if(maze[top[i].x-1][top[i].y]==0)
                { i++;
                       top[i].x=top[i-1].x-1;
                       top[i].y=top[i-1].y;
                      maze[top[i].x][top[i].y]=2;
                
                }
                       else   top[i].c+=1;
                  break;
                }
                case 3:
                {  if(maze[top[i].x][top[i].y-1]==0)
                {  i++;
                       top[i].x=top[i-1].x;
                       top[i].y=top[i-1].y-1;
                      maze[top[i].x][top[i].y]=2;
 
                }
                       else   top[i].c+=1;
                  break;
                }
                case 4:
                {  if(maze[top[i].x+1][top[i].y]==0)
                {  i++;
                       top[i].x=top[i-1].x+1;
                       top[i].y=top[i-1].y;
                      maze[top[i].x][top[i].y]=2;
                 
                }
                       else   top[i].c+=1;
                  break;
                }
          }
         }
         else
       {  if(i==0) return 0;
             maze[top[i].x][top[i].y]=0;
             top[i].c=1;
             i--;
             top[i].c+=1;
       
       }
       
      }while(run==1);
       
      break;
 
   case 2: printf("欢迎下次使用!");  
      break;
    default: break;
   }
   return 0;
}


