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


	//��������
	printf("�����봴������Ľڵ�����");
	scanf_s("%d", &n);
	head = (a*)malloc(sizeof(a));
	if (head)
	{
		end = head;
		printf("������value��");
		scanf_s("%d", &end->value);
		for (int i = 1; i < n; i++)
		{
			node = (a*)malloc(sizeof(a));
			if (node)
			{
				end->next = node;
				end = node;
				printf("������value��");
				scanf_s("%d", &end->value);
			}
			else printf("����ʧ�ܣ�");
		}
		end->next = NULL;
	}
	else printf("����ʧ�ܣ�");


	//�����������value
	node = head;
	if (node)
	{
		while (node != NULL)
		{
			printf("%d\n", node->value);
			node = node->next;
		};
	}


	//���нڵ㷴��
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


	//�����������value
	node = head;
	if (node)
	{
		while (node != NULL)
		{
			printf("%d\n", node->value);
			node = node->next;
		};
	}


	//���ҵ�һ��ֵΪ5�Ľڵ�
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
	if (isfound) printf("���Ϊ%d(�����)\n", cnt);
	else printf("-1\n");


	//������һ��ֵΪ5�Ľڵ�
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
	if (isfound) printf("���Ϊ%d(�����)\n", cnt);
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