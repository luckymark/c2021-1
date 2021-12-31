#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct node
{
	int data;
	struct node* next;
}Node;

Node* createList();
void insertList(Node* head, int inputData);
void traverseList(Node* head);
int lengthList(Node* head);
Node* searchList(Node* head, int searchData);
void deleteNode(Node* head, Node* pdst);
void reverseList(Node* head);
void sortList(Node* head);
void destoryList(Node* head);
int main()
{
	Node* head = createList();
	srand(time(NULL));
	printf("insert- traverse:\n");
	for (int i = 0; i < 10; i++)
		insertList(head, rand() % 100);
	traverseList(head);
	printf("\nfind-delete:\n");
	if (searchList(head, 0))
	{
		printf("ok.");
		deleteNode(head, searchList(head, 0));
		printf("\ndelete");
		traverseList(head);
	}
	else
		printf("none.\n");
	printf("reverse:\n");
	reverseList(head);
	traverseList(head);
	printf("\nsort:\n");
	sortList(head);
	traverseList(head);
	destoryList(head);
	return 0;
}
Node* createList()
{
	Node* head = (Node*)malloc(sizeof(Node));
	if (NULL == head)
		exit(-1);
	head->next = NULL;
	return head;
}
void insertList(Node* head, int inputData)
{
	Node* ptr = (Node*)malloc(sizeof(Node));
	if (NULL == ptr)
		exit(-1);
	ptr->data = inputData;
	ptr->next = head->next;
	head->next = ptr;
}
void traverseList(Node* head)
{
	head = head->next;
	while (head)
	{
		printf("%-3d", head->data);
		head = head->next;
	}
}
int lengthList(Node* head)
{
	int len = 0;
	head = head->next;
	while (head)
	{
		len++;
		head = head->next;
	}
	return len;
}
Node* searchList(Node* head, int searchData)
{
	head = head->next;
	while (head)
	{
		if (searchData == head->data)
			break;
		head = head->next;
	}
	return head;
}
void deleteNode(Node* head, Node* pdst)
{
	if (NULL == pdst->next)
	{
		while (head->next != pdst)
			head = head->next;
		head->next = pdst->next;
		free(pdst);
		pdst = NULL;
	}
	else
	{
		Node* tmp = pdst->next;
		pdst->data = pdst->next->data;
		pdst->next = pdst->next->next;
		free(tmp);
	}
}
void reverseList(Node* head)
{
	Node* ptr = head->next;
	head->next = NULL;
	Node* tmp;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		tmp->next = head->next;
		head->next = tmp;
	}
}
void sortList(Node* head)
{
	int len = lengthList(head);
	Node* p, * q, * prep, * tmp;
	for (int i = 0; i < len - 1; i++)
	{
		prep = head;
		p = head->next;
		q = p->next;
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (p->data > q->data)
			{
				prep->next = q;
				p->next = q->next;
				q->next = p;
				tmp = p;
				p = q;
				q = tmp;
			}
			prep = prep->next;
			p = p->next;
			q = q->next;
		}
	}
}
void destoryList(Node* head)
{
	Node* tmp;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}