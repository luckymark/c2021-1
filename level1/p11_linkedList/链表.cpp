#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	Node* next;
}Node;
Node* creatnode(int data) {
	Node* n = (Node*)malloc(sizeof(Node));
	if (n == NULL) {
		printf("分配失败");
		exit(1);
	}
	n->data = data;
	return n;
}
int main() {
	int arr[10];
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL) {
		printf("分配失败");
			exit(1);
	}
	Node* n[10];
	printf("请依次输入10个数：\n");
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
		n[i] = creatnode(arr[i]);
		head->next = n[0];
		if (i > 0) {
			n[i - 1]->next = n[i];
		}
		if (i == 9) {
			n[i]->next = NULL;
		}
	}
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL) {
		printf("分配失败");
		exit(1);
	}
	p = head->next ;
	int ser[11] = { 0 };
	printf("链表数据为：");
	for (int i = 1; p != NULL;i++) {
		printf("%d\t", p->data);
		if (p!=NULL&&p->data == 5) {
			ser[i] = 1;
		}
		p = p->next;
	}
	puts("\n");
	n[0]->next = NULL;
	head->next = n[9];
	for (int i = 1; i < 10; i++) {
		n[i]->next = n[i - 1];
	}
	printf("逆序后的数据为：");
	Node* p1 = (Node*)malloc(sizeof(Node));
	p1 = head->next;
	while (p1) {
		printf("%d\t", p1->data);
		p1 = p1->next;
	}
	puts("\n");
	int c = 0;
	for (int i = 0; i<11; i++) {
		if (ser[i]) {
			printf("原链表第%d个数据是5\n",i);
			c++;
		}	
	}
	if (c == 0) {
		return -1;
	}
	return 0;
}