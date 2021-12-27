#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 10000
int num=0;
double daysale=0;

typedef struct commodity_info{
 char name[20];
 int n;
 int stock;
 int sale; 
 double price; 
 int discount;    
}inf;

inf a[maxsize]; 
void stock(char *commodity,int m)
{

   int i;
   for(i=0;i<num;i++)
     {
       if(strcmp(commodity,a[i].name)==0)
        {
           a[i].n+=m; 
           a[i].stock+=m;  
           break;                          
        }  
     } 
       if(i==num)
        {
		   printf("��������Ʒ����\n"); 
           scanf("%lf",&a[num].price);
           strcpy(a[num].name,commodity);
           a[i].n+=m; 
           a[i].stock+=m;
           num++;           
        }
}
void Exit()
{
    exit(0);
}

void sale_count(char *commodity,int k)
{
     int i;
     double c;
     
     for(i=0;i<num;i++)
       {
                       
         if(strcmp(a[i].name,commodity)==0)
           {
            
             
              if(a[i].n<k)
			  {
                  printf("��治��\n");
			  }
              
              else
              {
                  printf("������\n");
                  a[i].n=a[i].n-k;
                
                if(a[i].discount) 
                {
                    printf("��������۵��ۿ���(0.0-1.0)\n");
                    scanf("%lf",&c); 
                    daysale+=k*a[i].price*c; 
                } 
                else
                  daysale+=k*a[i].price;
                  
                a[i].sale+=k;
              }  
               
               break;                           
           }  
          
         }
           if(i==num) 
		   {
               printf("û���ҵ���Ҫ��������Ʒ\n");
		   }
   
    printf("\n"); 
} 


void jsearch(char *commodity)
{
   int i;
   for(i=0;i<num;i++)
   {
       if(strcmp(commodity,a[i].name)==0)
       {
         printf("%d\n",a[i].stock);
         break;
       }
   }    
   if(i==num)
   {
       printf("û���ҵ���Ҫ��ѯ������Ʒ\n");
   }
}




void ssearch(char *commodity)
{
   int i;
  
   for(i=0;i<num;i++)
   {
       if(strcmp(commodity,a[i].name)==0)
       {
           printf("����Ʒ��ʣ%d\n",a[i].n);
           printf("����Ʒ���칲����%d\n",a[i].sale);
           break;  
       }
   }
   
   if(i==num)
   {
       printf("û���ҵ���Ҫ��ѯ������Ʒ\n"); 
   }
          
          printf("\n");                                 
}


void ksearch(char *commodity)
{
   int i;
   for(i=0;i<num;i++)
   {
       if(strcmp(commodity,a[i].name)==0)
       {
         if(a[i].n==0)
		 {
             printf("��治��\n");
		 }
         else 
		 {
             printf("���п��:%d��!\n",a[i].n);
		 }
         
         break;
       }
          
   } 
       
   if(i==num)
   {
       printf("û���ҵ���Ҫ��ѯ������Ʒ\n"); 
   }
     
} 

void salesort()
{
  int i,j,max,max1;
  inf t;
  for(i=0;i<num;i++)
  {
     max=a[i].sale;  
     max1=i; 
    for(j=i+1;j<num;j++)
      {
         if(a[j].sale>max)
           {
               max=a[j].sale; 
               max1=j;                 
           }
      } 
       t=a[i];
       a[i]=a[max1];
       a[max1]=t;
  }
}
  
  
  void saleprint()
  {
    int i;
    printf("    ��Ʒ��    ������\n");
    for(i=0;i<num;i++)
    {
      if(a[i].sale)
      printf("%10s%4d\n",a[i].name,a[i].sale);
    }           
  }


void main()
{
    int i,chose; 
    int k,chose1;
	int i1;
    char commodity[20];
    for(i=0;i<maxsize;i++)
    {
      a[i].stock=0;                     
      a[i].sale=0;  
      a[i].n=0;
    }

    printf("��Ʒ���������ϵͳ\n");
    
begin:   
	i1=1;
	printf("�����Ҫѡ��Ĺ��������Ӧ�Ĺ������\n");
	printf("�����룺1-5\n");
    printf("1������\n");
    printf("2���۳���֧���ۿۣ�\n");
    printf("3����ѯ(�����/����/����)\n"); 
    printf("4������ͳ��\n");
	printf("5�����沢�˳�\n");
    while(1)
    { 
     
    scanf("%d",&chose);
    
    switch(chose)
    {
      case 1:
		  while(i1)
		  {
            printf("������������Ʒ������\n");
            scanf("%s",commodity);
            printf("������������Ʒ������\n");
            scanf("%d",&k);
            stock(commodity,k);
            printf("��¼���\n\n");
			printf("����������1������������0\n");
			scanf("%d",&i1);
		  }
            break;
            
      case 2:
		    i1=1;
			while(i1)
			{
             printf("������˿���Ҫ����Ʒ����Ʒ��\n");
             scanf("%s",commodity);
             printf("������˿���Ҫ������\n");
             scanf("%d",&k);
             sale_count(commodity,k);
             printf("��¼���\n\n");
			 printf("����������1������������0\n");
			 scanf("%d",&i1);
			}
             break;
             
      case 3:
		  i1=1;
		  while(i1)
		  {
           printf("��������Ʒ����\n");
           scanf("%s",commodity); 
           printf("������Ҫѡ��Ĺ���\n");
           printf("�������1��ѡ����ǿ������ѯ\n");
           printf("�������2��ѡ����ǽ�����ѯ����\n");
           printf("�������3��ѡ������۳���ѯ����\n"); 
          
           scanf("%d",&chose1);
           
           switch(chose1)
           {
               case 1:
                       ksearch(commodity); 
                       break;
               case 2:
                       jsearch(commodity);
                       break; 
               case 3:
                       ssearch(commodity);
                       break;
                         
                 default:
                         break;            
                              
           } 
		   printf("������ѯ������1��������ѯ������0\n");
		   scanf("%d",&i1);
		  }
           break;

           
      case 4:
           printf("������Ҫѡ��Ĺ���\n");
           printf("�������1��ѡ����������۶��ѯ����\n");
           printf("�������2��ѡ������ۻ����й���\n");
           scanf("%d",&chose1);
           switch(chose1)
           {
             case 1:
                printf("%lf\n",daysale);
                break;
             case 2:
                 salesort();
                 saleprint();
                break;
           }
           break;
      case 5:
		   Exit();break;
           
          default :
               break;              
    }
	goto begin;
}
    
    
        
}

