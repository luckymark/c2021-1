#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <math.h>
int n;
int read(){
	int flag=1,ans=0;
	char ch;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') flag=-1;
	ans=ch-48;
	while((ch=getchar())>='0'&&ch<='9') ans=(ans<<3)+(ans<<1)+ch-48;
	return ans*flag;
} 
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
typedef struct node{
	int val,vis;
	struct node *next; 
};
node *Createlist(){
	node *head,*x,*end;
	head=(node *)malloc(sizeof(node));
	scanf("%d",&head->val),head->vis=1;
	end=head;
	for(int i=1;i<=n-1;i++){
		x=(node *)malloc(sizeof(node));
		scanf("%d",&x->val);
		x->vis=1;
		end->next=x;
		end=x;
	}
	end->next=NULL;
	return head;
} 
node *reverse(node *head){
	if(head==NULL||head->next==NULL){
		return head;
	} 
	node* newhead=reverse(head->next);
	head->next->next=head;
	head->next=NULL;
	return newhead;
} 

int main(){
	n=read();
	node *list=Createlist();
	list=reverse(list);
	node *h=list;
	int cnt=1;
	while(h!=NULL){
		if(h->val==5&&h->vis==1){
			h->vis=0;
			write(n-cnt+1);
			putchar(' ');
			break;
		}
		h=h->next;
		cnt++;
	}
	h=list;
	cnt=1;
	while(h!=NULL){
		if(h->val==5&&h->vis==1){
			h->vis=0;
			write(n-cnt+1);
			putchar(' ');
			break;
		}
		h=h->next;
		cnt++;
	}
	return 0;
}
