#include<iostream>

using namespace std; 

struct node {
int value;
struct node * next;
};
typedef struct node Node;
typedef struct node *ptrList,*List;
void create(Node *&T);void PrintNode(ptrList V);
//��������
void create(Node *&T)
{
Node *p,*tmp; //�����ָ��
int n;
if(T==NULL)
{
T = new Node;//����һ��ͷ���
T->value = 0;
T->next = NULL;
}
p = T;
cin>>n;
for(int i=0;i<n;i++)
{
tmp = new Node;//����һ���ṹ��
cin>>tmp->value; //����һ����ֵ
tmp->next = NULL; //����һ���ڵ�
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
