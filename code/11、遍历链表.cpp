#include<iostream>

using namespace std; 

struct node {
int value;
struct node * next;
};
typedef struct node Node;
typedef struct node *ptrList,*List;
void create(Node *&T);void PrintNode(ptrList V);
//建立链表
void create(Node *&T)
{
Node *p,*tmp; //插入的指针
int n;
if(T==NULL)
{
T = new Node;//申请一个头结点
T->value = 0;
T->next = NULL;
}
p = T;
cin>>n;
for(int i=0;i<n;i++)
{
tmp = new Node;//申请一个结构类
cin>>tmp->value; //输入一个数值
tmp->next = NULL; //插入一个节点
p->next = tmp;
p = tmp;
}
}
void PrintNode(ptrList V)
{
List tmp ;
if(!V||!V->next)
{
cout<<"NULL"<<endl;
return ;
}
tmp = V->next;
while(tmp->next)
{
cout<<tmp->value<<",";
tmp = tmp->next;
}
cout<<tmp->value<<endl;
return ;
}
int main()
{
List La=NULL;
create(La);
PrintNode(La);
return 0;
}
