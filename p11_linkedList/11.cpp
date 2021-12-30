#include<stdio.h>
#include<stdlib.h>


int main()
{
	typedef struct linklist
	{
		int value;
		struct linklist* next;
	}a;
	a* head = NULL, * end = NULL, * node = NULL;
	int n;


	//创建链表
	printf("请输入创建链表的节点数：");
	scanf_s("%d", &n);
	head = (a*)malloc(sizeof(a));
	if (head)
	{
		end = head;
		printf("请输入value：");
		scanf_s("%d", &end->value);
		for (int i = 1; i < n; i++)
		{
			node = (a*)malloc(sizeof(a));
			if (node)
			{
				end->next = node;
				end = node;
				printf("请输入value：");
				scanf_s("%d", &end->value);
			}
			else printf("创建失败！");
		}
		end->next = NULL;
	}
	else printf("创建失败！");


	//遍历链表，输出value
	node = head;
	if (node)
	{
		while (node != NULL)
		{
			printf("%d\n", node->value);
			node = node->next;
		};
	}


	//所有节点反序
	a** array = (a**)calloc(n, sizeof(a*));
	a** p = array;
	node = head;
	while (node != NULL)
	{
		if(p) *p = node;
		node = node->next;
		p++;
	};
	p--;
	if(p) node = *p;
	if (node) 
	{
		if (head) head->next = NULL;
		end = node;
		head = end;
		while (p!=array)
		{
			p--;
			node->next = *p;
			end = node;
			node = node->next;
		}
	}


	//遍历链表，输出value
	node = head;
	if (node)
	{
		while (node != NULL)
		{
			printf("%d\n", node->value);
			node = node->next;
		};
	}


	//查找第一个值为5的节点
	node = head;
	int cnt = 0;
	int isfound = 0;
	if (node)
	{
		while (node != NULL && isfound != 1)
		{
			if (node->value == 5) isfound = 1;
			else node = node->next;
			cnt++;
		}
	}
	if (isfound) printf("序号为%d(倒序后)\n", cnt);
	else printf("-1\n");


	//查找下一个值为5的节点
	if(node) node = node->next;
	isfound = 0;
	if (node)
	{
		while (node != NULL && isfound != 1)
		{
			if (node->value == 5) isfound = 1;
			else node = node->next;
			cnt++;
		}
	}
	if (isfound) printf("序号为%d(倒序后)\n", cnt);
	else printf("-1\n");

	//free
	node = head;
	if (head)
	{
		node = head->next;
		free(head);
		head = node;
	}

	return 0;
}