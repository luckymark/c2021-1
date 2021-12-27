#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;
 int i = 0,mid=1;
 //��������
void createLink(Node* head, int size) {
    Node* rear = head;
    int i;
    for (i = 0; i < size; ++i) {
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->next = NULL;
        scanf_s("%d", &newnode->data);
        rear->next = newnode;
        rear = newnode;
    }
}
//��������
void travelLink(Node* head) {
    Node* p = head->next;
    while (p != NULL) {
        printf("%d\t", p->data);
        p = p->next;
    }
    putchar('\n');
}
//��ת����
void reverseLink(Node* head) {
    Node* curr;
    Node* pre = NULL;
    while (head->next != NULL) {
        curr = head->next;
        head->next = curr->next;
        curr->next = pre;
        pre = curr;
    }
    head->next = pre;
}
//�ڸ������в��ҵ�һ��ֵΪ 5 �Ľڵ㣬����ҵ��򷵻ظýڵ����ţ����򷵻أ�1
int findfirst5(Node* head) {
    Node* p = head;
    while (p->next != NULL) {
        if (p->data == 5) return i;
        p = p->next;
        i++;
    }
    return -1;
}
//������һ��ֵΪ 5 �Ľڵ㣬����ֵͬ��
int findother5(Node* head) {
    int m;
    m = mid;
    Node* p = head;
    while (p->next != NULL) {
        if (p->data == 5) {
            if (m == 0) {
                mid++;
                return i-1;
            }
            else if (m != 0)m--;
        }
        p = p->next;
        i++;
    }
    return -1;
}
int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    int r,s;
    createLink(head, 10);//��������
    travelLink(head);//��������
    reverseLink(head);//��ת����Ԫ��
    travelLink(head);//��������
    r = findfirst5(head);//�ڸ������в��ҵ�һ��ֵΪ 5 �Ľڵ㣬����ҵ��򷵻ظýڵ����ţ����򷵻أ�1
    printf("��1��5�ڵ�%1dλ\n", r);
    s = findother5(head);//������һ��ֵΪ 5 �Ľڵ㣬����ֵͬ��
    printf("��%d��5�ڵ�%1dλ\n",mid,s);
    return 0;
}

