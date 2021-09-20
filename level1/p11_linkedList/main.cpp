#include<ctime>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef struct node{
    int value;
    int order;
    struct node *next;
}chart;
chart *cur=NULL;

chart *create(int n){
    chart *head=new chart;
    chart *pre=head;
    srand((unsigned)time(0) );
    for(int i=0;i<n;++i){
        chart *pmove=new chart;
        pmove->value=rand()%5+1;
        pmove->order=i+1;//head不编号
        pre->next=pmove;
        pre=pmove;
        pmove=NULL;
    }
    pre->next=NULL;
    return head;
}
void display(chart *head){
    chart *pmove=head->next;
    while(pmove!=NULL){
        cout<<pmove->value<<endl;
        pmove=pmove->next;
    }
}
chart *reorder(chart *head){
    chart *reverse=NULL;
    chart *next;
    while(next!=NULL){
       next=head->next->next;
       head->next->next=reverse;
       reverse=head->next;
       if(next!=NULL)
       head->next=next;
    }
    return head;
}
int search(){
    while(cur->next!=NULL){
        cur=cur->next;
        if (cur->value==5){
            return cur->order;
        }
    }
    return -1;
}
chart *create(int n);
void display(chart *head);
chart *reorder(chart *head);
int search(chart *head);
int main(){
    int n,number=-1,j=1;
    bool flag=false;
    cout<<"enter the number of node"<<endl;
    cin>>n;
    chart *head=create(n);
    display(head);
    chart *headnew=reorder(head);
    cout<<"the new node are"<<endl;
    display(headnew);
    cur=headnew;
    do{
        number=search();
        if (number!=-1){
            cout<<"第"<<j<<"个节点序号为"<<number<<endl;
            j=j+1;
            flag=true;
        }
        else if(!flag) goto final;
    }
    while(number!=-1);
    return 0;
    final:return -1;
}


