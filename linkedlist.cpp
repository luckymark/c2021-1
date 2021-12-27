#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef	int	E;
struct	jiedian {
	int	value;
	struct	jiedian* next;
};
struct	jiedian* create() {
	int	len, i, val;
	printf("请输入链表长度");
	scanf("%d", &len);
	struct jiedian* head = (struct	jiedian*)malloc(sizeof(struct	jiedian));
	if (head == NULL) {
		printf("!!!内存分配失败!!!");
	}
	struct	jiedian* Tail = head;
	Tail->next = NULL;
	for (i = 0; i < len; i++) {
		printf("请输入第%d个链表的值", i + 1);
		scanf("%d", &val);
		struct	jiedian* New = (struct	jiedian*)malloc(sizeof(struct jiedian));
		if (NULL == New) {
			printf("!!!内存分配失败!!!");
		}
		New->value = val;
		Tail->next = New;
		New->next = NULL;
		Tail = New;
	}
	return	head;
}
void	traverse(struct	jiedian* head) {
	printf("\n");
	printf("链表遍历完成:\n");
	struct	jiedian* p = head->next;
	while (NULL != p) {
		printf("%d\n", p->value);
		p = p->next;
	}
}
jiedian* revert_list(jiedian* head) {
	if (head == NULL) {
		return	head;
	}
	jiedian* p = head->next;
	head->next = NULL;
	jiedian* tmp = NULL;
	while (p) {
		tmp = p->next;
		p->next = head->next;
		head->next = p;
		p = tmp;
	}
	return	head;
}
void	display_list(jiedian* head) {
	jiedian* tmp = head;
	while (NULL != (tmp = tmp->next)) {
		printf("%d\n", tmp->value);
	}
	printf("\n");
}
int	main() {
	int	count = 0;
	struct	jiedian* head;
	struct	jiedian* p;
	head = create();
	traverse(head);
	head = revert_list(head);
	printf("逆序链表为：\n");
	display_list(head);
	int	x = 5;
	int	j = 1, k = 1;
	p = head;
	while (p != NULL && p->value != x) {
		p = p->next;
	}
	while (p != NULL) {
		if (p->value == x) {
			printf("找到了，位置是%d\n", j);
			count++;
		}
		p = p->next;
		j++;
	}
	if (count == 0) {
		printf("没找到\n");
		printf("-1");
	}
	return	0;
}