#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef	int	Elem;
struct	Node{
	int	value;
	struct	Node*next;
}; 
struct	Node*create(){
	int	len,i,val;
	printf("������������len=");
	scanf("%d",&len);
	struct Node*head=(struct	Node*)malloc(sizeof(struct	Node));
	if(head==NULL){
		printf("�ڴ����ʧ��");
	} 
	struct	Node*Tail=head;
	Tail->next=NULL;
	for(i=0;i<len;i++){
		printf("�������%d�������ֵ:value=",i+1);
		scanf("%d",&val);
		struct	Node*New=(struct	Node*)malloc(sizeof(struct Node));
		if(NULL==New){
			printf("�ڴ����ʧ��"); 
		}
		New->value=val;
		Tail->next=New;
		New->next=NULL;
		Tail=New;
	}
	return	head;
}
void	traverse(struct	Node*head){
	printf("\n");
	printf("����������:\n");
	struct	Node*p=head->next;
	while(NULL!=p){
		printf("%d\n",p->value);
		p=p->next;
	}
}
Node* revert_list(Node*head){
	if(head==NULL){
		return	head;
	}
	Node*p=head->next;
	head->next=NULL;
	Node*tmp=NULL;
	while(p){
		tmp=p->next;
		p->next=head->next;
		head->next=p;
		p=tmp;
	} 
	return	head;
}
void	display_list(Node*head){
	Node*tmp=head;
	while(NULL!=(tmp=tmp->next)){
		printf("%d\n",tmp->value);
	}
	printf("\n");
}
int	main(){
	int	count=0;
	struct	Node*head;
	struct	Node*p;
	head=create();
	traverse(head);
	head=revert_list(head);
	printf("��������Ϊ��\n");
	display_list(head);
	int	x=5;
	int	j=1,k=1;
	p=head;
	while(p!=NULL&&p->value!=x){
		p=p->next;	
	}
	while(p!=NULL){
		if(p->value==x){
			printf("�ҵ��ˣ�λ����%d\n",j);
			count++;
		}
		p=p->next;
		j++;
	}
	if(count==0){
		printf("û�ҵ�\n");
		printf("-1");
	}
	return	0;
}
