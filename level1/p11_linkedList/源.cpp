#include<stdio.h>
#include<stdlib.h>

typedef struct NODE
{
	int data;
	struct NODE* next;
}NODE;


void createNODE(NODE* L, int a)
{
	NODE* s;
	int i;
	s = (NODE*)malloc(sizeof(NODE));
	s->data = a;
	s->next = L->next;
	L->next = s;
}

void printfList(NODE* L)
{
	NODE* temp = L;
	printf("表中的元素为:\n");
	while (temp->next)
	{
		temp = temp->next;
		printf("%d ", temp->data);
	}
	printf("\n");

}
int searchElem(NODE* L, int e)
{
	NODE* temp = L;
	int i = 1;
	int p = 0;
	while (temp->next)
	{
		temp = temp->next;
		if (e == temp->data)
		{
			p = i;
			printf("找到了与%d相等元素位置为%d\n", e, p);
			return 1;
		}
		i++;
	}
	printf("抱歉，没有找到！");
	return -1;
}

int main()
{
	NODE* L;
	L = (NODE*)malloc(sizeof(NODE));
	L->next = NULL;
	int n;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf_s("%d", &x);
		createNODE(L, x);
	}

	printfList(L);

	return 0;
}

