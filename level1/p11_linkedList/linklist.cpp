#include<stdio.h>
#include<malloc.h>
typedef struct LINK {
	int num;
	LINK* next;


};
void Lfree(LINK* head) {
	LINK* a, * b;
	a = head;
	while (a) {
		b = a->next;
		free(a);
		a = b;
	}

}

void creat(int i, LINK* head) {
	LINK* a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = (LINK*)malloc(sizeof(LINK));
	}
	head->next = a[0];
	for (int m = 0; m < i; m++) {
		printf("请输入数据");
		scanf_s("%d", &a[m]->num);
		printf("\n");
		if (m == i - 1) {
			a[m]->next = NULL;
		}
		else {
			a[m]->next = a[m + 1];
		}
	}




}
void Lprint(LINK* head) {
	int i = 1;
	LINK* temp = head->next;
	while (temp) {
		printf("第%d个链表中num是：%d", i, temp->num);
		i++;

		temp = temp->next;
	}
}
void find(LINK* head,int *a) {
	for (int i = 0; i < 10; i++) {
		a[i] = 0;
	}
	for (int m = 0;; m++) {
		if (head == NULL) {
			break;
		}
		if (head->num == 5) {
			a[m] = 1;
		}
		head = head->next;
	}




}

int main() {
	LINK* head = (LINK*)malloc(sizeof(LINK));
	if (head == NULL) {
		printf("分配失败");
	}
	head->num = 0;
	head->next = NULL;
	creat(4, head);
	Lprint(head);
	int r[10];
	find(head,r);
	int count = 0;
	for (int i = 0; i < 10; i++) {

		if (r[i] == 1) {
			printf("\t在第%d个表\n", i);
		}
		count = r[i] + count;
	}
	if (count == 0) {
		printf("-1");
	}
	Lfree(head);
}