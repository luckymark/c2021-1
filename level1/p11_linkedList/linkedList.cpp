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
}linklist;
linklist *Createlist(){
	linklist *head,*x,*end;
	head=(linklist *)malloc(sizeof(linklist));
	end=head;
	for(int i=1;i<=n;i++){
		x=(linklist *)malloc(sizeof(linklist));
		scanf("%d",&x->val);
		x->vis=1;
		end->next=x;
		end=x;
	}
	end->next=NULL;
	return head;
} 
node *reverse(node *head){
	if(head==NULL||head->next==NULL) return head; 
	node* newhead=reverse(head->next);
	head->next->next=head;
	head->next=NULL;
	return newhead;
} 

int main(){
	scanf("%d",&n);
	linklist *list=Createlist();
	node *h=reverse(list);
	int cnt=1;
	while(h->next!=NULL){
		if(h->val==5&&h->vis==1) {
			write(n-cnt+1);
			putchar('\n');
			h->vis=0;
			break;
		}
		h=h->next;
		cnt++;
	}
	cnt=1;
	while(h->next!=NULL){
		if(h->val==5&&h->vis==1) {
			write(n-cnt+1);
			putchar('\n');
			h->vis=0;
			break;
		}
		h=h->next;
		cnt++;
	}
	return 0;
}
