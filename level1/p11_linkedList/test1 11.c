#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int rank;
    int data;
    struct Node* next;
}Node;

typedef struct List{
    Node *head;
}List;

void printlist(List* list);

void add(List *list,int data);

void search(List *list,int number);

void rank(List *list);
int main(){
    List list;
    list.head=NULL;
    printf("输入你想在链表内添加的数据（数据用空格隔开），输入-1终止\n");
    int number;
    
    do{
        scanf("%d",&number);
        if(number!=-1){
            add(&list,number);}
    }while(number!=-1);
    Node *p,*q,*r;
    p=list.head;
    q=list.head->next;
    list.head->next=NULL;
    while(q){
    	r=q->next;
    	q->next=p;
    	p=q;
    	q=r;
	}
    list.head=p;
	printlist(&list);
    rank(&list);	
	
    
		search(&list,5);

    return 0;
}

void add(List *list,int data0){
	
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=data0;
    p->next=NULL;
    
    Node*last=list->head;
    if(last){
        while(last->next){
            last=last->next;
        }
        last->next=p;
    }else{p->rank=0;
        list->head=p;
    }
}

void printlist(List* list){
	Node *p;
    for(p=list->head;p;p=p->next){
        printf("%d ",p->data);
    }
    printf("\n");
}

void search(List *list,int number){
	Node *p;
	static int m=0;
	for(p=list->head;p;p=p->next){
		if(p->data==number){
			printf("%d ",p->rank);
			m=1;
			
			
		}
	}
	if(m==0){
		printf("未找到5"); 
		exit;
	}
	
}
void rank(List *list){
	Node *p;
	for(p=list->head;p;p=p->next){
		static m=0;
		m++;
		p->rank=m;
	}
}

