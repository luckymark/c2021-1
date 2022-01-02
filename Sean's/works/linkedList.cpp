#include<time.h>
#include<stdio.h>
#include<stdlib.h>

const int N = 100;
const int M = 10;

struct Node {
	int data;
	Node* next;
};
struct Node* head;
struct Node* tail;

Node* create(int num) {
	Node* a = (Node*)malloc(sizeof(Node));
	a->data = num;
	a->next = NULL;
	return a;
}

Node* append(Node* now, int num) {
	Node* New = create(num);
	now->next = New;
	tail=New;
	return New;
}

void insert(Node* index, int num) {
	Node* New = create(num);
	New->next = index->next;
	index->next = New;
}
bool Delete(Node* index) {
	if (index->next == NULL) return 1;
	index->next = (index->next)->next;
	return 0;
}
Node* find(int id, Node* now) {
	if (id == 0) return now;
	return find(id - 1, now->next);
}
//没有用到的三个函数

void reverse(Node* now,int cnt) {
	if (now->next == NULL) {
		head->next = now;
		return;
	}
	reverse(now->next,cnt+1);
	(now->next)->next = now;
	if (cnt == 1) {
		now->next = NULL;
		tail = now;
	}
}
//反转该单向链表

void PRINT() {
	Node* dir = head;
	while (dir != tail) {
		dir = dir->next;
		printf("%d ", dir->data);
	}
	puts("");
}
//遍历并打印该链表

int FIND_5(Node* now,int id) {
	if (now->data == 5) return id;
	if (now == tail) return -1;
	return FIND_5(now->next, id + 1);
}
//找第一个5的序号

int FIND2_5(Node* now, int id, int cnt) {
	if (now->data == 5) {
		if (cnt == 1) return id;
		if (now == tail) return -1;
		return FIND2_5(now->next, id + 1, cnt + 1);
	}
	if (now == tail) return -1;
	return FIND2_5(now->next,id+1,cnt);
}
//找第二个5的序号

void PROCESS() {
	srand(time(NULL));
	head = create(0);
	tail = head;
	for (int i = 1; i <= N; ++i) 
		tail=append(tail,rand()%M+1);
	PRINT();
	printf("第一个5的序号是：%d\n", FIND_5(head->next, 1));
	printf("第二个5的序号是：%d\n", FIND2_5(head->next, 1,0));
	reverse(head->next,1);
	PRINT();
	printf("第一个5的序号是：%d\n", FIND_5(head->next,1));
	printf("第二个5的序号是：%d\n", FIND2_5(head->next, 1, 0));
}

int main()
{
	PROCESS();
	return 0;
}