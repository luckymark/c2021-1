
#include<stdio.h>
#include<stdlib.h>
#define n1 50//�����з�Χ
#define n2 50//�����з�Χ
 
typedef struct node//����һ���ṹ��洢������Ϣ
{
         int x;
         int y;
         int c;
}linkstack;
int maze[n1][n2]; //����һ����ά����
linkstack top[n1*n2]; //����һ��N*N��ջ
int i,j,k,m=1,run;
 
void array(int g,int h)    //�Զ�ά������ʽ�����Թ�����
{
          int a,b;
          for(a=0;a<g;a++)
          {
               for(b=0;b<h;b++)
               {
                     scanf("%d",&maze[a][b]);   //�����Թ���Ӧ����������
             }
         }   
}
 
void initmaze(int g,int h){//�����Թ�
   int a,b;
     printf("���ɵ��Թ���:\n");
       for(a=0;a<g;a++)
      { for(b=0;b<h;b++)
         printf(maze[a][b]?"#":"");//����Թ�ͼ��
         printf("\n");
      }
}
 
int main()
{ int g,h,v;
    int w;
   printf("**********     ��ӭʹ���Թ����           ********\n");
   printf("***************�Թ�����밴:1   ******************\n");
   printf("***************    �˳��밴:2   ******************\n");
  printf("**************************************************\n");
   printf("��������ѡ��:");
    scanf("%d",&w);
   switch(w)//�������WΪ1��2,���������
   { case 1:printf("�����Թ���С(��ʾ:���������ܳ���50!):");//WΪ1ʱ
            scanf("%d",&g);
            printf("��С�������,�������Թ�:\n");
            h=g;//ȷ�������СΪgά
            array(g,h);
               for(i=0;i<=g*h;i++)
               top[i].c=1;
            initmaze(g,h);//�����Թ�
            i=0;
            top[i].x=1;//i=0ʱX�����Ӧֵ�ú�Ϊ1
            top[i].y=0; //i=0ʱY�����Ӧֵ�ú�Ϊ0
            maze[1][0]=2;//����Թ�ֵ��Ϊ2
            run=1;
            v=1;
            do{ //�������߹���ͳ����ж�
              if(top[i].c<5)//��i��ɵ�����ֵС��5�����½���
              {
                                     if(top[i].x==(g-2)&&top[i].y==(h-1))//��i��Ϊ����ʱ�����������
                                   {
                                                       printf("��%d��ͨ·��:\n",m++);//�����ͬ��·��
                                             for(j=0;j<=i;j++)
                                                    {
                                                                           printf("(%d,%d)",top[j].x,top[j].y);
                                                                  }//���ͨ·����
                             printf("\n");
                   for(j=0;j<g;j++)//����Թ�·��ͼ��
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
                     printf("���Թ���ͨ·!");
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
 
   case 2: printf("��ӭ�´�ʹ��!");  
      break;
    default: break;
   }
   return 0;
}


