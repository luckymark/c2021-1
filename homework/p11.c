#include<stdio.h>
#include<time.h>
#include<stdlib.h>
const int MAX = 1000;
typedef struct List {
	int val;
	struct List* next;
}List;
List* addlist(List* end, int val) {
	end->next = (List*)malloc(sizeof(List));
	end = end->next;
	end->val = val;
	end->next = NULL;
	return end;
}
List* getptr(List* head, int n) {//查找指定节点的指针
	List* now = head;
	for (now = head; n > 0; --n) {
		now = now->next;
	}
	return now;
}
int findval(List* head, int x) {//查找从head开始第一个x的序号
	for (int i = 1; i < MAX; ++i) {
		if (head->val == x) {
			return i;
		}
		head = head->next;
	}
	return -1;
}
int main() {
	srand((unsigned)time(NULL));
	List* head = (List*)malloc(sizeof(List));
	List* end = head;
	head->val = rand()%100;
	for (int i = 1; i < MAX; ++i) {//构造一个长度为1000的单向链表
		end = addlist(end, rand()%100);
	}
	for (int i = 0; i < MAX; ++i) {//遍历输出各节点的值
		List* p = getptr(head, i);
		printf("%d\n", p->val);
	}
	for (int i = MAX - 1; i >= 1; --i) {//链表反向
		getptr(head, i)->next = getptr(head, i - 1);
	}
	List* temp = head;
	head = end;
	end = temp;
	end->next = NULL;
	int n = findval(head, 5);
	printf("%d\n", n);
	n = (n != 1) ? findval(getptr(head, n), 5) + n : -1;
	printf("%d\n", n);
	return 0;
}