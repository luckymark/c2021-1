/*说明：
先输入要存储的数据个数
然后输入依次输入每个数据

程序会返回你输入的每个数据，链表反序后的数据，数字5在哪些结点上*/
#include <stdio.h>
#include<stdlib.h>
#define NUM 5   //要查找的数字
typedef struct Node{
    int data;
    struct Node* next;
}Node;
typedef struct List{
    Node* head;
}List;

void add(List* pList,int number);
void invert(List* pList);
void print(List* pList);
int search(List* pList,int n,int number);//查找第n个数字number


int main()
{
    List list;
    list.head=NULL;

    int number;
    int number_n;
    printf("请输入要输入的数据个数：");
    scanf("%d",&number_n);
    for(int i=0;i<number_n;i++)
    {
        scanf("%d",&number);
        add(&list,number);
    }
    printf("你输入的数据：");
    print(&list);
    printf("\n反序后的数据：");
    invert(&list);
    print(&list);
    printf("\n");
    int n=1;
    if(search(&list,n,NUM)!=-1)
    {
        while (search(&list,n,NUM)!=-1)
        {
            printf("第%d个数字%d在第%d个结点上\n",n,NUM,search(&list,n,NUM));
            n++;
        }
    }
    else
    {
        printf("找不到数字%d",NUM);
    }  
}

void add(List* pList,int number)
{
    Node* q=(Node*)malloc(sizeof(Node));
    q->data=number;
    q->next=NULL;
    Node* last=pList->head;
    if(last)
    {
        for(;last->next;last=last->next);
        last->next=q;
    }
    else
    {
        pList->head=q;
    }
}
void invert(List* pList)
{
    Node* p=pList->head;
    if(p!=NULL)
    {
        Node* q=p->next;
        p->next=NULL;
        if(q!=NULL)
        {
            Node* r=q->next;
            if(r!=NULL)
            {
                for(;r->next;p=q,q=r,r=r->next)
                {
                    q->next=p;
                }
                q->next=p;
                r->next=q;
                pList->head=r;
            }
            else
            {
                q->next=p;
                pList->head=q;
            }
        }
        else
        {
            pList->head=p;
        }
    }
}
int search(List* pList,int n,int number)
{
    int ret=-1;
    int idx=1;
    for(Node* p=pList->head;p;p=p->next)
    {
        if(p->data==number)
        {
            n--;
            if(n==0)
            {
                ret=idx;
                break;
            }
        }
        idx++;
    }
    return ret;
}

void print(List* pList)
{
    for(Node* p=pList->head;p;p=p->next)
    {
        printf("%d ",p->data);
    }
}