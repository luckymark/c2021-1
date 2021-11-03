#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int value;
	struct node* next;
}node;

node* create_list(int cnt) {
	int i;
	node* head = NULL;
	node* first = (node*)malloc(sizeof(node));
	scanf("%d", &first->value);
	first->next = NULL;
	head = first;
	for(i = 1; i < cnt; i++) {
		node* code = (node*)malloc(sizeof(node));
		scanf("%d", &code->value);
		code->next = NULL;
		first->next = code;
		first = first->next;
	}
	return head;
}

void printf_list(node*list) {
	node* a = list;
	while(a) {
		printf("%d\t", a->value);
		a = a->next;
	}
	free(a);
}

int search_5(node*list, int length) {
	node*b = list;
	int ret = -1;
	int i;
	for(i = 1; i <= length; i++) {
		if(b->value == 5) {
			ret = i;
			break;
		}
		b = b->next;
	}
	for(; i <= length; i++) {
		b = b->next;
	}
	free(b);
	return ret;
}

int search_all_five(node*list, int length) {
	node*b = list;
	int ret = -1;
	int i, cnt;
	for(i = 1; i <= length; i++) {
		if(b->value == 5) {
			ret = i;
			cnt++;
			printf("��%d��5�ڵ�%d���ڵ㴢��\n", cnt, i);
		}
		b = b->next;
	}
	free(b);
	return ret;
}

int search_appointed_number(node*list, int length, int seq, int num) {
	node*b = list;
	int ret = -1;
	int i, cnt;
	for(i = 1; i <= length; i++) {
		if(b->value == num) {
			cnt++;
		}
		if(cnt == seq) {
			ret = i;
			break;
		}
		b = b->next;
	}
	return ret;
}

node* reverse(node*list, int length) {
	node*c = list;
	node*first = NULL;
	for(;length > 0;length--) {
		node*new_code = (node*)malloc(sizeof(node));
		new_code->value = c->value;
		new_code->next = first;
		first = new_code;
		c = c->next;
	}
	return first;
}
node* add_list(node*list, int length) {
	node*d = reverse(list, length);
	node*add_joint = (node*)malloc(sizeof(node));
	printf("��������ӵĽڵ��ֵ��_____\b\b\b\b\b");
	scanf("%d", &add_joint->value);
	add_joint->next = d;
	node*e = reverse(add_joint, length+1);
	return e;
}
int main()
{
	int cnt, num, seq;
	printf("�����봴������ĳ��ȣ�_____\b\b\b\b\b");
	scanf("%d", &cnt);
	printf("�����������������ݣ�\n");
	node*p = create_list(cnt);
	printf_list(p);
	printf("������������һ������_____\b\b\b\b\b");
	scanf("%d", &num);
	printf("�ҵڼ���:_____\b\b\b\b\b");
	scanf("%d", &seq);
	int ret = search_appointed_number(p, cnt, seq, num);
	if(	ret != -1 ) {
		printf("��%d��%d��%d���ڵ�\n", seq, num, ret);
	}else {
		printf("�����в����ڵ�%d��%d\n", seq, num);
	}
	//search_all_five(p, cnt);
	node*q = reverse(p, cnt);
	printf_list(q);
	node*r = add_list(p, cnt);
	printf_list(r);
	return 0;
 } 
