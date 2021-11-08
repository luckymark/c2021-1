#include<cstdio>
using namespace std;

struct node
{
	node* nxt;
	node* pre;
	int val,num;
};

int main()
{
	int n;
	node* head=new node;
	node* x=head;
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		scanf("%d",&x->val);
		x->num=n-i+1;
		x->nxt=new node;
		x->nxt->pre=x;
		x=x->nxt;
	}
	scanf("%d",&x->val);
	x->num=1;
	x->nxt=NULL;
	head=x;
	for(int i=1;i<n;++i)
	{
		x->nxt=x->pre;
		x=x->nxt;
	}//∑¥–Ú
	x->nxt=NULL;
	x=head;
	while(x!=NULL)
	{
		if(x->val==5)
		printf("%d ",x->num);
		x=x->nxt;
	}//≤È’“
	printf("-1");
	return 0;
}