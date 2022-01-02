#include <stdio.h>
#include <malloc.h>
struct NODE {
	int data;
	struct NODE* next;
};
struct NODE* creatlist() {
	struct NODE* head = (struct NODE*)malloc(sizeof(struct NODE));
	head->next = NULL;
	return head;
}
struct NODE* createNode(int data) {
	struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void printlist(struct NODE* headlist) {
	struct NODE* pMove = headlist->next;
	while (pMove) {
		printf("%d\n", pMove->data);
		pMove = pMove->next;
		/*printf("\n");*/	
	}
}
void printlistNoHead(struct NODE* headlist) {
	struct NODE* pMove = headlist;
	while (pMove) {
		printf("%d\n", pMove->data);
		pMove = pMove->next;
		/*printf("\n");*/
	}
}
void insertNodeByHead(struct NODE* headNode,int data) {
	struct NODE* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
int iteration(NODE* head,int count) {
	int time = 0;
    int Time = -1;
    int COUNT = 1;
    if (head == NULL || head->next == NULL) {
        return -1;
    }
    else {
        NODE* beg = NULL;
        NODE* mid = head;
        NODE* end = head->next;
        //һֱ����
        while (1)
		{
			time++;
            //�޸� mid ��ָ�ڵ��ָ��
            mid->next = beg;
            if (mid->data == 5 && COUNT == count) {
                Time = time;
            }
            else if (mid->data == 5) {
                COUNT++;
            }
            //��ʱ�ж� end �Ƿ�Ϊ NULL������������˳�ѭ��
            if (end == NULL) {
                break;
            }

            //��������ƶ� 3 ��ָ��
            beg = mid;
            mid = end;
            end = end->next;

        }
        return Time;
    }
}
struct NODE* iteration_reverse(NODE* head) {
    int time = 0;
    if (head == NULL || head->next == NULL) {
        return head;
    }
    else {
        NODE* beg = NULL;
        NODE* mid = head;
        NODE* end = head->next;
        while (1)
        {
            time++;
            mid->next = beg;
            if (end == NULL) {

                break;
            }
            if (mid->data == 5) {
                printf("5�ڵ�%d��\n", time);
            }
            beg = mid;
            mid = end;
            end = end->next;

        }
        head = mid;
        return head;
    }
}
int main() {
	struct NODE* list = creatlist();
	insertNodeByHead(list, 3);
	insertNodeByHead(list, 5);
	insertNodeByHead(list, 1);
    insertNodeByHead(list, 5);
	printlist(list);
    struct NODE* reverse = iteration_reverse(list->next);/*���ɷ�������*/
    printlistNoHead(reverse);
    int a = iteration(reverse,2);
    printf("%d��ζ����Ҫ��ĵ�5�ڵ�%d��", a,a);
	return 0;
}