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
		   printf("请输入商品进价\n"); 
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
                  printf("库存不足\n");
			  }
              
              else
              {
                  printf("库存充足\n");
                  a[i].n=a[i].n-k;
                
                if(a[i].discount) 
                {
                    printf("请输入打折的折扣率(0.0-1.0)\n");
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
               printf("没有找到你要的这种商品\n");
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
       printf("没有找到你要查询这种商品\n");
   }
}




void ssearch(char *commodity)
{
   int i;
  
   for(i=0;i<num;i++)
   {
       if(strcmp(commodity,a[i].name)==0)
       {
           printf("该商品还剩%d\n",a[i].n);
           printf("该商品今天共卖出%d\n",a[i].sale);
           break;  
       }
   }
   
   if(i==num)
   {
       printf("没有找到你要查询这种商品\n"); 
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
             printf("库存不足\n");
		 }
         else 
		 {
             printf("还有库存:%d件!\n",a[i].n);
		 }
         
         break;
       }
          
   } 
       
   if(i==num)
   {
       printf("没有找到你要查询这种商品\n"); 
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
    printf("    商品名    销售量\n");
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

    printf("商品进销存管理系统\n");
    
begin:   
	i1=1;
	printf("请根据要选择的功能输入对应的功能序号\n");
	printf("请输入：1-5\n");
    printf("1，进货\n");
    printf("2，售出（支持折扣）\n");
    printf("3，查询(库存量/进货/出售)\n"); 
    printf("4，财务统计\n");
	printf("5，保存并退出\n");
    while(1)
    { 
     
    scanf("%d",&chose);
    
    switch(chose)
    {
      case 1:
		  while(i1)
		  {
            printf("请输入所进商品的名称\n");
            scanf("%s",commodity);
            printf("请输入所进商品的数量\n");
            scanf("%d",&k);
            stock(commodity,k);
            printf("记录完毕\n\n");
			printf("继续请输入1，结束请输入0\n");
			scanf("%d",&i1);
		  }
            break;
            
      case 2:
		    i1=1;
			while(i1)
			{
             printf("请输入顾客想要的商品的商品名\n");
             scanf("%s",commodity);
             printf("请输入顾客想要的数量\n");
             scanf("%d",&k);
             sale_count(commodity,k);
             printf("记录完毕\n\n");
			 printf("继续请输入1，结束请输入0\n");
			 scanf("%d",&i1);
			}
             break;
             
      case 3:
		  i1=1;
		  while(i1)
		  {
           printf("请输入商品名称\n");
           scanf("%s",commodity); 
           printf("请输入要选择的功能\n");
           printf("如果输入1，选择的是库存量查询\n");
           printf("如果输入2，选择的是进货查询功能\n");
           printf("如果输入3，选择的是售出查询功能\n"); 
          
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
		   printf("继续查询请输入1，结束查询请输入0\n");
		   scanf("%d",&i1);
		  }
           break;

           
      case 4:
           printf("请输入要选择的功能\n");
           printf("如果输入1，选择的是日销售额查询功能\n");
           printf("如果输入2，选择的是售货排行功能\n");
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

