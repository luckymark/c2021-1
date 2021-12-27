#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;
 int i = 0,mid=1;
 //创建链表
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
//遍历链表
void travelLink(Node* head) {
    Node* p = head->next;
    while (p != NULL) {
        printf("%d\t", p->data);
        p = p->next;
    }
    putchar('\n');
}
//翻转链表
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
//在该链表中查找第一个值为 5 的节点，如果找到则返回该节点的序号，否则返回－1
int findfirst5(Node* head) {
    Node* p = head;
    while (p->next != NULL) {
        if (p->data == 5) return i;
        p = p->next;
        i++;
    }
    return -1;
}
//查找下一个值为 5 的节点，返回值同上
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
    createLink(head, 10);//创建链表
    travelLink(head);//遍历链表
    reverseLink(head);//翻转链表元素
    travelLink(head);//遍历链表
    r = findfirst5(head);//在该链表中查找第一个值为 5 的节点，如果找到则返回该节点的序号，否则返回－1
    printf("第1个5在第%1d位\n", r);
    s = findother5(head);//查找下一个值为 5 的节点，返回值同上
    printf("第%d个5在第%1d位\n",mid,s);
    return 0;
}

