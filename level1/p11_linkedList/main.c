#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    struct node *next;
}Node;
void add(int number,Node **head);
void print(Node *head);
Node *reserve(Node *head);
void find(Node *head);
int main()
{
    Node *head=NULL;
    int number;
    do{
        scanf("%d",&number);
        if(number!=-1){
           add(number,&head);//创建
        }
    }while(number!=-1);
    print(head);//输出
    head=reserve(head);//反序
   find(head);//寻找
    return 0;
}
void add(int number,Node **head) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;
    Node *last = *head;
    if (last) {
        while (last->next) {
            last = last->next;
        }
        last->next = p;
    } else {
        *head = p;
    }
}
void print(Node *head){
    Node *print=head;
    while(print){
        printf("%d\n",print->value);
        print=print->next;
    }
}
Node *reserve(Node *head){
    if(head==NULL||head->next==NULL){
        return head;
    }else{
        Node *beg=NULL;
        Node *end=NULL;
        beg=head;
        end=head->next;
        while(end!=NULL){
            beg->next=end->next;
            end->next=head;
            head=end;
            end=beg->next;
        }
       return head;
    }
}
void find(Node *head){
   Node *find;
   int count;
   int number=-1;
   for(find=head,count=1;find!=NULL;find=find->next,count++){
       if(find->value==5){
           printf("序号为%d\n",count);
           number=count;
       }
   }
   if(number==-1){
       printf("不存在");
   }
}
